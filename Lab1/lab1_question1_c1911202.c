#include <stdio.h>
#include <stdlib.h>

void changevalues(int *, int *);
void changeaddress(int *, int *);

void changevalues(int *pa, int *pb)
{

    printf("a= %d\nb= %d\n------------Swap1------------\n", *pa, *pb);
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("a= %d\nb= %d\npa address= %p\npb address= %p", *pa, *pb, pa, pb);
}
void changeaddress(int *pa, int *pb)
{
    int temp;
    temp = pa;
    pa = pb;
    pb = temp;
    printf("\n------------Swap2------------\npa address= %p\npb address= %p", pa, pb);
}

int main(int argc, char const *argv[])
{
    int a = 42;
    int b = 17;

    changevalues(&a, &b);
    changeaddress(&a, &b);

    return 0;
}
