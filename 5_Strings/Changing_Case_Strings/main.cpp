#include <iostream>

using namespace std;



int main()
{

//    int i;
//    //Code for changing to lower
//    char A[]="WELCOME";
//    for(i=0;A[i]!='\0';i++){
//        if(A[i]<=90 && A[i]>=65){
//        A[i]=A[i]+32; // ASCII character A=65 and a=97 so 97-65=32 so adding 32 to upper case will give lower case
//        }
//    }
//    cout<<A<<endl;



    //-----------------------------------------------------

    //how you can modify the code to convert all uppercase letters in a string to lowercase letters and remove any non-letter characters, including the null character

    char str[] = "HeLlo\0WorLd";
    char newStr[sizeof(str)/sizeof(char)];
    int i, j;
    for (i = 0, j = 0; i < sizeof(str)/sizeof(char); i++) {
        if (str[i] == '\0') {
            newStr[j] = '\0';
            break;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            newStr[j++] = str[i] + ('a' - 'A');
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            newStr[j++] = str[i];
        }
    }
    cout << "The string in all lowercase letters is: " << newStr << endl;

    //-------------------------------------------------------


    //Toggle upper case and lower case
    char A[]="w5lcome"; //5 will remain as it is
    //int i;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90){
            A[i]+=32;
        }
        else if(A[i]>='a' && A[i]<=122){
            A[i]-=32;
        }
    }
    cout<<"The string is: "<<A<<endl;
    return 0;

}
