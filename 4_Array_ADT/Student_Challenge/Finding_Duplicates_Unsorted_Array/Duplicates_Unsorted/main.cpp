#include <iostream>

using namespace std;

int A[]={8,3,6,4,6,5,6,8,2,7};
int len = sizeof(A)/sizeof(int);

int main()
{
    for(int i=0;i<len-1;i++)
    {
        int count=1;
        if(A[i] != -1){
        for(int j=i+1;j<len;j++)
        {
            if(A[i]==A[j])
            {
                count++;
                A[j]=-1; // make it -1 because it's a duplicate we counted before like = [8,3,6,4,6,5,6,8,2,7], after = [8,3,6,4,-1,5,-1,-1,2,7]
            }
        }
        if(count>1){
            cout<<A[i]<<" is a duplicate "<<endl;
        }
        }
    }
}
