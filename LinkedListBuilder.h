#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#include "LinkedListBuilder.cpp"

using namespace std;

struct node {
    int data;
    node * next;
};

// Function Prototypes:
void removeNode (node * head, int value);
void AddNode(node * head, node * add);

