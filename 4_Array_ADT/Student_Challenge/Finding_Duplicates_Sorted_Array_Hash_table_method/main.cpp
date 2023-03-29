#include <iostream>

using namespace std;

int A[] = {3,6,8,10,12,15,15,15,20};
int len = sizeof(A)/sizeof(int);
int H[21] = {0}; // increase the size of H to 21 to handle numbers up to 20

int main()
{
    for(int i=0; i<len; i++)
    {
        H[A[i]]++;
    }
    for(int i=0; i<=20; i++)
    {
        if(H[i]>1){
                cout<<"The duplicates are: "<<i<<" appears "<<H[i]<<" times"<<endl;
        }
    }

    return 0;
}
