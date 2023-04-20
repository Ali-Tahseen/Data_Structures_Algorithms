#include <iostream> //Header file for input-output

using namespace std;

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

int Max(int A[], int n) { //Function to find maximum element
  int max = -32768;
  for (int i = 0; i < n; i++) { //Traversing the array
    if (A[i] > max) { //Updating maximum
      max = A[i];
    }
  }
  return max;
}

void CountSort(int A[], int n) { //Counting sort function
  int max = Max(A, n); //Finding maximum element
  // Create count array
  int * count = new int[max + 1];

  // Initialize count array with 0
  for (int i = 0; i < max + 1; i++) { //Initializing count array
    count[i] = 0;
  }

  // Update count array values based on A values
  for (int i = 0; i < n; i++) { //Incrementing count of each element
    count[A[i]]++;
  }

  // Update A with sorted elements
  int i = 0;
  int j = 0;
  while (j < max + 1) { //Traversing count array
    if (count[j] > 0) { //If count is greater than 0
      A[i++] = j; //Copying element
      count[j]--; //Decrementing count
    } else { //If count becomes 0
      j++;
    }
  }

  // Delete heap memory
  delete[] count;
}
int main() {
  int A[] = {2,5,8,12,3,6,7,10}; //Input array
  int n = sizeof(A) / sizeof(A[0]); //Size of array

  Print(A, n, "\t\tA"); //Printing array
  CountSort(A, n); //Calling count sort
  Print(A, n, " Sorted A"); //Printing sorted array

  return 0;
}

