#include <stdio.h> //Header file for input-output

#include<stdlib.h> //Header file for various functions

void swap(int * x, int * y) //Function to swap two numbers
{
  int temp = * x; //Storing value of x in temp
  * x = * y; //Assigning value of y to x
  * y = temp; //Assigning temp to y
}

void Merge(int A[], int l, int mid, int h) //Function to merge left and right halves
{
    int i = l, j = mid + 1, k = l; //Initializing pointers i, j and k
    int B[100]; //Temporary array

    while (i <= mid && j <= h) //Comparing elements of left and right halves
    {
      if (A[i] < A[j]) //If element of left half is smaller, move it to temp array
        B[k++] = A[i++];
      else //If element of right half is smaller, move it to temp array
        B[k++] = A[j++];
    }

    for (; i <= mid; i++) //Copying remaining elements of left half
      B[k++] = A[i];
    for (; j <= h; j++) //Copying remaining elements of right half
      B[k++] = A[j];

    for (i = l; i <= h; i++) //Copying temp array to main array
      A[i] = B[i];
}

void MergeSort(int A[], int l, int h) //Recursive function to sort the subarray
{
    int mid;
    if (l < h) //If subarray is not sorted
    {
      mid = (l + h) / 2; //Finding middle point
      MergeSort(A, l, mid); //Sorting left half
      MergeSort(A, mid + 1, h); //Sorting right half
      Merge(A, l, mid, h); //Merging two halves
    }
}

int main() {
        int A[] = {11,13,7,12,16,9,24,5,10,3}, n = 10, i; //Input array
        MergeSort(A, 0, n - 1); //Calling merge sort
        for (i = 0; i < 10; i++) //Printing sorted array
          printf("%d ", A[i]);
        printf("\n");
        return 0;
}
