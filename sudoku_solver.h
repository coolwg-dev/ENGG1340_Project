#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

class SudokuSolver {
public:
    // Constructor to initialize the Sudoku board
    SudokuSolver(int board[9][9]);

    // Function to solve the Sudoku puzzle
    bool solve();

    // Function to print the Sudoku board
    void printBoard();

private:
    int board[9][9];

    // Helper function to check if a number can be placed at (row, col)
    bool isValid(int row, int col, int num);

    // Backtracking function to solve the Sudoku
    bool solveUtil();
};

#endif // SUDOKU_SOLVER_H
