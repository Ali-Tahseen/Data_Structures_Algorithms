#include <iostream> // include input/output stream library
#include <cmath> // include math library

using namespace std; // use standard namespace

template <class T> // define a template for a function that takes a generic type T
void Print(T& vec, int n, string s){ // define function to print elements of an array or vector
    cout << s << ": [" << flush; // flush output stream and print the string s followed by "["
    for (int i=0; i<n; i++){ // loop through the array/vector
        cout << vec[i] << flush; // flush output stream and print the current element
        if (i < n-1){ // if the current element is not the last element
            cout << ", " << flush; // flush output stream and print a comma followed by a space
        }
    }
    cout << "]" << endl; // print a closing bracket followed by a newline character
}

int Max(int A[], int n){ // define function to find the maximum element in an array
    int max = -32768; // initialize max to a very small value
    for (int i=0; i<n; i++){ // loop through the array
        if (A[i] > max){ // if the current element is greater than max
            max = A[i]; // update max
        }
    }
    return max; // return the maximum element
}

// Linked List node
class Node{ // define a class for a linked list node
public:
    int value; // the value stored in the node
    Node* next; // a pointer to the next node in the linked list
};

int countDigits(int x){ // define a function to count the number of digits in an integer
    int count = 0; // initialize count to zero
    while (x != 0){ // while x is not zero
        x = x / 10; // divide x by 10
        count++; // increment count
    }
    return count; // return the number of digits
}

void initializeBins(Node** p, int n){ // define a function to initialize an array of linked list head pointers
    for (int i=0; i<n; i++){ // loop through the array
        p[i] = nullptr; // set each head pointer to null
    }
}

void Insert(Node** ptrBins, int value, int idx){ // define a function to insert a value into a linked list bin at a given index
    Node* temp = new Node; // create a new linked list node
    temp->value = value; // set the value of the new node
    temp->next = nullptr; // set the next pointer of the new node to null

    if (ptrBins[idx] == nullptr){ // if the bin at the given index is empty
        ptrBins[idx] = temp;  // set the head pointer to point to the new node
    } else { // otherwise
        Node* p = ptrBins[idx]; // create a pointer to the head of the linked list at the given index
        while (p->next != nullptr){ // loop through the linked list until the end is reached
            p = p->next; // move to the next node
        }
        p->next = temp; // set the next pointer of the last node to point to the new node
    }
}

int Delete(Node** ptrBins, int idx){ // define a function to delete the first node from a linked list bin at a given index
    Node* p = ptrBins[idx]; // create a pointer to the head of the linked list at the given index
    ptrBins[idx] = ptrBins[idx]->next; // update the head pointer to point to the next node in the linked list
    int x = p->value; // store the value of the first node
    delete p; // delete the first node
    return x; // return the value of the first node
}

int getBinIndex(int x, int idx){ // define a function to get the bin index for an element in the array
    return (int)(x / pow(10, idx)) % 10; // return the index of the bin where the element belongs
}

void RadixSort(int A[], int n){ // define the Radix Sort function to sort an array
    int max = Max(A, n); // find the maximum element in the array
    int nPass = countDigits(max); // find the number of digits in the maximum element

    // Create bins array
    Node** bins = new Node* [10]; // create an array of head pointers for the linked list bins

    // Initialize bins array with nullptr
    initializeBins(bins, 10); // set all the head pointers to null

    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){ // for each pass

        // Update bins based on A values
        for (int i=0; i<n; i++){ // loop through the array
            int binIdx = getBinIndex(A[i], pass); // get the bin index for the current element
            Insert(bins, A[i], binIdx); // insert the current element into the corresponding linked list bin
        }

        // Update A with sorted elements from bin
        int i = 0; // initialize a counter for the array
        int j = 0; // initialize a counter for the linked list
        while (i < 10){ // while there are still linked lists with elements
            while (bins[i] != nullptr){ // while the current linked list is not empty
                A[j++] = Delete(bins, i); // delete the first node from the linked list and add its value to the array
            }
            i++; // move to the next linked list
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10); // set all the head pointers to null
    }

    // Delete heap memory
    delete [] bins; // deallocate the memory used for the linked list bins
}

int main() {

    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62}; // create an array to be sorted
    int n = sizeof(A)/sizeof(A[0]); // find the length of the array

    Print(A, n, "\t\tA"); // print the original array
    RadixSort(A, n); // sort the array using Radix Sort
    Print(A, n, " Sorted A"); // print the sorted array

    return 0; // exit the program with a status code of 0
}
