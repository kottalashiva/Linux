#include<stdio.h>

static int myFun(int a, int b)
{
	return a+b;
}

static int add(int a, int b) __attribute__((alias("myFun")));

int main()
{
	printf("%d\n", myFun(10,20));
	printf("%d\n", add(20, 30));
	return 0;
}

