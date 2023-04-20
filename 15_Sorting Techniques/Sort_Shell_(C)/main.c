// Shell Sort implementation in C
#include <stdio.h>
#include<stdlib.h>

// Function to swap two integers
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform Shell Sort
void ShellSort(int A[], int n)
{
    int gap, i, j, temp;

    // Start with a large gap and reduce by half in each iteration
    for (gap = n/2; gap >= 1; gap /= 2)
    {
        // Perform Insertion Sort on subarrays separated by gap
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

// Driver function
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10, i;

    // Sort the array using Shell Sort
    ShellSort(A, n);

    // Print the sorted array
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
