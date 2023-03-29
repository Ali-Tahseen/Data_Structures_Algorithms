#include <stdio.h>
#include <stdlib.h>

//this is 2^9 and has more number of steps
int Lpow(int m,int n){
    if(n==0)
        return 1;
    return Lpow(m,n-1)*m;
}


//this is 2*(2^8) and has less number of steps
int Spow(int m, int n){
    if(n==0)
        return 1;
    if(n%2==0)
        return Spow(m*m,n/2);
    else
        return m*Spow(m*m,(n-1)/2);
}

//iterative process of finding power
int Ipow(int m, int n){
    int e = 1;
    for(int i=1; i<=n; i++){
        e=e*m;
    }
    return e;
}

int main()
{
    printf("%d",Ipow(2,9));
    return 0;
}
