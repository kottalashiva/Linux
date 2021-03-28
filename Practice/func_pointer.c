#include<stdio.h>


float* func(void*, void*);
int main()
{
	float a, b ;
	float *s;
	float *(*p)(void*, void*);
	a = 10.5;
	b = 12.5;
	p = &func;
	s=p(&a, &b);
	printf("%f", *s);
	return 1;
}

float* func(void* a, void* b)
{
	float c;
	float d;
	float e;
	c = *(float*)a;
	d = *(float*)b;
	e = c+d;
	printf("%f ", e);
	return &e;
}