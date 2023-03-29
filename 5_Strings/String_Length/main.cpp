#include <iostream>

using namespace std;

int main()
{
    int i;
    //char s[]={'w','e','l','c','o','m','e','\0'};//either this
    char s[]="welcome"; // or this
    for(i=0;s[i] != '\0';i++){}
    cout<<"Length is: "<<i<<endl;
    return 0;
}
