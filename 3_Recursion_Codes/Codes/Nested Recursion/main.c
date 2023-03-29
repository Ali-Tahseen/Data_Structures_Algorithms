#include <stdio.h>
#include <stdlib.h>

// Nested recursion is function calling itself by passing itself as the parameter
// For any value below 100 this function will return 91
int n1, n2;


int fun(int n){
    if(n>100){
        return n-10;

    }
    else {
        return fun(fun(n+11));
    }
}

int main()
{
    printf("%d",fun(102));
    return 0;
}
