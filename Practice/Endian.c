#include<stdio.h>


int main()
{
	unsigned int a=300;
	char *ist_byte = (char*)&a;
	printf("%u", *(char*)&a);
	printf("%d",*++ist_byte);
	if(ist_byte == 3)
		printf("Big endian");
	else
		printf("Little endian");
}