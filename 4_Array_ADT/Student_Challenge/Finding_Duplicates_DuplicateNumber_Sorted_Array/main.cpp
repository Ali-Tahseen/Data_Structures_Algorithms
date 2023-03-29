#include <iostream>

using namespace std;

int A[] = {3,6,8,8,10,12,15,15,15,20};
int len = sizeof(A)/sizeof(int);

int main()
{
    // Find Duplicates
    int lastDuplicate=0;
    for(int i=0;i<len;i++)
    {
        if(A[i]==A[i+1] && A[i] != lastDuplicate)
        {
            cout<<A[i]<<endl;
            lastDuplicate=A[i];
        }
    }
    //Finding number of Duplicates
    for(int i=0;i<len;i++)
    {
        if(A[i]==A[i+1])
        {
            int j=i+1;
            while(A[j]==A[i])j++;
            cout<<A[i]<<" is appearing "<<j-i<<" times."<<endl;
            i=j-1;
        }
    }
    return 0;
}
