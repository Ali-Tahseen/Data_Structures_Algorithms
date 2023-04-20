// Insertion Sort
#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;  // Store the value of *x in a temporary variable
    *x=*y;        // Assign the value of *y to *x
    *y=temp;      // Assign the value of temp to *y
}

void Insertion(int A[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)  // Loop through each element in the array
    {
        j=i-1;
        x=A[i];  // Store the current element in x
        while(j>-1 && A[j]>x)  // Loop through each element in the sorted part of the array
        {
            A[j+1]=A[j];  // Move the current element to the right
            j--;
        }
        A[j+1]=x;  // Insert the current element in its correct position
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    Insertion(A,n);  // Sort the array using Insertion Sort
    for(i=0;i<10;i++)
        printf("%d ",A[i]);  // Print the sorted array
    printf("\n");
    return 0;
}
