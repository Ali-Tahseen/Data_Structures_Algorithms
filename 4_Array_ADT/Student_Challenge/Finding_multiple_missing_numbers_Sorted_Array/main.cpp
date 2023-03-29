#include <iostream>

using namespace std;

int A[] = {6,7,8,9,11,12,15,16,17,18,19};
int main()
{
    int lowest = A[0]; // in a sorted list
    int diff = lowest-0;
    for(int i = 0; i<sizeof(A)/sizeof(int); i++)
    {
        if(A[i]-i != diff)
        {
            while(diff<A[i]-i)
            {
                cout<<i+diff<<" "<<endl;
                diff++;
            }
        }
    }
    return 0;
}
// order to n
