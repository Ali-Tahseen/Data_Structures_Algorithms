#include <stdio.h>
#include <stdlib.h>

int main()
{
    //static array
    int A[5]={2,4,6,8,10}; //Array created in stack
    int *p; // Pointer

    // Dynamic array
    //Creating array in heap using pointer
    p=(int *)malloc(5*sizeof(int));
    p[0]=3;//adding 3 to to index 0 using pointer P
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;
    p[5]=13;

    for(int i=0; i<5;i++)
        printf("%d", A[i]);
    printf("\n");
    for(int i=0; i<6;i++)
        printf("%d", p[i]);
    return 0;
}
