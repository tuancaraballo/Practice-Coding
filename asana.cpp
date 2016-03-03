// Name: Tuan Anh Caraballo
/*
 Algorithm: In main the user should write a matrix. and pass it to the function with
            he dimensions of the matrix. Otherwise we could calculate the dimensions
            using sizeof, ex:
            int number_rows = sizeof(matrix)/sizeof(matrix[0]);
            There might be a more efficient way to do this, but the first thing that 
            I came up with was to treat the grid in 4 different parts: top, right
            column, bottom row and left column. Then as we reach the end of the top row,
            we update the row_start to the following, we do the same with row_end,
            cols_start and cols_end. After updating these values we check if they have 
            not crossed their allowed boundaries, meaning that row_end must always be 
            greater than row_start, same as cols_end must always be greater than
            cols_start, otherwise we break out of the loop.
 */

void printMatrix(int matrix[][], int the_rows, int the_columns)
{
    int row_start = 0;
    int row_end = the_rows -1;
    int cols_start = 0;
    int cols_end = the_columns -1;
    while (true) {
        for (int cols = cols_start; cols <= cols_end; cols++) {
            cout<<matrix[row_start][cols]<< " "
        }
        row_start++;
        if (row_end<row_start) {
            break;
        }
        for (int row = row_start; row <= row_end; row++) {
            cout<<matrix[row][cols_end]<<" ";
        }
        cols_end --;
        if (cols_end < cols_start) {
            break;
        }
        for (int cols = cols_end; cols >=cols_start; cols--) {
            cout<<matrix[row_end][cols]<< " ";
        }
        row_end--;
        if (row_end < row_start) {
            break;
        }
        for (int row =row_end; row>= row_start ; row--) {
            cout<<matrix[row][cols_start]<<" ";
        }
        cols_start++;
        if (cols_end < cols_start) {
            break;
        }
    }
}




