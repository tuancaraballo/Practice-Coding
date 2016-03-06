#include "LinkedListBuilder.h"


/*
    Purpose: to add a node to the end of a list.
 */
void AddNode(node * head, int value){
    node * add = new node;
    add->data = value;
    add->next = NULL;
    if (head) {
        node * current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = add;
    } else{
        head = add;
    }
}

void removeNode (nod * head, int value){
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