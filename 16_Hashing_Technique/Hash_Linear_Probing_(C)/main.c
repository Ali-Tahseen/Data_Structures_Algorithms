// Including the standard input/output library header file 'stdio.h'
#include <stdio.h>

// Defining the size of the hash table as 10 using a preprocessor directive
#define SIZE 10

// Function to calculate the hash value for a given key
int hash(int key)
{
    return key % SIZE;
}

// Function to perform linear probing to find an empty slot in the hash table
int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index+i) % SIZE] != 0)
        i++;
    return (index+i) % SIZE;
}

// Function to insert a key in the hash table
void Insert(int H[], int key)
{
    int index = hash(key);

    // If the slot at the calculated index is already occupied, perform linear probing
    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}

// Function to search for a key in the hash table
int Search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index+i) % SIZE] != key)
        i++;
    return (index+i) % SIZE;
}

// Main function
int main()
{
    // Initializing a hash table with all slots set to 0
    int HT[10] = {0};

    // Inserting keys into the hash table
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    // Searching for the key 35 in the hash table
    printf("\nKey found at %d\n", Search(HT, 35));

    // Returning 0 to indicate successful execution of the program
    return 0;
}
