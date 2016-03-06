#include <cmath>

/****************************** LIBRARIES ****************************/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct node {
    int data;
    node * next;
};

node * head = NULL;

/************************** FUNCTION PROTOTYPES **************************/
void AddNode(int value);
void removeNode (node * head, int value);
void printList();
void removeDouble();

/************************** MAIN FUNCTION **************************/

int main(){
    
    int values [10] = {1,2,1,3,4,5,3,3,7,7};
    
    for (int i = 0; i < 10; i++) {
        AddNode(values[i]);
    }
    printList();
    removeDouble();
    printList();
    
    
    
    
    return 0;
}

/************************** FUNCTION **************************/
// Purpose: to add a node to the end of a list.

void AddNode(int value){
    node * add = new node;
    add->data = value;
    add->next = NULL;
    
    if (head == NULL) {
        head = add;
    }else{
        node * current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = add;
    }
}

// Purpose: to remove a node from a linked list.
void removeNode (node * head, int value){
    if (head) {
        node * current = head;
        node * previous = current;
        while (current) {
            if (current->data == value) {
                node * temp =  current->next;
                delete(current);
                previous->next = temp;
                break;
            }
            previous = current;
            current = current->next;
        }
    }
}
//  Purpose: to print a Linear Linked List
void printList(){
    if (head) {
        node * current = head;
        while (current) {
            cout<<current->data<<" ";
            current = current->next;
        }
    }
    cout<<endl;
}

// Purpose: To remove repeated nodes
void removeDouble(){
    if (head) {
        node * compare =  head;
        node * previous;
        node * current;
        while (compare) {
            current = compare->next;
            previous = compare;
            while (current) {
                if (current->data == compare->data) {
                    previous->next = current->next;
                    delete(current);
                    current= previous->next;
                } else{
                previous = current;
                current = current->next;
                }
            }
                compare = compare->next;
        }
       
    }
    
}
