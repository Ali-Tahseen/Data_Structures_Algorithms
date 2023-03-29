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

void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size) // Check if there is any free space in the array or not
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
        // going from highest to smallest number in a sorted list while the condition holds,
    }
    arr->A[i+1]=x;
    //since A[i] is smaller then x so x is copied to A[i+1]
    arr->length++;
    //length of an array is incremented because a new element is added
}

//check to see if an array is sorted
int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

//Rearranging any array and dividing the positive and negative numbers in right and left side accordingly.
void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr={{2,-3,10,25,-6,5},10,6};

    //InsertSort(&arr,1);
    //printf("%d\n", isSorted(arr));
    Rearrange(&arr);
    Display(arr);

    return 0;
}
