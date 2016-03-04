//#include <cmath>
#include <cstdio>
//#include <vector>
#include <iostream>
//#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;


string compress(string word){
    int len = word.length();
    int count = 1;
    string comp;
    int i;
    for (i = 1; i< len; i++) {
        if (word[i] == word[i-1]) {
            count++;
        } else{
            comp += word[i-1];
            comp += to_string(count);
            count =1;
        }
    }
    comp += word[i-1];
    comp += to_string(count);
    count =1;
    return comp;
}

int main() {
    
    string word = "aaabbbbbbccccc";
    cout<<compress(word)<<endl;



    
    return 0;
}
