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

// swap two elements in an array
void swap(int *x, int *y){
    int temp;
    temp=*x;// temp = value from x
    *x=*y; // value of x modified by value of y
    *y=temp;// and value of y will change to value of temp
}

// for call by address use -> and for call by value use dot
// here we pass by value because it has to only search by value
//int LinearSearch(struct array arr,int key){
//    int i;
//    for(i=0;i<arr.length;i++)
//    {
//        if(key==arr.A[i])
//            return i;
//    }
//    return -1;
//}


// here we have to pass by address
int LinearSearch(struct array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i]){
            //transposition swap
            //swap(&arr->A[i],&arr->A[i-1]);
            // move to head
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }

    }
    return -1;
}

int main()
{
    struct array arr={{2,3,4,5,6},10,5};

    //Append(&arr,10);
    //Insert(&arr,2,10);
    printf("%d\n",LinearSearch(&arr,5));
    Display(arr);

    return 0;
}
