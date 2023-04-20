// Bubble Sort
#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;  // Store the value of *x in a temporary variable
    *x=*y;        // Assign the value of *y to *x
    *y=temp;      // Assign the value of temp to *y
}

void Bubble(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)  // Loop through each element in the array
    {
        flag=0;
        for(j=0;j<n-i-1;j++)  // Loop through each element in the unsorted part of the array
        {
            if(A[j]>A[j+1])  // If the current element is greater than the next element
            {
                swap(&A[j],&A[j+1]);  // Swap the current element with the next element
                flag=1;  // Set the flag to indicate that a swap has occurred
            }
        }
        if(flag==0)  // If no swaps occurred in the inner loop, the array is already sorted, so break out of the outer loop
            break;
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    Bubble(A,n);  // Sort the array using Bubble Sort
    for(i=0;i<10;i++)
        printf("%d ",A[i]);  // Print the sorted array
    printf("\n");
    return 0;
}
