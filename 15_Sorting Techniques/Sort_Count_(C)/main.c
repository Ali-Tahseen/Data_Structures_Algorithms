//Count Sort
#include <stdio.h> //Header file for input-output

#include<stdlib.h> //Header file for various functions

void swap(int * x, int * y) //Function to swap two numbers
{
  int temp = * x; //Storing value of x in temp
  * x = * y; //Assigning value of y to x
  * y = temp; //Assigning temp to y
}

int findMax(int A[], int n) //Function to find maximum element
{
  int max = INT_MIN; //Initializing max (corrected from INT32_MIN)
  int i;
  for (i = 0; i < n; i++) // traversing the array
  {
    if (A[i] > max) //updating max
      max = A[i];
  }
  return max;
}

void CountSort(int A[], int n) //Counting sort function
{
  int i, j, max, * C; //Initializing variables
  max = findMax(A, n); //Finding max element
  C = (int *) malloc(sizeof(int)*(max + 1)); //Allocating memory

  for (i = 0; i < max + 1; i++) //Initializing count array
  {
    C[i] = 0;
  }

  for (i = 0; i < n; i++) //Incrementing count of each element
  {
    C[A[i]]++;
  }

  i = 0;
  j = 0; //Initializing pointers
  while (j < max + 1) //Corrected ') before (' token
  {
    if (C[j] > 0) //Corrected count
    {
      A[i++] = j; //Copying element (corrected ') before (' token)
      C[j]--; //Decrementing count
    }else //Corrected main braces
    j++;
  }
}


int main() { //Corrected main braces
  int A[] = {11,13,7,12,16,9,24,5,10,3}, n = 10, i; //Input array
  CountSort(A, n); //Calling count sort
  for (i = 0; i < 10; i++) //Printing sorted array
    printf("%d ", A[i]);
  printf("\n");
  return 0;
}
