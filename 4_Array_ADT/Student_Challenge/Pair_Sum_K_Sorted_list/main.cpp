#include <iostream>

using namespace std;

int A[]={1,3,4,5,6,8,9,10,12,14};
int len = sizeof(A)/sizeof(int);
int k = 10;

int main()
{
    cout<<len<<" is len "<<endl;
    int i = 0;
    int j=len-1;
    cout<<"j is "<<A[j]<<endl;
    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            cout<<"The pairs are: "<<A[i]<<" and "<<A[j]<<endl;
            i++; // move to the next pair of elements
            j--;
        }
        else if(A[i]+A[j]<k) {
                i++;
            }
        else {
            j--;
        }
    }
    return 0;
}
