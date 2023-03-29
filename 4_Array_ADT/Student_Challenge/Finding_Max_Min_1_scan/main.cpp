#include <iostream>

using namespace std;

int A[]={5,8,3,9,6,2,10,7,-1,4};
int len = sizeof(A)/sizeof(int);


int main()
{
    int min = A[0];
    int max=A[0];
    for(int i=0; i<len; i++){
        if(min>A[i]){
            min=A[i];
        }
        else if(max<A[i]){
            max=A[i];
        }
    }
    cout<<"Maximum is: "<<max<<endl;
    cout<<"Minimum is: "<<min<<endl;
    return 0;
}
