#include <iostream>
#include <fstream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(BoardSize size) {
    // Allocates a square with the size given
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

void Sudoku::loadFromFile(string fileName) {
    ifstream File;
    File.open(fileName);

    if (!File) {
        cerr << "Failed to open " << fileName << endl;
    }

    for(int i = 0; i < this->boardSize; ++i) {
        for (int j = 0; j < this->boardSize; ++j) {
            File >> this->board[i][j];
        }
    }
}

ostream &operator<<(ostream &output, Sudoku game) {
    for (int i = 0; i < game.boardSize; ++i) {
        for (int j = 0; j < game.boardSize; ++j) {
            if (j + 1 < game.boardSize) {
                output << to_string(game.board[i][j]) << " ";
            }
            else {
                output << to_string(game.board[i][j]);
            }
        }
        output << "\n";
    }

    return output << endl;
}


