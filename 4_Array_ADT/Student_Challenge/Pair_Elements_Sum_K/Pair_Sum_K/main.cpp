#include <iostream>

using namespace std;

int A[] = {6,3,8,10,16,7,5,2,9,14};
int len = sizeof(A)/sizeof(int);
int k = 10;

int main()
{
    for(int i =0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++){
            if(A[i]+A[j]==k)cout<<" The pairs are "<<A[i]<<" and "<<A[j]<<endl;

        }
    }
}
