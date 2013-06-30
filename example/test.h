
int add(int a,int b)
{
	return a+b;
}

typedef struct _A{
	int a;
	int b;
	int (*c);
} A;

int sum(A a)
{
	return add(a.a,a.b);
}
