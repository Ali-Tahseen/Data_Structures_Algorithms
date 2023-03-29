#include <stdio.h>
#include <stdlib.h>

// Simple factorial recursive function to get nCr but the nCr is not recursive
int fact(int n){
    if(n==0) return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r){
    int num, den;
    num=fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}

// Using recursive nCr to find nCr
int NCR(int n, int r){
    {
        if(n==r || r==0)
            return 1;
        return NCR(n-1,r-1)+NCR(n-1,r);

    }
}



int main()
{
    printf("%d \n", NCR(4,2));
    return 0;
}
