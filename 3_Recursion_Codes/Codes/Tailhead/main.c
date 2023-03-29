#include <stdio.h>
#include <stdlib.h>

void fun(int n){
if(n>0){
    // Ascending if function call after print
    printf("%d", n);
    fun(n-1);
    // Descending if function call after print
    // This is recursion's advantage over loop
}
}

int main()
{
    int x = 3;
    fun(x);

    return 0;
}
