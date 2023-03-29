#include <iostream>

using namespace std;

int A[] = {6,3,8,10,16,7,5,2,9,14};
int len = sizeof(A)/sizeof(int);
int H[17]={0};
int k = 10;

int main()
{
    for(int i =0; i<len; i++)
    {
        if(H[k-A[i]] != 0)
        {
            cout<<A[i]<<" and "<<k-A[i]<<" sum are pairs of "<<k<<endl;
        }
        H[A[i]]++;
    }
}
