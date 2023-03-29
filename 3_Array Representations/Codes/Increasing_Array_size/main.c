#include <stdio.h>
#include <stdlib.h>

// This is the way to increase the size of an array

int main()
{
    // In C++ the array size can made during runtime
    // In C the array has to be mentioned during compile time
    int *p,*q; //create two pointers, pointer q will be used to

    int i;

    // using pointer p create a size of array 5 in the heap
    p=(int *)malloc(5*sizeof(int));
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;

    // use q to create any array of larger size
    q=(int *)malloc(10*sizeof(int));

    // first transfer all the values of pointer p array to pointer q array using for loop
    for(i=0;i<5;i++)
        q[i]=p[i];

    free(p);//free the space pointed by p since p will now point to new array with bigger size
    p=q;//p is pointing on q
    q=NULL; //NULL the q pointer afterwards

    for(i=0;i<5;i++)
            printf("%d \n",p[i]);
    return 0;
}
