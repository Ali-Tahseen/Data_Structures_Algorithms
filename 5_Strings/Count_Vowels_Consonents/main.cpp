#include <iostream>

using namespace std;

int main()
{
    // Count vowels and consonants
    char A[]="How are you";
    int i, vcount=0, ccount=0; //vcount = total number of vowels, ccounts = total number of consonents
    for(i=0;A[i] != '\0'; i++)
    {
       if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E' ||
       A[i]=='I' || A[i]=='O' || A[i]=='U'){
       vcount++;
       }
       else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122)){
        ccount++;
       }
    }
    cout << "Total number of vowels are: "<<vcount<< endl;
    cout << "Total number of consonants are: "<<ccount<< endl;
    //-----------------------------------------------------------------------

    //Counting words
    int word=1;
    for(i=0; A[i]!='\0';i++)
    {
        if(A[i]==' ' && A[i-1]!=' ')//check for spaces and widespaces as well
            word++;
    }
    cout << "Total number of words are: "<<word<< endl;
    return 0;
}
