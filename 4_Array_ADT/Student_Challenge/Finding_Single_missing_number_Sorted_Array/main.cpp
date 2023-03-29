#include <iostream>

using namespace std;

int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
int B[] = {6, 7, 8, 9 , 10, 11, 13, 14, 15, 16, 17};

int main()
{
    // Method 1
    int sum = 0;
    int MissNum = 0;
    int n = sizeof(A)/sizeof(int) + 1;  // calculate the expected size of the array with the missing element
    int s = n*(n+1)/2;  // calculate the sum of integers from 1 to n = 78

    for(int i = 0; i < sizeof(A)/sizeof(int); i++)  // iterate through all the elements in A
    {
        sum += A[i]; // calculate sum of all elements in the array = 71
    }

    MissNum = s - sum;  // calculate the missing number by 78 -71

    cout << "Method 1: Missing number in A is: " << MissNum << endl;


    // Method 2
    int l = B[0]; // lowest number in a sorted array so B[0]
    int diff = l-0;
    for(int i=0;i<sizeof(B)/sizeof(int);i++)
    {
        if(B[i]-i != diff)
        {
            int element = i+diff;
            cout<<"Method 2: Missing element in B is: " << element << endl;
            break;
        }
    }

    return 0;
}
