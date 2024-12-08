#include<stdio.h>
#include<stdbool.h>

#define SIZE 9 

int isValidSudoku(int board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        int row[SIZE + 1] = {0}; // To track numbers 1-9 in the row
        int col[SIZE + 1] = {0}; // To track numbers 1-9 in the column
        
        for (int j = 0; j < SIZE; j++) {
            // Check row
            if (board[i][j] != 0) {
                if (row[board[i][j]]) {
                    return 0; // Duplicate found in row
                }
                row[board[i][j]] = 1;
            }
            
            // Check column
            if (board[j][i] != 0) {
                if (col[board[j][i]]) {
                    return 0; // Duplicate found in column
                }
                col[board[j][i]] = 1;
            }
        }
    }

    // Check 3x3 subgrids
    for (int startRow = 0; startRow < SIZE; startRow += 3) {
        for (int startCol = 0; startCol < SIZE; startCol += 3) {
            int grid[SIZE + 1] = {0}; // To track numbers 1-9 in the grid
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = board[startRow + i][startCol + j];
                    if (num != 0) {
                        if (grid[num]) {
                            return 0; // Duplicate found in grid
                        }
                        grid[num] = 1;
                    }
                }
            }
        }
    }

    return 1; 
}
