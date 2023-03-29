#include <stdlib.h>
#include <stdio.h>

//Tail recursion
// Four activation records created
// space - O(n)
void fun(int n){
    if(n>0){
        printf("%d",n);
        fun(n-1);
    }
}


//While loop to replace tail recursion
//only one activation record created
//space-O(1)
//void fun(int n){
//    while(n>0){
//        printf("%d",n);
//        n--;
//    }
//}

int main()
{
    fun(3);
    return 0;
}


// In tail recursion they only use loop instead of tail recursion
