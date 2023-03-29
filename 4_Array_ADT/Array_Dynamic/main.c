#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *A;
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
    struct array arr;
    int n,i;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    // This type of array will be created in heap and this type of array creation is more preferrable because array is created at runtime


    printf("Enter number of numbers");
    scanf("%d", &n);

    //For loop to insert n elements
    printf("Enter all Elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr.A[i]);
    arr.length=n;

    Display(arr);

    return 0;
}
