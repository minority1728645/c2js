from pycparser import c_parser, c_ast
import sys
import re
import StringIO


def parse(node):
    typ = type(node)
    if typ == c_ast.ArrayRef:
        parse(node.name)
        output.write('[')
        parse(node.subscript)
        output.write('] ')

    elif typ == c_ast.ID:
        output.write(node.name)

    elif typ == c_ast.Constant:
        output.write(node.value)

    elif typ == c_ast.Return:
        output.write('return ')
        parse(node.expr)

    elif typ == c_ast.IdentifierType:
        for name in node.names:
            output.write(name + ',')
        output.seek(-1, 1)

    elif typ == c_ast.Decl:
        if type(node.type) == c_ast.TypeDecl and type(node.type.type) == c_ast.IdentifierType and node.type.type.names[0] in ['int', 'float', 'double', 'char']:
            if node.init == None:
                output.write('var ' + node.name)
            else:
                output.write('var ' + node.name + '=')
                parse(node.init)
        elif type(node.type) == c_ast.TypeDecl and type(node.type.type) == c_ast.IdentifierType and node.type.type.names[0] in ['Array', 'Boolean']:
            if node.init == None:
                output.write('var ' + node.name)
            else:
                output.write(
                    'var ' + node.name + '=new ' + node.type.type.names[0] + '(')
                parse(node.init)
                output.write(')')
        elif type(node.type) == c_ast.TypeDecl and type(node.type.type) == c_ast.IdentifierType:
            output.write('var ' + node.name + '=new Object()')
        else:
            parse(node.type)

    elif typ == c_ast.TypeDecl:
        parse(node.type)
        output.write(node.declname)

    elif typ == c_ast.FuncCall:
        parse(node.name)
        output.write('(')
        parse(node.args)
        output.write(')')

    elif typ == c_ast.ExprList:
        for expr in node.exprs:
            parse(expr)
            output.write(',')
        output.seek(-1, 1)

    elif typ == c_ast.StructRef:
        parse(node.name)
        output.write('.')
        parse(node.field)

    elif typ == c_ast.InitList:
        for expr in node.exprs:
            parse(expr)
            output.write(',')
        output.seek(-1, 1)

    elif typ == c_ast.For:
        output.write('for(')
        parse(node.init)
        output.write(';')
        parse(node.cond)
        output.write(';')
        parse(node.next)
        output.write('){\n')
        parse(node.stmt)
        output.write('}')

    elif typ == c_ast.DeclList:
        for decl in node.decls:
            parse(decl)
            output.write(',')
        output.seek(-1, 1)

    elif typ == c_ast.BinaryOp:
        parse(node.left)
        output.write(node.op)
        parse(node.right)

    elif typ == c_ast.UnaryOp:
        if node.op[0] == 'p':
            parse(node.expr)
            output.write(node.op[1:])
        else:
            output.write(node.op)
            parse(node.expr)

    elif typ == c_ast.Compound:
        for block_item in node.block_items:
            parse(block_item)
            output.write(';\n')

    elif typ == c_ast.Assignment:
        parse(node.lvalue)
        output.write(node.op)
        parse(node.rvalue)

    elif typ == c_ast.If:
        output.write('if(')
        parse(node.cond)
        output.write('){\n')
        parse(node.iftrue)
        output.write('}')
        if node.iffalse != None:
            output.write('\nelse{\n')
            parse(node.iffalse)
            output.write('}')

    elif typ == c_ast.While:
        output.write('while(')
        parse(node.cond)
        output.write('){\n')
        parse(node.stmt)
        output.write('}')

    elif typ == c_ast.Switch:
        output.write('switch(')
        parse(node.cond)
        output.write('){\n')
        parse(node.stmt)
        output.write('}')

    elif typ == c_ast.Case:
        output.write('case ')
        parse(node.expr)
        output.write(':\n')
        for stmt in node.stmts:
            parse(stmt)
            output.write(';\n')
        output.seek(-2, 1)

    elif typ == c_ast.Break:
        output.write('break')

    elif typ == c_ast.Default:
        output.write('default:\n')
        for stmt in node.stmts:
            parse(stmt)
            output.write(';\n')
        output.seek(-2, 1)

    elif typ == c_ast.DoWhile:
        output.write('do{\n')
        parse(node.stmt)
        output.write('}while(')
        parse(node.cond)
        output.write(')')

    elif typ == c_ast.Continue:
        output.write('continue')

    elif typ == c_ast.TernaryOp:
        parse(node.cond)
        output.write('?')
        parse(node.iftrue)
        output.write(':')
        parse(node.iffalse)

    elif typ == c_ast.FuncDef:
        output.write('function ' + node.decl.name + '(')
        for param in node.decl.type.args.params:
            output.write(param.name + ',')
        output.seek(-1, 1)
        output.write('){\n')
        parse(node.body)
        output.write('}\n')

if __name__ == '__main__':

    text = ''
    for line in open('js.h', 'r').readlines()[:-5]:
        text += line

    regex_inc = re.compile(r'^\s*\#include\s*\"(.*?)\"')
    regex_com = re.compile(r'#.*?$|\/\*.*?\*\/|\/\/.*?$', re.M | re.S)

    for line in open(sys.argv[1], 'r').readlines():
        match = regex_inc.search(line)
        if match:
            filename = match.group(1)
            if filename != 'js.h':
                text += open(line[10:line.rfind('"')], 'r').read()
        else:
            text += line

    text = regex_com.sub('', text)

    output = StringIO.StringIO()

    parser = c_parser.CParser()
    ast = parser.parse(text)

    for ext in ast.ext:
        if type(ext) == c_ast.FuncDef and ext.decl.name == 'main':
            main = ext
        else:
            parse(ext)

    for block in main.body.block_items:
        if type(block) != c_ast.Return:
            parse(block)
            output.write(';\n')

    print output.getvalue()
