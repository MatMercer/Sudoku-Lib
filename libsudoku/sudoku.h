#ifndef SUDOKU_LIBRARY_H
#define SUDOKU_LIBRARY_H

#include <iostream>

using namespace std;

enum class BoardSize {
    SMALL,
    LARGE
};

class Sudoku {
private:
    int boardSize;
    int **board;

    bool gameOverLine(int line);
    bool gameOverLines();

    //TODO: Implement the functions below
    bool gameOverColumn();
    bool gameOverColumns();

    bool gameOverSquare();
    bool gameOverSquares();
public:
    friend ostream &operator<<(ostream &output, Sudoku game);

    void loadFromFile(string fileName);

    bool validateSyntax();

    bool gameOver();

    Sudoku(BoardSize size);

    ~Sudoku();
};

#endif // SUDOKU_LIBRARY_H