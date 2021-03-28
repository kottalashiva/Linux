
#include<stdio.h>
#include<errno.h>
#include<string.h>

void* xmalloc(int bytes)
{
	void *p;
	p=sbrk(0);
	if(sbrk(2) == NULL)
	{
		perror("sbrk");
	}
	else{
		return p;
	}
}

void xfree(int bytes)
{
	sbrk(bytes*-1);
}
int main()
{
	char *p=(char *)xmalloc(10);
//	int s;
	strncpy(p, "shiva kumadsadsadasdsadasdsadsadasdadsadadsds", strlen("shiva kumadsadsadasdsadasdsadsadasdadsadadsds"));
	printf("%s", p);
//	s = malloc_usable_size(p);
	//printf("%d", malloc_usable_size(p));
	xfree(10);
	return 1;
}
