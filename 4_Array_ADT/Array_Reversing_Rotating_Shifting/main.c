#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
}

// swap two elements in an array
void swap(int *x, int *y){
    int temp;
    temp=*x;// temp = value from x
    *x=*y; // value of x modified by value of y
    *y=temp;// and value of y will change to value of temp
}


// Reversing an array with another array. Note: This method takes longer so not preferrable
void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

//Reversing an array by swapping first index with last and so on. Note: This method takes less time to swap and reverse the array
void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    Reverse2(&arr);
    Display(arr);

    return 0;
}
