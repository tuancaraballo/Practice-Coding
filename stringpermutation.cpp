
/*********************** QUESTION *************************/
/*
 | Question: Giventwo strings, write a function to decide if one is a 
 |           a permutation of the other. eg ABC and CBA should return true
 |           ABC and CDA should return false.
 *?



/*********************** LIBRARIES  ***********************/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/*********************** LIBRARIES  ***********************/
const int WORD_LENGTH = 100;


bool isPermutation (char original [], char permutation []){
    int len1 = strlen(original);
    int len2 = strlen(permutation);
 
    if (len1 == len2) {
        for (int i = 0; i<len2; i++) {
            char * ptr = strchr(original, permutation[i]);
            if (ptr == NULL) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// NOTE: I'm using char arrays instead of strings.

int main()
{
   
    char original[WORD_LENGTH];
    char permutation[WORD_LENGTH];
    cout << "Enter original word!: ";
    cin.get(original,WORD_LENGTH);
    cin.ignore(WORD_LENGTH, '\n'); // it cleans the input buffer. 
    cout<<endl<< "Enter the permutation word: ";
    cin.get(permutation,WORD_LENGTH);
    cin.ignore(WORD_LENGTH, '\n');
    cout<<endl;
    if (isPermutation (original,permutation)) {
        cout<<"Yes!"<<endl;
    } else{
        cout<<"Nope!"<<endl;
    }
    cout<<endl;
    return 0;
}
