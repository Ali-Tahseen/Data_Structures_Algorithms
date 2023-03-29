#include <iostream>

using namespace std;
int A[] = {8,3,6,4,6,5,6,8,2,7};
int len = sizeof(A) / sizeof(int);
int lowest = 1;
int highest = len;
int H[20] = {0};
int main()
{
    for(int i =0; i<len; i++)
    {
        H[A[i]]++;
    }
    for(int i=lowest; i<=highest; i++)
    {
        if(H[i]>1){
            cout<<i<< " has "<<H[i]<<" duplicates."<<endl;
        }
    }

}
