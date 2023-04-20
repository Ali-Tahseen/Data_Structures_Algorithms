#include<stdio.h> //Header file for input-output

#include<stdlib.h> //Header file for various functions


void merge(int A[], int l, int mid, int h) //Function to merge two subarrays
{
  int i = l, j = mid + 1, k = l; //Initializing pointers i, j and index k
  int B[100]; //Temporary array

  while (i <= mid && j <= h) {
    if (A[i] < A[j]) //If A[i] is smaller, move it to temp array
      B[k++] = A[i++];
    else //Otherwise move A[j] to temp array
      B[k++] = A[j++];
  }

  for (; i <= mid; i++) //Copying rest elements of left half
    B[k++] = A[i];
  for (; j <= h; j++) //Copying rest elements of right half
    B[k++] = A[j];

  for (i = l; i <= h; i++) //Copying elements from temp array to main array
    A[i] = B[i];
}

void IMergeSort(int A[], int n) //Function for merge sort
{
  int p, l, h, mid, i;

  for (p = 2; p <= n; p = p * 2) //Finding positions of left and right subarrays
  {
    for (i = 0; i + p - 1 < n; i = i + p) {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2; //Finding middle of two subarrays
      merge(A, l, mid, h);
    }

    if (n - i > p / 2) //If size of right subarray is greater than p/2
    {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2; //Find middle of two subarrays
      merge(A, l, mid, n - 1);
    }
  }

  if (p / 2 < n) //If size of left subarray is greater than p/2
    // this is used incase there are some elements left for merging
  {
    merge(A, 0, p / 2 - 1, n - 1);
  }
}

int main() {
  int A[] = {11,5,14,2,6,3,1}, n = 7, i;

  IMergeSort(A, n); //Calling merge sort funtion

  for (i = 0; i < n; i++) //Printing sorted array
    printf("%d ", A[i]);
  printf("\n");
  return 0;
}
