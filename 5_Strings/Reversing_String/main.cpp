#include <iostream>

using namespace std;

int main()
{
    // Method one using two arrays-------------------------------------
    char A[] = "python";
    char B[7];
    int i, j;
    for (i = 0; A[i] != '\0'; i++) {
    }
    i = i - 1; // this is done to to make i index start from last character before '\0'
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << "Method one: " << B << endl;
    //-----------------------------------------------------------------

    // Method two is using the same array but swaping the position------
    char t;
    for(j=0;A[j] != '\0'; j++)
    {
    }
    j=j-1;
    for(i=0; i<j; i++, j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    cout << "Method two: " << A << endl;
    return 0;
}
