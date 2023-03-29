#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[20];
    int size;
    int length;
};

void Display(struct array arr)
{
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
}
int main()
{
    struct array arr={{2,3,4,5,6},20,5};


    Display(arr);

    return 0;
}
