#include <stdio.h>

int puzzle[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0},
};

void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int col, int val);
int solve_puzzle(int puzzle[9][9], int row, int col);

int main() {
    printf("\n\tWELCOME TO SUDOKU SOLVER !");
    printf("\n\nOriginal Puzzle: ");
    print_puzzle(puzzle);
    if (solve_puzzle(puzzle, 0, 0)) {
        printf("\nThe Puzzle Is Solved: ");
        print_puzzle(puzzle);
    } else {
        printf("\nThis Puzzle Is Not Solvable");
    }
    return 0;
}

int solve_puzzle(int puzzle[9][9], int row, int col) {
    if (col == 9) { // Move to next row when column exceeds 8
        row++;
        col = 0;
    }
    if (row == 9) { // Base case: entire puzzle is solved
        return 1;
    }

    if (puzzle[row][col] > 0) { // Skip filled cells
        return solve_puzzle(puzzle, row, col + 1);
    }

    for (int i = 1; i <= 9; i++) { // Try values 1-9
        if (valid_move(puzzle, row, col, i)) {
            puzzle[row][col] = i; // Place the value
            if (solve_puzzle(puzzle, row, col + 1)) { // Recur for next cells
                return 1;
            }
            puzzle[row][col] = 0; // Backtrack if needed
        }
    }
    return 0; // No valid value found, trigger backtracking
}

int valid_move(int puzzle[9][9], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == val || puzzle[i][col] == val) {
            return 0; // Check row and column
        }
    }

    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++) { // Check 3x3 subgrid
        for (int j = 0; j < 3; j++) {
            if (puzzle[r + i][c + j] == val) {
                return 0;
            }
        }
    }
    return 1; // Valid move
}

void print_puzzle(int puzzle[9][9]) {
    printf("\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("\n|--------+------+-------|");
        }
        printf("\n");
        for (int col = 0; col < 9; col++) {
            if (col % 3 == 0) {
                printf("| ");
            }
            if (puzzle[row][col] != 0) {
                printf("%d ", puzzle[row][col]);
            } else {
                printf("  ");
            }
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}
