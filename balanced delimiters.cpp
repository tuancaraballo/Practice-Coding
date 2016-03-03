//#include <cmath>
#include <cstdio>
//#include <vector>
#include <iostream>
//#include <algorithm>
#include <string.h>
using namespace std;

char findOpposite(char c){
    switch(c){
        case '}':
            return '{';
        case ']':
            return '[';
        case ')':
            return '(';
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        default:
            return 'z';
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char string[1000];
    cout<<"Enter string: ";
    cin.get(string, 1000);
    cin.ignore(1000, '\n');
    int len = strlen(string);
    if(len>1 && len%2 ==0){
        int count =0;
        for(int i = 1; i<len; i++){
            char c = findOpposite(string[i]);
            if(c == 'z'){
                cout<<"It's not balanced!"<<endl;
                return 0;
            }
            if( c == string[i-1]){
                count++;
            } else if ( c == string[i-2*count-1]){
                count++;
            }
        }
        if(count == len/2){
            cout<<"It's balanced!"<<endl;
            return 1;
        }
    }
    cout<<"False"<<endl;
    return 0;
}
