#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int isBalanced(char* exp){

    // Create map
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';

    // Create map iterator
    map<char, char>::iterator itr;

    // Create stack
    stack<char> stk;

    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            stk.push(exp[i]); // push the opening brackets onto the stack
        } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if (stk.empty()){ // if the stack is empty, it means there is no corresponding opening bracket
                return false;
            } else {
                char temp = stk.top(); // get the top element of the stack
                itr = mapping.find(exp[i]); // find the corresponding opening bracket in the map
                if (temp == itr->second){ // check if the top element of the stack matches the corresponding opening bracket in the map
                    stk.pop(); // if it does, pop the top element from the stack
                } else {
                    return false; // if it doesn't, return false
                }
            }
        }
    }
    return stk.empty() ? true : false; // if the stack is empty, return true; otherwise, return false
}

int main() {

    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;

    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;

    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;

    return 0;
}
