#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();                          // Constructor to initialize the board
    void display();                   // Method to display the board
    bool setCell(int row, int col, int num); // Set a number in a cell
    int getCell(int row, int col);    // Get the number from a cell
    bool isValid(int row, int col, int num); // Check if placing num is valid

private:
    int board[9][9];                  // 2D array for the Sudoku board
    bool isInRow(int row, int num);   // Check if num is in the specified row
    bool isInCol(int col, int num);   // Check if num is in the specified column
    bool isInBox(int startRow, int startCol, int num); // Check in the 3x3 box
};

#endif // BOARD_H
