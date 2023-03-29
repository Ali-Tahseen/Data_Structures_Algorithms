#include <iostream>

using namespace std;

int main()
{
    char A[]="decimal";
    char B[]="medical";
    int i,H[26]={0}, lenA=0, lenB=0;
    for(i=0; A[i]!='\0';i++){
        lenA++;
    }
    for(i=0; B[i]!='\0';i++){
        lenB++;
    }
    if(lenA==lenB){
        for(i=0;A[i]!='\0';i++){
            H[A[i]-97]+=1; //Use ASCII code since char have specific number so we need subtract them from initial number to get value
            // and update the hash table
        }
        for(i=0;B[i]!='\0';i++){
            H[B[i]-97]-=1;
            if(H[B[i]-97]<0){
                cout<<"Not Anagram"<<endl;
                break;
            }
            else if(B[i+1]=='\0'){
             cout<<"It's an Anagram"<<endl;
            }
        }
    }
    else{
        cout<<"Not Anagram"<<endl;
    }
    return 0;
}
