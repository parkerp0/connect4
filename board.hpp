#ifndef BOARD_HPP
#define BOARD_HPP

#include <math.h>

class board
{
    public:
        board();
        board(board *oldBoard);
        board(board *oldBoard,int column, int player);
        int checkWin();
        int countTriples(int player);
        int countDoubles(int player);
        int drop(int column, int player);

    private:
        int **field;
        int turn;
        int highlightColumn;

};

#endif