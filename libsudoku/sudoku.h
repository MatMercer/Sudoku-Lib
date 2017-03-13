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
public:
    friend ostream &operator<<(ostream &output, Sudoku game);

    void loadFromFile(string fileName);

    Sudoku(BoardSize size);

    ~Sudoku();
};

#endif // SUDOKU_LIBRARY_H