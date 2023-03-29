#include <stdio.h>
#include <stdlib.h>

//Head Recursion
//void fun(int n){
//    if(n>0){
//    fun(n-1);
//    printf("%d",n);
//    }
//}

//While loop for head recursion
void fun(int n){
    int i = 1;
    while(i<=n){
        printf("%d",i);
        i++;
    }
}

int main()
{
    fun(3);
    return 0;
}

// Better to use head recursion for while loop
