#include <iostream>

using namespace std;

int main()
{
    char A[]="finding";
    long int H=0, x=0;
    for(int i=0;A[i]!='\0';i++)
    {
        x=1;
        x=x<<(A[i]-97); //shifting bits by the difference in a 32bit to fill the value as 1 video 139
        if((x&H)>0) //Masking
        {
            cout<<A[i]<<endl;
        }
        else{
            H=x|H; //Merging
        }
    }
    return 0;
}
