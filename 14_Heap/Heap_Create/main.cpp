#include <iostream>   // Include necessary header files
#include <vector>

using namespace std;   // Use the standard namespace

void Insert(vector<int>& vec, int key){   // Define function that inserts into a vector-based max heap
    // Insert key at the end
    auto i = vec.size();   // Set the index to the last element in the heap
    vec.emplace_back(key);   // Add the new element to the end of the vector

    // Rearrange elements: O(log n)
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){   // While the new element is greater than its parent and not at the root
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];   // Swap the new element with its parent
        i = i % 2 == 0 ? (i/2)-1 : i/2;   // Move up to the parent index
    }
    vec[i] = key;   // Insert the new element in its correct position
}

void InsertInplace(int A[], int n){   // Define function that inserts into an array-based max heap in-place
    int i = n;   // Set the index to the last element in the heap
    int temp = A[n];   // Store the new element to be inserted in a temporary variable
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){   // While the new element is greater than its parent and not at the root
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];   // Swap the new element with its parent
        i = i % 2 == 0 ? (i/2)-1 : i/2;   // Move up to the parent index
    }
    A[i] = temp;   // Insert the new element in its correct position
}

void CreateHeap(vector<int>& vec, int A[], int n){   // Define function that creates a heap using vector-based max heap
    // O(n log n)
    for (int i=0; i<n; i++){   // Loop over all elements in the array
        Insert(vec, A[i]);   // Insert the current element into the heap
    }
}

void createHeap(int A[], int n){   // Define function that creates a heap using array-based max heap in-place
    for (int i=0; i<n; i++){   // Loop over all elements in the array
        InsertInplace(A, i);   // Insert the current element into the heap
    }
}

template <class T>
void Print(T& vec, int n, char c){   // Define a function that prints the heap
    cout << c << ": [" << flush;   // Print the label of the heap
    for (int i=0; i<n; i++){   // Loop over all elements in the heap
        cout << vec[i] << flush;   // Print the current element
        if (i < n-1){   // If the current element is not the last element in the heap
            cout << ", " << flush;   // Print a comma and a space
        }
    }
    cout << "]" << endl;   // Print the closing bracket of the heap and a newline character
}


int main() {   // Define the main function

    cout << "Create Heap" << endl;   // Print a message indicating the start of the heap creation process
    int b[] = {10, 20, 30, 25, 5, 40, 35};   // Define an array-based max heap
    Print(b, sizeof(b)/sizeof(b[0]), 'b');   // Print the heap

    vector<int> v;   // Define a vector-based max heap
    CreateHeap(v, b, sizeof(b)/sizeof(b[0]));   // Create the heap using the array-based max heap
    Print(v, v.size(), 'v');   // Print the heap

    cout << "Inplace Insert" << endl;   // Print a message indicating the start of the in-place insertion process
    createHeap(b, sizeof(b)/sizeof(b[0]));   // Create the heap using the array-based max heap in-place
    Print(b, sizeof(b)/sizeof(b[0]), 'b');   // Print the heap

    return 0;   // End the program
}
