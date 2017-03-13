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

        for (int j = 0; j < boardSize; ++j) {
            this->board[i][j] = 0;
        }
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
        output << endl;
    }

    return output << endl;
}

bool Sudoku::validateSyntax() {
    bool valid = true;
    for (int i = 0; i < this->boardSize; ++i) {
        for (int j = 0; j < this->boardSize; ++j) {
            if (this->board[i][j] > 9 || this->board[i][j] < 1) {
                valid = false;
                cerr << "Invalid Sudoku syntax at " << i+1 << ":" << j+1 << " -> " << this->board[i][j] << "." << endl;
            }
        }
    }
    return valid;
}

bool Sudoku::gameOverLine(int line) {
    int lineChecker[this->boardSize];
    bool gameOver = true;

    for (int i = 0; i < this->boardSize; ++i) {
        lineChecker[i] = 0;
    }

    for (int i = 0; i < this->boardSize; ++i) {
        lineChecker[this->board[line][i] - 1] += 1;
    }

    for (int i = 0; i < this->boardSize; ++i) {
        if (lineChecker[i] != 1) {
            cerr << "Line " << line+1 << " at column " << i+1 << " has a invalid number -> " << this->board[line][i] << "." << endl;
            gameOver = false;
        }
    }

    return gameOver;
}

bool Sudoku::gameOverLines() {
    bool gameOver = true;

    for (int i = 0; i < this->boardSize; ++i) {
        gameOver = this->gameOverLine(i);
    }

    return gameOver;
}

bool Sudoku::gameOver() {
    bool gameOver;

    gameOver = this->gameOverLines();

    return gameOver;
}


