#include<stdio.h>

int main()
{
	unsigned int a=2;
	char *s = (char*)&a;
	if(s==)
		printf(" Little Endian");
	else
		printf("Big Endian");
	return 1;
}
