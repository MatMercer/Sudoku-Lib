#include <iostream>
#include "../libsudoku/sudoku.h"

using namespace std;

int main() {

    Sudoku s = Sudoku(BoardSize::LARGE);
    cout << s << endl;
    return 0;
}
