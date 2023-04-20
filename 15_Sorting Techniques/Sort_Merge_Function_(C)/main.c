#include <stdio.h>
#include <stdlib.h>

// Merge two sorted subarrays A[l..mid] and A[mid+1..h]



void Merge(int A[], int l, int mid, int h){
    int i = l;  // Initialize i to the start of the first subarray
    int j = mid+1;  // Initialize j to the start of the second subarray
    int k = l;  // Initialize k to l, which is the start of the merged subarray
    int B[100];  // Create a temporary array to store the merged subarray

    // Merge the elements from the two subarrays in ascending order
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];  // Copy the ith element of the first subarray to B and increment i and k
        } else {
            B[k++] = A[j++];  // Copy the jth element of the second subarray to B and increment j and k
        }
    }

    // Copy the remaining elements from the first subarray, if any
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }

    // Copy the remaining elements from the second subarray, if any
    for (; j <= h; j++) {
        B[k++] = A[j];
    }

    // Copy the merged subarray from B back to A
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

// Recursively divide the array into two halves and sort them
void MergeSort(int A[], int l, int h){
    int mid;
    if (l < h) {  // If there are two or more elements in the array
        mid = (l+h)/2;  // Find the middle index
        MergeSort(A, l, mid);  // Sort the first half recursively
        MergeSort(A, mid+1, h);  // Sort the second half recursively
        Merge(A, l, mid, h);  // Merge the two sorted halves
    }
}

// Driver code to test the MergeSort function
int main(){
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};  // Define an array of integers to be sorted
    int n = 10, i;

    MergeSort(A, 0, n-1);  // Sort the array using MergeSort

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
