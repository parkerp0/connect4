#include "board.hpp"

board::board()
{
    field = new int*[7];
    for (int i = 0; i < 7; i++)
    {
        field[i] = new int[6];
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            field[i][j] = 0;
        }
    }

    highlightColumn = -1;
    turn = rand() % 2 + 1;
}

board::board(board *oldBoard)
{
    field = new int*[7];
    for (int i = 0; i < 7; i++)
    {
        field[i] = new int[6];
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            field[i][j] = oldBoard->field[i][j];
        }
    }

    highlightColumn = -1;
    turn = oldBoard->turn;
}

board::board(board *oldBoard,int column, int player)
{
    field = new int*[7];
    for (int i = 0; i < 7; i++)
    {
        field[i] = new int[6];
    }//allocate memory for the field

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            field[i][j] = oldBoard->field[i][j];
        }
    }//copy the field

    drop(column, player);//add new piece to the board

    highlightColumn = column;//highlight the column that was just played
    turn = (player == 1) ? 2 : 1;//switch turns
}

int board::checkWin()
{
    for(int i; i < 7; i++)
    {
        for(int j; j < 6; j++)
        {
            if(i < 4 && field[i][j] == field[i+1][j] && field[i][j] == field[i+2][j] && field[i][j] == field[i+3][j])//horizontal
                return field[i][j];

            if(j < 3)//bounds check for vertical
            {
                if(field[i][j] == field[i][j+1] && field[i][j] == field[i][j+2] && field[i][j] == field[i][j+3])//vertical
                {
                    return field[i][j];
                }
                if(field[i][j] == field[i+1][j+1] && field[i][j] == field[i+2][j+2] && field[i][j] == field[i+3][j+3])//diagonal
                {
                    return field[i][j];
                }
                if(field[i][j] == field[i-1][j+1] && field[i][j] == field[i-2][j+2] && field[i][j] == field[i-3][j+3])//diagonal
                {
                    return field[i][j];
                }
            }
        }
    }
    return 0;
}

int board::drop(int column, int player)
{
    for(int i = 0; i < 5; i++)
    {
        if(field[column][i] == 0)
        {
            field[column][i] = player;
            return 0;
        }
    }
    return -1;
}

