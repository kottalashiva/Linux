#include<stdio.h>
#include<stdlib.h>

void *xmalloc(int size)
{
	void *p = sbrk(0);
	if(sbrk(size) == NULL)
	{
		return NULL;
	}
	return p;
}

void free(int bytes)
{
	sbrk(bytes * -1);
}
int main()
{
	char *p = (char*) xmalloc(10);
	strncpy(p, "Shiva", 5);
	printf("%s\n", p);
	
	return 0;
}