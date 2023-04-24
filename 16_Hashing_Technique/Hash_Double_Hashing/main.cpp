#include <iostream>     // Standard input/output library
#define SIZE 10         // Define a constant variable SIZE as 10
#define PRIME 7         // Define a constant variable PRIME as 7

using namespace std;    // Using the standard namespace

template <class T>      // Define a function template for printing an array
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;   // Print the function name and opening bracket
    for (int i=0; i<n; i++){       // Loop over the array and print each element
        cout << vec[i] << flush;
        if (i < n-1){             // If not the last element, print a comma and space
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;           // Print the closing bracket and a newline character
}

int Hash(int key){               // Define a simple hash function that returns the modulus of the key with SIZE
    return key % SIZE;
}

int PrimeHash(int key){          // Define a hash function that uses prime numbers
    return PRIME - (key % PRIME);
}

int DoubleHash(int H[], int key){  // Define a double hashing function
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0){  // Loop until an empty slot is found
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;  // Return the index of the empty slot
}

void Insert(int H[], int key){    // Define a function to insert a key into the hash table
    int idx = Hash(key);          // Get the index of the key using the simple hash function

    if (H[idx] != 0){             // If the slot is not empty, use double hashing to find an empty slot
        idx = DoubleHash(H, key);
    }
    H[idx] = key;                 // Insert the key into the hash table
}

int Search(int H[], int key){     // Define a function to search for a key in the hash table
    int idx = Hash(key);          // Get the index of the key using the simple hash function
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key){  // Loop until the key is found or an empty slot is encountered
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0){   // If an empty slot is encountered, return -1 to indicate failure
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;  // Return the index of the key in the hash table
}


int main() {

    int A[] = {5, 25, 15, 35, 95};   // Initialize an array of integers
    int n = sizeof(A)/sizeof(A[0]);  // Get the size of the array
    Print(A, n, " A");               // Print the array

    // Hash Table
    int HT[10] = {0};                // Initialize a hash table with 10 slots
    for (int i=0; i<n; i++){         // Insert each key from the array into the hash table
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");           // Print the hash table

    int index = Search(HT, 25);      // Search for key 25 in the hash table
    cout << "key found at: " << index << endl;   // Print the index of the key in the hash table

    index = Search(HT, 35);          // Search for key 35 in the hash table
    cout << "key found at: " << index << endl;   // Print the index of the key in the hash table

    return 0;                        // Return 0 to indicate successful program execution
}
