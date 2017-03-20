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

    return output;
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
    // Histogram of numbers
    int lineChecker[this->boardSize];
    // If the line is over or not
    bool gameOver = true;

    // Clean the histogram
    for (int i = 0; i < this->boardSize; ++i) {
        lineChecker[i] = 0;
    }

    // Sum the histogram based in the numbers
    for (int i = 0; i < this->boardSize; ++i) {
        lineChecker[this->board[line][i] - 1] += 1;
    }

    // Sends to cerr if the number repeats X times or isn't in the line
    for (int i = 0; i < this->boardSize; ++i) {
        if (lineChecker[i] > 1) {
            cerr << "Number " << i+1 << " repeats " << lineChecker[i] << " times in line " << line+1 << "." << endl;
            gameOver &= false;
        }
        else if (lineChecker[i] == 0) {
            cerr << "There is no number " << i+1 << " at line " << line+1 << "." << endl;
        }
    }

    return gameOver;
}

bool Sudoku::gameOverLines() {
    bool gameOver = true;

    for (int i = 0; i < this->boardSize; ++i) {
        gameOver &= this->gameOverLine(i);
    }

    return gameOver;
}

bool Sudoku::gameOverColumn(int column) {
    // Histogram of numbers
    int columnChecker[this->boardSize];
    // If the column is over or not
    bool gameOver = true;

    // Clean the histogram
    for (int i = 0; i < this->boardSize; ++i) {
        columnChecker[i] = 0;
    }

    // Sum the histogram based in the numbers
    for (int i = 0; i < this->boardSize; ++i) {
        columnChecker[this->board[i][column] - 1] += 1;
    }

    // Sends to cerr if the number repeats X times or isn't in the column
    for (int i = 0; i < this->boardSize; ++i) {
        if (columnChecker[i] > 1) {
            cerr << "Number " << i+1 << " repeats " << columnChecker[i] << " times in column " << column+1 << "." << endl;
            gameOver &= false;
        }
        else if (columnChecker[i] == 0) {
            cerr << "There is no number " << i+1 << " at column " << column+1 << "." << endl;
        }
    }

    return gameOver;
}

bool Sudoku::gameOverQuadrant(int quadX, int quadY) {
    // Histogram of numbers
    int quadrantChecker[this->boardSize];
    // If the quadrant is over or not
    bool gameOver = true;

    int idxX = quadX * 3;
    int idxY = quadY * 3;

    // Clean the histogram
    for (int i = 0; i < this->boardSize; ++i) {
        quadrantChecker[i] = 0;
    }

    for (int i = idxX; i < idxX + 3; ++i) {
        for (int j = idxY; j < idxY + 3; ++j) {
            quadrantChecker[this->board[i][j] - 1] += 1;
        }
    }

    // Sends to cerr if the number repeats X times or isn't in the column
    for (int i = 0; i < this->boardSize; ++i) {
        if (quadrantChecker[i] > 1) {
            cerr << "Number " << i+1 << " repeats " << quadrantChecker[i] << " times in quadrant " << quadX+1 << ":" << quadY+1 << "." << endl;
            gameOver &= false;
        }
        else if (quadrantChecker[i] == 0) {
            cerr << "There is no number " << i+1 << " at quadrant " << quadX+1 << ":" << quadY+1 << "." << endl;
        }
    }

    return gameOver;
}

bool Sudoku::gameOverQuadrants() {
    bool gameOver = true;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameOver &= this->gameOverQuadrant(i, j);
        }
    }

    return gameOver;
}


bool Sudoku::gameOverColumns() {
    bool gameOver = true;

    for (int i = 0; i < this->boardSize; ++i) {
        gameOver &= this->gameOverColumn(i);
    }

    return gameOver;
}


bool Sudoku::gameOver() {
    bool gameOver = true;

    // Checks all the board for errors
    gameOver &= this->gameOverLines();
    gameOver &= this->gameOverColumns();
    gameOver &= this->gameOverQuadrants();

    return gameOver;
}

