/*
| Description: Implement a function that determines if a string of parenthesis and curly 
|              braces and square braces is balanced:
|              ex:  {[]}{()[{}]}  is balanced
|              {(}) is not balanced
|  Algorithm:  Implemented a stack that saves opening braces, if it encounters a non-
|              opening characters it checks if it's  closing curly braces and if it
|              matched the most recently added brace to the stack, if it does, the top 
|              element is popped
*/


/******************************** LIBRARIES ******************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

/********************************* FUNCTIONS ****************************************/

/*
 |      Name: isOpen(...)
 |   Purpose: To determine if a character is
 | Arguments: A character
 |     Reurn: true if it's an opening brace, false otherwise.
 */

bool isOpen (char input){
    if(input == '{' || input == '[' ||input == '(' ){
        return true;
    }
    return false;
}

/*
 |      Name: findOpposite(...)
 |   Purpose: To find the opposite of a brace
 | Arguments: A character
 |     Reurn: A closing brace that matches the one being passed as the argument.
 */
char findOpposite(char input){
    if(input == '}') return '{';
    if(input == ']') return '[';
    if(input == ')') return '(';
    return 't';
    
}

/*
 |      Name: isbalanced(...)
 |   Purpose: To determine if the string passed is balanced, it calls the above function
 | Arguments: A string
 |     Reurn: True if balanced, false otherwise.
 */
bool isBalanced(string input){
    stack <char> mystack;
    int len = input.length();
    for(int i =0; i< len; i++){
        if(isOpen(input[i])){
            mystack.push(input[i]);
        }
        else if(findOpposite(input[i]) == mystack.top()){
            mystack.pop();
        }else{
            return false;
        }
    }
    if(mystack.size() == 0){
        return true;
    }
    return false;
    
}

int main() {
    string input;
    cout<<"Enter line: ";
    getline(cin,input);
    if(isBalanced(input)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
