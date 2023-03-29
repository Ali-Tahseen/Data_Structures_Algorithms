#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
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
// As it is modifying the array so it should be a call by address type and x is the value we want to insert
void Append(struct array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct array *arr,int index, int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
       for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
       arr->A[index]=x;
       arr->length++;
    }
}

int main()
{
    struct array arr={{2,3,4,5,6},10,5};

    //Append(&arr,10);
    Insert(&arr,2,10);
    Display(arr);

    return 0;
}
