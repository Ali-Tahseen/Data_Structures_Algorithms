#include <iostream>

using namespace std;

int main()
{
    //Comparing strings
//    char A[]="Painter";
//    char B[]="Painting";
//    int i,j;
//    for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
//    {
//        if(A[i]!=B[j]){
//            break;
//        }
//    }
//    if(A[i]==B[j])cout<<"Equal"<<endl;
//    else if(A[i]<B[j])cout<<A<<" is smaller"<<endl;
//    else cout<<B<<" is smaller"<<endl;
//    return 0;

    //---------------------------------------------------------------------------------------------

    // Palindrome means when you reverse a string it still remains the same
    // Checking palindrome in the first method
    char A[] = "madam";
    char B[7];
    int i, j;

    // Reverse the string in a different array
    for (i = 0; A[i] != '\0'; i++) {
    }
    i = i - 1; // this is done to to make i index start from last character before '\0'
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';
    //cout << "Method one: " << B << endl;



    // Compare the two strings to see if they are Palindrome by checking if they are equal and same
    for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j]){
            break;
        }
    }
    if(A[i]==B[j])cout<<A<<" is a palindrome"<<endl;
    else cout<<A<<" is not a palindrome"<<endl;





    //-----------------------------------------------------


    //Method two of finding a palindrome


//    char A[] = "madam";
//    int i, j;
    for (j = 0; A[j] != '\0'; j++) { // find the length of the string
    }
    j = j - 1; // adjust the index to the last character
//    for (i = 0; i < j; i++, j--) { // reverse the string
//        char temp = A[i];
//        A[i] = A[j];
//        A[j] = temp;
//    }
    for (i = 0, j = j; i<j ; i++, j--) { // check if the string is a palindrome, j should start from the last index before '\0'
        if (A[i] != A[j]) {
            cout << "The string is not a palindrome." << endl;
            return 0;
        }
    }
    cout << "The string is a palindrome." << endl;
    //-----------------------------------------------------

    return 0;

}
