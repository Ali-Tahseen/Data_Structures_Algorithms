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

void IterativeMergeSort(int A[], int n) { //Function for merge sort
  int p;
  for (p = 2; p <= n; p = p * 2) { //Determining subarrays of size p
    for (int i = 0; i + p - 1 < n; i = i + p) { //Traversing through array with jump of size p
      int low = i; //Determining left and right limits of subarray
      int high = i + p - 1;
      int mid = (low + high) / 2;
      Merge(A, low, mid, high); //Calling merge() on subarrays
    }
  }
  if (p / 2 < n) { //If size of left subarray is greater than p/2
    Merge(A, 0, p / 2 - 1, n - 1); //Merge left and right subarrays
  }
}

int main() {
  int A[] = {2,5,8,12,3,6,7,10}; //Input array
  int n = sizeof(A) / sizeof(A[0]); //Size of array

  Print(A, n, "\t\tA"); //Printing array
  IterativeMergeSort(A, n); //Calling merge sort
  Print(A, n, " Sorted A"); //Printing sorted array

  return 0;
}
