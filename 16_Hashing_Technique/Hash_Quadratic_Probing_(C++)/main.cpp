// Including the input/output stream header file 'iostream'
#include <iostream>

// Defining the size of the hash table as 10 using a preprocessor directive
#define SIZE 10

// Importing the 'std' namespace
using namespace std;

// Template function to print the elements of a vector or an array
template <class T>
void Print(T& vec, int n, string s){
    // Printing a string followed by a colon and a space
    cout << s << ": [" << flush;

    // Printing each element of the vector or the array
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;

        // Printing a comma and a space after all elements except the last one
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    // Printing a closing square bracket and a new line character
    cout << "]" << endl;
}

// Function to calculate the hash value for a given key
int Hash(int key){
    return key % SIZE;
}

// Function to perform quadratic probing to find an empty slot in the hash table
int QuadraticProbe(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != 0){
        i++;
    }
    return (idx + i*i) % SIZE;
}

// Function to insert a key in the hash table
void Insert(int H[], int key){
    int idx = Hash(key);

    // If the slot at the calculated index is already occupied, perform quadratic probing
    if (H[idx] != 0){
        idx = QuadraticProbe(H, key);
    }
    H[idx] = key;
}

// Function to search for a key in the hash table
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != key){

        // If a slot with a value of 0 is encountered, the key is not present in the hash table
        if (H[(idx + i*i) % SIZE] == 0){
            return -1;
        }
        i++;
    }
    return (idx + i*i) % SIZE;
}


int main() {
    // Initializing an array of integers
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};

    // Calculating the size of the array
    int n = sizeof(A)/sizeof(A[0]);

    // Printing the array
    Print(A, n, " A");

    // Initializing a hash table with all slots set to 0 and inserting keys into it
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }

    // Printing the hash table
    Print(HT, SIZE, "HT");

    // Searching for the key 25 in the hash table
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;

    // Searching for the key 35 in the hash table
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;

    // Returning 0 to indicate successful execution of the program
    return 0;
}
