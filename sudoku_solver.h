#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

class SudokuGame {
public:
    SudokuGame(int difficulty);
    void displayBoard();
    bool makeMove(int row, int col, int num);
    bool isGameWon();

private:
    int board[9][9];
    void generatePuzzle(int difficulty);
    bool isValidMove(int row, int col, int num);
};

#endif // SUDOKU_GAME_H
