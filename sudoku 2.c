#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
            if ((col + 1) % 3 == 0) printf("  ");
        }
        printf("\n");
        if ((row + 1) % 3 == 0) printf("\n");
    }
}

// Function to check if a number can be placed at a particular position
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check if the number is already in the current row
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) return false;
    }

    // Check if the number is already in the current column
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) return false;
    }

    // Check if the number is already in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using Backtracking
bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col;
    bool empty = false;

    // Find an empty cell (denoted by 0)
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    // If there is no empty cell, the board is solved
    if (!empty) return true;

    // Try placing digits 1 to 9 in the empty cell
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively solve the rest of the board
            if (solveSudoku(board)) return true;

            // If placing num does not lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Function to take input for the Sudoku board
void inputBoard(int board[SIZE][SIZE]) {
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("Enter number for cell (%d, %d): ", row + 1, col + 1);
            scanf("%d", &board[row][col]);
        }
    }
}

int main() {
    int board[SIZE][SIZE];

    // Input the board from the user
    inputBoard(board);

    // Print the initial board
    printf("\nInitial Sudoku Puzzle:\n");
    printBoard(board);

    // Solve the Sudoku puzzle
    if (solveSudoku(board)) {
        printf("\nSolved Sudoku Puzzle:\n");
        printBoard(board);
    } else {
        printf("\nNo solution exists!\n");
    }

    return 0;
}
