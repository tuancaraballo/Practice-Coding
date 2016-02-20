/*********************** QUESTION *************************/
/*
 | Question 1.4: Given a string, add 20% in all white spaces. Assume the string
 |               has sufficient space at the end to fit the additional characters and
 |               that you are given the true length of the string.
 |           eg:   input:  "Mr John Smith    " length = 13
 |                output:  "Mr20%John20%Smith"
 */



/*********************** LIBRARIES  ***********************/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

/*********************** LIBRARIES  ***********************/
const int WORD_LENGTH = 1000;


void fillWhiteSpaces(char original []){
    char tag [] = "20%";   // string literal
    int lenght = strlen (original);
    //char * modified;
    for (int i =0; i<lenght; i++) {
        if (original[i] == ' ') {
            char * origin = original + i;
            char * destination = origin + 3; // original (start) + current position of white space plus  three (20%)
            strcpy(destination, origin +1);
            strncpy(origin,tag,3); // not strcpy, because it copies the null teminator
                                    // unlike strncpy
        }
    }
}

// NOTE: I'm using char arrays instead of strings.

int main()
{
    char sentence[WORD_LENGTH];
    cout << "Enter sentence: ";
    cin.get(sentence,WORD_LENGTH);
    cin.ignore(WORD_LENGTH, '\n'); // it cleans the input buffer.
    cout<<endl;
    fillWhiteSpaces(sentence);
    cout<<sentence<<endl;
    cout<<endl;
    return 0;
}
