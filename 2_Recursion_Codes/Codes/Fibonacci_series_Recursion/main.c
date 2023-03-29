#include <stdio.h>
#include <stdlib.h>

// Recursive function for fibonacci
// Excessive recursive function since fib(4) and fib(3) and so on are repetitive
// it takes 2^n time line O(2^n)
int rfib(int n){
    if(n<=1)
        return n;
    return rfib(n-2)+rfib(n-1);
}

// This can solved by using static variable or global variable in this case a static or global array is taken
// Memoization helps solve repetitive calls
// -1 means no value

int F[10];

int Mfib(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=Mfib(n-2);
        if(F[n-1]==-1)
            F[n-1]=Mfib(n-1);
        return F[n-2]+F[n-1];
    }
}



//iterative function for fibonacci
int Ifib(int n){
    int to = 0, t1=1, s,i;
    if(n<=1) return n;
    for(i=2; i<=n; i++){
        s=to+t1;
        to=t1;
        t1=s;
    }
    return s;
}


int main()
{
    //------------------------
    int i;
    for(i = 0; i<10; i++)
        F[i]=-1;
    // This part is only for Memoization

    //--------------------------
    printf("%d \n", Mfib(6));
    return 0;
}
