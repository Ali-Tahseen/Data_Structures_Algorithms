#include <stdio.h>
#include <stdlib.h>

//int x=0; // It works same like the static int x since which is it only gets initialized once

int fun(int n){
    static int x=0; // Initialized only once so every time the function is called it will increment x by 1
    // However it will get initialized every time if it doesn't
    if(n>0){
        x++;
        return fun(n-1)+x; // This is descending since function is called before x is added
    }
    return 0;
}

int main()
{

    int r;
    r=fun(5);
    printf("%d\n", r);

    r=fun(5);
    printf("%d\n", r);

    return 0;
}
