#include <iostream> //Header file for input-output

using namespace std; //Using standard namespace

template < class T >
  void Print(T & vec, int n, string s) { //Template function to print the vector
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) { //Traversing the vector
      cout << vec[i] << flush;
      if (i < n - 1) { //Checking if we have reached the end of vector
        cout << ", " << flush;
      }
    }
    cout << "]" << endl;
  }

void Merge(int A[], int low, int mid, int high) { //Function to merge two halves
  int i = low; //Initializing pointers
  int j = mid + 1;
  int k = low;
  int B[high + 1]; //Temporary array
  while (i <= mid && j <= high) { //Comparing elements of two halves
    if (A[i] < A[j]) { //If element of left half is smaller, move it to temp array
      B[k++] = A[i++];
    } else { //If element of right half is smaller, move it to temp array
      B[k++] = A[j++];
    }
  }
  while (i <= mid) { //Copying remaining elements of left half
    B[k++] = A[i++];
  }
  while (j <= high) { //Copying remaining elements of right half
    B[k++] = A[j++];
  }
  for (int i = low; i <= high; i++) { //Copying temp array to main array
    A[i] = B[i];
  }
}

void RecursiveMergeSort(int A[], int low, int high) { //Recursive merge sort function
  if (low < high) { //If subarray is not sorted
    // Calculate mid point
    int mid = low + (high - low) / 2;
    // Sort sub-lists
    RecursiveMergeSort(A, low, mid); //Sort left half
    RecursiveMergeSort(A, mid + 1, high); //Sort right half

    // Merge sorted sub-lists
    Merge(A, low, mid, high); //Merge left and right halves
  }

}

int main() {
  int A[] = {2,5,8,12,3,6,7,10}; //Input array
  int n = sizeof(A) / sizeof(A[0]); //Size of array

  Print(A, n, "\t\tA"); //Printing array
  RecursiveMergeSort(A, 0, n - 1); //Calling merge sort
  Print(A, n, " Sorted A"); //Printing sorted array

  return 0;

}
