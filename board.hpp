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

};