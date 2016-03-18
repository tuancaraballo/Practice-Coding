#include <cmath>

/****************************** LIBRARIES ****************************/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>

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
void findKthElement(int position);
node * findNthElement(int value);
void deleteNode(node * start);
/************************** MAIN FUNCTION **************************/

int main(){
    
    int values [10] = {1,2,1,3,4,5,3,3,7,7};
    
    for (int i = 0; i < 10; i++) {
        AddNode(values[i]);
    }
    cout<<" - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<"List: ";
    printList();
    cout<<" - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<"Finding the 6th to last element: ";
    findKthElement(6);
    cout<<" - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    node * temp = findNthElement(5);
    cout<<"Element to remove only given a pointer to it: "<<temp->data<<endl;
    deleteNode(temp);
    printList();
    cout<<" - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<"Removing all duplicates: ";
    removeDouble();  // 1 2 3 4 5 7
    printList();
    cout<<" - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    
    
    return 0;
}

/************************** FUNCTIONS **************************/
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

// Purpose: To find te kth element to last

void findKthElement(int position){
    if (head) {
        stack<node*> mystack;
        node * current = head;
        while (current) {
            mystack.push(current);
            current = current->next;
        }
        while (position != 1) {
            mystack.pop();
            position--;
        }
        cout<<mystack.top()->data<<endl;
    }
}

// Purpose: To find and return the node containing the value passed as argument, if
//          the value is not contained in the linked list it returns a NUll pointer.
node * findNthElement(int value){
    if (head) {
        node * current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}

// Purpose: Given a pointer to the the node that contains the value we need to delete that node. Since the question does require that we don't use head, only the pointer
//  given, the only solution I see here is to copy/move all info one node back and delete the last node.

void deleteNode(node * start){
    if (start) {
        node * current =  start;
        node * previous = current;
        while (current->next) {
            current->data = current->next->data;
            previous =  current;
            current = current->next;
        }
        delete(current);
        previous->next = NULL;
    }
    


    
}

