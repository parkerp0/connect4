#ifndef BOARD_HPP
#define BOARD_HPP

#include <math.h>


class board
{
    public:
        board();
        board(board *oldBoard, int player);
        board(board *oldBoard,int column, int player);
        int checkWin();
        int countOpenTripleEnds(int player);
        int countOpenDoubleEnds(int player);
        int drop(int column, int player);
        int getTurn();

    private: 
        int **field;
        int turn;
        int highlightColumn;

};

#endif