#include <iostream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(BoardSize size) {
    // Alocates a square with the size given
    int boardSize = size == BoardSize::SMALL ? 3 : 9;
    this->board = new int *[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        this->board[i] = new int[boardSize];
    }
    this->boardSize = boardSize;
}

Sudoku::~Sudoku() {
    //TODO: Fix this, "invalid pointer"
    // Delete columns
//    for (int i = 0; i < this->boardSize; ++i) {
//        delete [] this->board[i];
//    }
    // Delete rows
//    delete [] this->board;
}

ostream &operator<<(ostream &output, Sudoku game) {
    string outStr = "";

    for (int i = 0; i < game.boardSize; ++i) {
        for (int j = 0; j < game.boardSize; ++j) {
            output << to_string(game.board[i][j]);
        }
        output << "\n";
    }

    return output << endl;
}
