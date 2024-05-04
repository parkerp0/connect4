#ifndef BOARD_HPP
#define BOARD_HPP

#include <math.h>
#include "printer.hpp"


class board
{
    public:
        board();
        ~board();
        board(board *oldBoard, int player);
        board(board *oldBoard,int column, int player);
        void print();
        int checkWin();
        int countOpenTripleEnds(int player);
        int countOpenDoubleEnds(int player);
        int drop(int column, int player);
        int moveHighlight(int move);
        int getTurn();
        int getHighlightColumn();

    private: 
        int **field;
        int turn;
        int highlightColumn;

};

#endif