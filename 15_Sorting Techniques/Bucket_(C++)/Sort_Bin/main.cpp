#include <iostream> // Include the iostream library

using namespace std; // Use the standard namespace

template <class T> // Start definition of a template function
void Print(T& vec, int n, string s){ // Define a function called Print that takes a vector, its size, and a string as arguments
    cout << s << ": [" << flush; // Print the string and an opening bracket
    for (int i=0; i<n; i++){ // Loop over the vector
        cout << vec[i] << flush; // Print the current element of the vector
        if (i < n-1){ // If not the last element of the vector
            cout << ", " << flush; // Print a comma
        }
    }
    cout << "]" << endl; // Print a closing bracket and a newline
}

int Max(int A[], int n){ // Define a function called Max that takes an array and its size as arguments
    int max = -32768; // Initialize a variable called max to a very small number
    for (int i=0; i<n; i++){ // Loop over the array
        if (A[i] > max){ // If the current element is greater than max
            max = A[i]; // Update max to the current element
        }
    }
    return max; // Return the maximum value
}

// Linked List node
class Node{ // Define a class called Node
public: // Public members of the class
    int value; // An integer value
    Node* next; // A pointer to the next Node object
};

void Insert(Node** ptrBins, int idx){ // Define a function called Insert that takes a pointer to an array of Node pointers and an index as arguments
    Node* temp = new Node; // Allocate memory for a new Node object
    temp->value = idx; // Set the value of the new Node object to the index
    temp->next = nullptr; // Set the next pointer of the new Node object to null

    if (ptrBins[idx] == nullptr){ // If the head pointer in the array of Node pointers is null
        ptrBins[idx] = temp; // Set the head pointer to the new Node object
    } else { // Otherwise
        Node* p = ptrBins[idx]; // Get a pointer to the head Node object
        while (p->next != nullptr){ // Loop until we reach the last Node object in the list
            p = p->next; // Move to the next Node object
        }
        p->next = temp; // Set the next pointer of the last Node object to the new Node object
    }
}

int Delete(Node** ptrBins, int idx){ // Define a function called Delete that takes a pointer to an array of Node pointers and an index as arguments
    Node* p = ptrBins[idx];  // Get a pointer to the head Node object
    ptrBins[idx] = ptrBins[idx]->next; // Set the head pointer to the next Node object in the list
    int x = p->value; // Get the value of the Node object
    delete p; // Deallocate memory for the Node object
    return x; // Return the value of the Node object
}

void BinSort(int A[], int n){ // Define a function called BinSort that takes an array and its size as arguments
    int max = Max(A, n); // Get the maximum value in the array

    // Create bins array
    Node** bins = new Node* [max + 1]; // Allocate memory for an array of Node pointers

    // Initialize bins array with nullptr
    for (int i=0; i<max+1; i++){ // Loop over the bins array
        bins[i] = nullptr; // Set each element to null
    }

    // Update count array values based on A values
    for (int i=0; i<n; i++){ // Loop over the array
        Insert(bins, A[i]); // Insert each element into the appropriate bin
    }

    // Update A with sorted elements
    int i = 0; // Initialize a counter
    int j = 0; // Initialize another counter
    while (i < max+1){ // Loop over the bins array
        while (bins[i] != nullptr){ // Loop over the nodes in the current bin
            A[j++] = Delete(bins, i); // Delete the current node, update the array with its value, and move to the next node
        }
        i++; // Move to the next bin
    }

    // Delete heap memory
    delete [] bins; // Deallocate memory for the array of Node pointers
}

int main() { // Define the main function

    int A[] = {2, 5, 8, 12, 3, 6, 7, 10}; // Initialize an array
    int n = sizeof(A)/sizeof(A[0]); // Get the size of the array

    Print(A, n, "\t\tA"); // Print the array
    BinSort(A, n); // Sort the array using BinSort
    Print(A, n, " Sorted A"); // Print the sorted array
    cout << endl; // Print a newline
    return 0; // End the program
}
