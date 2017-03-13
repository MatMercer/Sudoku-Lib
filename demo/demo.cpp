#include <iostream>
#include "../libsudoku/sudoku.h"

using namespace std;

int main() {

    Sudoku sud = Sudoku(BoardSize::LARGE);

    sud.loadFromFile("/home/mat/Documents/Projects/sudoku_game/9x9_valid_syntax_not_gameover.txt");
    cout << sud;
    cout << "GameOver: " << sud.gameOver() << "." << endl;

    sud.loadFromFile("/home/mat/Documents/Projects/sudoku_game/9x9_invalid_syntax_not_gameover.txt");
    cout << sud;
    sud.validateSyntax();


    return 0;
}
