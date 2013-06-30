function add(a,b){
return a+b;
}
function sum(a){
return add(a.a,a.b);
}
var a=new Object();
a.a=1;
a.b=2;
a.c=sum;
document.write(a.c(a));
document.write("<br/>");
for(var i=0;i<3;i++){
document.write("forloop ");
document.write(i);
document.write("th iter!<br/>");
};
while(a.b>0){
document.write("whileloop ");
document.write(a.b);
document.write("<br/>");
a.b--;
};
if(a.a>a.b){
document.write("If<br/>");
};
if(a.a<a.b){
document.write("Wrong<br/>");
}
else{
document.write("Else<br/>");
};

