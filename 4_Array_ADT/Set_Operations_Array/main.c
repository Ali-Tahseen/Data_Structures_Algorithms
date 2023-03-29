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
        printf("%d\n", arr.A[i]);
}

// swap two elements in an array
void swap(int *x, int *y){
    int temp;
    temp=*x;// temp = value from x
    *x=*y; // value of x modified by value of y
    *y=temp;// and value of y will change to value of temp
}

// function for sorting any arrays
void SortedNum(struct Array *arr){
    int n=arr->length;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) { if(arr->A[i]>arr->A[j])
            {
                swap(&arr->A[i],&arr->A[j]);
            }
        }
    }
}


// Union function to find common numbers once and all the other unique numbers but on a sorted list it's comparing
// If an index num of one arr is less than other the increment the index and see the next element whether it is equal or not
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }
    //if the size of arr1 is larger or smaller than arr2 then the remaining elements from arr1 or arr2 can be copied by using the
    //following for loop
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}


// Function to find the difference in between two arrays
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }

    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];


    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

// Functions to find all the common elements only
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else // only if the arrs are equal then copy them
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}


int main()
{
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3;

    //InsertSort(&arr,1);
    //printf("%d\n", isSorted(arr));
    //SortedNum(&arr);
    arr3=Intersection(&arr1,&arr2);
    Display(*arr3);
    // if the function takes in pointers as parameters when we have to pass address of variable using & sign
    // if the function takes in value as parameters then we pass the pointer

    return 0;
}
