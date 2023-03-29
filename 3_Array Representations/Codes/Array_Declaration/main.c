#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5]; //Five spaces with garbage values
    int B[5] ={1,2,3,4,5}; //Five spaces with five values initialized
    int C[10] = {2,4,6}; // 10 spaces with the first three being 2,4,6 and the rest are 0
    int D[5] = {0}; // Fives spaces with all five of them containing 0
    int E[] = {1,2,3,4,5,6}; //the array size depends on the number of values in the curly braces which is of size 6 here so
    // it is E[6]

    for(int i=0;i<5;i++)
            printf("%u \n",&A[i]);// Print the address of the arrays
    return 0;
}
