#include<stdio.h>
int main(){
    short int a=5;
    int b=5;
    long int c=5l;
    float d=5.0f;
    double e=5.0;
    long double f=5.0L;
    char g='5';
    printf("Size of short int: %d\n",sizeof(a));
    printf("Size of int: %d\n",sizeof(b));
    printf("Size of long int: %d\n",sizeof(c));
    printf("Size of float: %d\n",sizeof(d));
    printf("Size of double: %d\n",sizeof(e));
    printf("Size of long double: %d\n",sizeof(f));
    printf("Size of char: %d\n",sizeof(g));
        return 0;
}