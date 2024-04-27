#ifndef BOARD_HPP
#define BOARD_HPP

#include <math.h>

class board
{
    public:
        board();
        int checkWin();
        int drop(int column, int player);

    private:
        int **field;
        int turn;
        int highlightColumn;

};

#endif