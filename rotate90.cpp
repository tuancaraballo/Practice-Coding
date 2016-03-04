//#include <cmath>
#include <cstdio>
//#include <vector>
#include <iostream>
//#include <algorithm>
#include <string.h>
using namespace std;




void rotateRight(int matrix [4][4] , int N){
    for (int layer = 0; layer < N/2; layer++) { // this is the number of layers
        int first = layer; // first element;
        int last = N-1-layer; // how far to go.
        for (int i = first; i<last; i++) {
            int offset = i - first; // how far is the element from the first
            int top_row = matrix[first][i]; // saved first element, to be used later
            //move the left column to the top row:
            matrix[first][i] = matrix[last - offset][first];
            // move the bottom row to the left column
            matrix[last - offset][first] = matrix[last][last - offset];
            //move right column to bottom
            matrix[last][last - offset] = matrix[i][last]; //it iterates thourgh the row
            // move top to to right;
            matrix[i][last] = top_row;
        }
    }
}

void printMatrix(int matrix [4][4], int dimension){
    for (int row = 0; row< dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
    
}

int main() {
    
    int matrix [4][4]= {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    printMatrix(matrix,4);
    rotateRight(matrix,4);
    printMatrix(matrix,4);
    
    
    return 0;
}
