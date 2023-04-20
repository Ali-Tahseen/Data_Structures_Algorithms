// Selection Sort
#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;  // Store the value of *x in a temporary variable
    *x=*y;        // Assign the value of *y to *x
    *y=temp;      // Assign the value of temp to *y
}

void SelectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)  // Loop through each element in the array
    {
        for(j=k=i;j<n;j++)  // Find the minimum element in the unsorted part of the array
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i],&A[k]);  // Swap the minimum element with the first element in the unsorted part of the array
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    SelectionSort(A,n);  // Sort the array using Selection Sort
    for(i=0;i<10;i++)
        printf("%d ",A[i]);  // Print the sorted array
    printf("\n");
    return 0;
}
