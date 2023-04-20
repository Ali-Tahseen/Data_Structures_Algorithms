// Quick Sort
#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;  // Store the value of *x in a temporary variable
    *x=*y;        // Assign the value of *y to *x
    *y=temp;      // Assign the value of temp to *y
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];  // Choose the pivot element
    int i=l,j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);  // Move i to the right until A[i] is greater than the pivot
        do{j--;}while(A[j]>pivot);   // Move j to the left until A[j] is less than or equal to the pivot
        if(i<j)swap(&A[i],&A[j]);   // Swap A[i] and A[j] if i is less than j
    }while(i<j);
    swap(&A[l],&A[j]);  // Swap the pivot element with A[j]
    return j;  // Return the index of the pivot element
}

void QuickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);  // Partition the array using the pivot element
        QuickSort(A,l,j);    // Sort the left subarray recursively
        QuickSort(A,j+1,h);  // Sort the right subarray recursively
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    QuickSort(A,n);  // Sort the array using Quick Sort
    for(i=0;i<10;i++)
        printf("%d ",A[i]);  // Print the sorted array
    printf("\n");
    return 0;
}
