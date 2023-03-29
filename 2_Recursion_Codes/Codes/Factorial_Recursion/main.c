#include <stdio.h>
#include <stdlib.h>

// if a recursive function is going to infinite recursive calls then the call terminates as the there is stackoverflow

int fact(int n){
    if(n>0)
        return fact(n-1)*n;
    return 1;
}

int Ifact(int n){
    int f=1;
    int i;
    for(i=1;i<=n;i++)
        f=f*i;
    return s;
}

int main()
{
    printf("%d",fact(4));
    return 0;
}
