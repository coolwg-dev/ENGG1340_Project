#include <iostream>
#include "board.h"
#include "sudoku.h"

void printInstructions() {
    std::cout << "Welcome to Sudoku!\n";
    std::cout << "Enter your moves in the format: row col num\n";
    std::cout << "Example: 0 2 5 (sets row 0, column 2 to 5)\n";
    std::cout << "Enter -1 to exit.\n";
}

int main() {
    Board board;  // Create a new Board object
    board.display();  // Display the initial empty board

    printInstructions();  // Show instructions

    int row, col, num;
    while (true) {
        std::cout << "Enter your move: ";
        std::cin >> row;

        // Exit condition
        if (row == -1) {
            break;
        }

        std::cin >> col >> num;

        if (board.setCell(row, col, num)) {
            board.display();  // Show updated board
            if (board.isGameWon()) {
                std::cout << "Congratulations! You've solved the Sudoku!\n";
                break;
            }
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
