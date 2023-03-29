#include <iostream>

using namespace std;
int A[] = {3,7,4,9,12,6,1,11,2,10};
int len = sizeof(A) / sizeof(int);
int lowest = 1;
int highest = len;
int H[100] = {0};
int main()
{
    for(int i =0; i<len; i++)
    {
        H[A[i]]++;
    }
    for(int i=lowest; i<=highest; i++)
    {
        if(H[i]==0){
            cout<<i<<" "<<endl;
        }
    }

}
