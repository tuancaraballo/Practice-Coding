/*
 |Problem: Given a string of binaries, decode the string. The Huffman Tree is provided
 |           {-1,5}
 |       0 /         \ 1
 |   {-1,2}          {A,3}
 |   0/   \1
 |{B,1}  {C,1}
 |
 | S="1001011"
 | 
 |   Note: I created a basic tree, Note: memory allocated by this tree is not freed.
 |         since building the tree is not the goal of this question, but the decoding.
 */


/**************************** LIBRARIES ****************************/

#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

/**************************** FUNCTIONS ****************************/

/* 
|     NAME: decode_huff(...)
|  PURPOSE: To translate a code into a string.
|ARGUMENTS: The root of the node and the binary string to decode
|   RETURN: Nothing, this is a void function.
*/
string decode_huff(node * root,string s)
{
    int len = s.length();
    int start =0;
    string word;
    node * copy = root; // this will be constantly updating, it helps traverse the tree
                        // once we hit a leaf, copy is updated it back to root.
    while(start < len){
        for(int i = start; i< len; i++){
            start++;
            if(s[i] == '1'){ // if it's equal to 1 take right
                if(copy->right){
                    copy = copy->right;
                }
                if (!copy->right && !copy->left) { // if arrived to a leaf
                    word += copy->data;
                    copy = root; // update copy back to the root
                    break;
                }
            } else{
                if(copy->left){ // otherwise turn left
                    copy = copy->left;
                }
                if (!copy->left && !copy->right){ // if arrived to a leaf.
                    word += copy->data;
                    copy = root; // update copy back to the root.
                    break;
                }
            }
        }
    }
    return word;
}


// NOT the ideal way to create a small tree, but it works
//
/*
 |     NAME: initialize(...)
 |  PURPOSE: To build a basic tree containing A,B,C as the data of the leaves
 |ARGUMENTS: Nothing
 |   RETURN: The root of the tree. 
 |     NOTE: The memory is not cleaned in this problem. This is not the best way
 |           to build a tree. I just built it to test the function.
 */
node * initialize(){
    node * first = new node;
    node * sec = new node;
    node * third = new node;
    node * fourth = new node;
    node * fifth = new node;
    
    
    first->data = -1;
    first->left = sec;
    first->right = third;
    
    sec->data = -1;
    sec->left =fourth;
    sec->right = fifth;
    
    third->data = 'A';
    third->left = NULL;
    third->right =NULL;
    
    fourth->data = 'B';
    fourth->left = NULL;
    fourth->right = NULL;
    
    fifth->data = 'C';
    fifth->left = NULL;
    fifth->right = NULL;
   
    return first;
}

int main() {
    
    node * root = initialize();
    string s = "1001011010101010101111";
    string word = decode_huff(root,s);
    cout<<"The translation is: "<<word<<endl;
    return 0;
}
