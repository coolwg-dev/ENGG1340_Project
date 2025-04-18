#include "board.h"
#include <iostream>

Board::Board() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
    for(int row=0;row<9;++row){
        for(int col=0;col<9;++col){
            while(board[row][col]==0){
                int in=rand()%9+1;
                if(isValid(row,col,in)){
                    board[row][col]=in;
                }
            }
        }
    }
    // Initialize the board with zeros
    for(int a = rand()%15;a>0;--a){
        int i=rand()%9;
        int j=rand()%9;
        board[i][j] = 0;
    }
}

void Board::display() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
bool Board::isGameWon(){
    for (int row=0;row<9;++row){
        for(int col=0;col<9;++col){
            if(board[row][col]==0){
                return false;            
            }
            if(!isValid(row,col,board[row][col])){
                return false;
            }
        }
    }
    return true;
}
bool Board::setCell(int row, int col, int num) {
    if (isValid(row, col, num)) {
        board[row][col] = num;
        return true;
    }
    return false;
}

int Board::getCell(int row, int col) {
    return board[row][col];
}

bool Board::isValid(int row, int col, int num) {
    return !isInRow(row, num) && !isInCol(col, num) && !isInBox(row - row % 3, col - col % 3, num);
}

bool Board::isInRow(int row, int num) {
    for (int col = 0; col < 9; ++col) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Board::isInCol(int col, int num) {
    for (int row = 0; row < 9; ++row) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Board::isInBox(int startRow, int startCol, int num) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return true;
            }
        }
    }
    return false;
}
