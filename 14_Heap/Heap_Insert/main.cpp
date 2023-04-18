#include <iostream>   // Include necessary header files
#include <vector>

using namespace std;   // Use the standard namespace

// Lecture based
void InsertA(int A[], int n){   // Define function that inserts into an array-based max heap
    int i = n;   // Set the index to the last element in the heap
    int temp = A[n];   // Store the new element to be inserted in a temporary variable
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){   // While the new element is greater than its parent and not at the root
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];   // Swap the new element with its parent
        i = i % 2 == 0 ? (i/2)-1 : i/2;   // Move up to the parent index
    }
    A[i] = temp;   // Insert the new element in its correct position
}


// STL vector based
void Insert(vector<int>& vec, int key){   // Define function that inserts into a vector-based max heap
    // Insert key at the end
    auto i = vec.size();   // Set the index to the last element in the heap
    vec.emplace_back(key);   // Add the new element to the end of the vector

    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){   // While the new element is greater than its parent and not at the root
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];   // Swap the new element with its parent
        i = i % 2 == 0 ? (i/2)-1 : i/2;   // Move up to the parent index
    }
    vec[i] = key;   // Insert the new element in its correct position
}

template <class T>
void Print(T& vec, int n){   // Define a function that prints the heap
    cout << "Max Heap: [" << flush;   // Print the opening bracket of the heap
    for (int i=0; i<n; i++){   // Loop over all elements in the heap
        cout << vec[i] << flush;   // Print the current element
        if (i < n-1){   // If the current element is not the last element in the heap
            cout << ", " << flush;   // Print a comma and a space
        }
    }
    cout << "]" << endl;   // Print the closing bracket of the heap and a newline character
}


int main() {   // Define the main function

    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};   // Define an array-based max heap
    InsertA(a, 9);   // Insert a new element into the heap
    Print(a, sizeof(a)/sizeof(a[0]));   // Print the heap

    cout << endl;   // Print a newline character

    // STL based
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};   // Define a vector-based max heap
    Print(v, v.size());   // Print the heap
    v.reserve(15);  // Reserve space for 15 elements
    Insert(v, 50);   // Insert a new element into the heap
    Print(v, v.size());   // Print the heap

    return 0;   // Return 0 to indicate successful execution of the program
}
