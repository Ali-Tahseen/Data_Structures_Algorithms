#include <stdio.h>
#include <stdlib.h>

// Three method of making 2D arrays

// 1st method is making a 2D array in the stack

// 2nd Method is taking array of points which is created in stack and to
// for each array in stack create an array in heap and assign it

// 3rd method is taking a double pointer created in stack



int main()
{
    // 1st method 2D array created in stack
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7},};

    //2nd method of 2D arrays
    // array of pointers created in heap
    int *B[3];
    // for each pointer in stack there is array created in heap and assigned to the pointer
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));


    // 3rd method is of creating 2D arrays
    //creating double pointer in stack
    int **C;

    // First 3 rows rows are created in heap
    C=(int **)malloc(3*sizeof(int *));
    // Next three arrays are also created in heap
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    for(int i=0; i<3;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
