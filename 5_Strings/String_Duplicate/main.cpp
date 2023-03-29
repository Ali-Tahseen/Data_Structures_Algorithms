#include <iostream>

using namespace std;

int main()
{
    // String Duplicates
    char A[] = "finding";
    int i,j,k,len=0;
    for(i=0;A[i]!='\0';i++){
        len++;
    }
    for(j=0;j<len;j++){
        for(k=j+1; k<len-1; k++){
            if(A[k]==A[j]){
                cout<<A[k]<<endl;
            }
        }
    }

    // Hash Table method
    int H[128] = {0}; // initialize hash table with all zeros
    for (i = 0; A[i] != '\0'; i++) {
        H[A[i]] += 1; // increment count for character in hash table
    }
    for (i = 0; i < 128; i++) {
        if ((H[i] > 1) && ((i >= 48 && i <= 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122))) {
            cout << (char)i << " is more than one" << endl;
            cout << H[i] << " is the number of duplicates" << endl;
        }
    }
    return 0;
}
