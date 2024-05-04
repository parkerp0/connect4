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

    highlightColumn = 3;
    turn = 1;
}

board::~board()
{
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        delete[] field[i];
    }
    delete[] field;
}

board::board(board *oldBoard,int player)
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

    highlightColumn = 3;
    turn = player;
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

void board::print()
{
    printBoard(field,highlightColumn);
}

int board::checkWin()
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(i < 4 && field[i][j] == field[i+1][j] && field[i][j] == field[i+2][j] && field[i][j] == field[i+3][j])//horizontal
                return field[i][j];

            if(j < 3 && field[i][j] == field[i][j+1] && field[i][j] == field[i][j+2] && field[i][j] == field[i][j+3])//vertical
                return field[i][j];

            if(i < 4 && j < 3 && field[i][j] == field[i+1][j+1] && field[i][j] == field[i+2][j+2] && field[i][j] == field[i+3][j+3])//diagonal from top-left to bottom-right
                return field[i][j];

            if(i > 2 && j < 3 && field[i][j] == field[i-1][j+1] && field[i][j] == field[i-2][j+2] && field[i][j] == field[i-3][j+3])//diagonal from bottom-left to top-right
                return field[i][j];
        }
    }
    return 0;
}

// int board::checkWin()
// {
//     for(int i = 0; i < 7; i++)
//     {
//         for(int j = 0; j < 6; j++)
//         {
//             if(i < 4 && field[i][j] == field[i+1][j] && field[i][j] == field[i+2][j] && field[i][j] == field[i+3][j])//horizontal
//                 return field[i][j];

//             if(j < 3)//bounds check for vertical
//             {
//                 if(field[i][j] == field[i][j+1] && field[i][j] == field[i][j+2] && field[i][j] == field[i][j+3])//vertical
//                 {
//                     return field[i][j];
//                 }
//                 if(i < 4 && field[i][j] == field[i+1][j+1] && field[i][j] == field[i+2][j+2] && field[i][j] == field[i+3][j+3])//diagonal
//                 {
//                     return field[i][j];
//                 }
//                 if(i > 2 && field[i][j] == field[i-1][j+1] && field[i][j] == field[i-2][j+2] && field[i][j] == field[i-3][j+3])//diagonal
//                 {
//                     return field[i][j];
//                 }
//             }
//         }
//     }
//     return 0;
// }

int board::countOpenTripleEnds(int player)
{
    int count = 0;

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(field[i][j] == player)
            {
                if(i < 5 && field[i+1][j] == player && field[i+2][j] == player)//horizontal triple
                {
                    if(i<4 && field[i+3][j] == 0)// check for open ends of the triple
                        count++;
                    if(i>0 && field[i-1][j] == 0)
                        count++;
                }
                if(j < 4)//bounds check for vertical
                {
                    if(field[i][j+1] == player && field[i][j+2] == player)//vertical
                    {
                        if(j<3 && field[i][j+3] == 0) // check for open ends of the triple
                            count++;
                        if(j>0 && field[i][j-1] == 0)
                            count++;
                    }
                    if(i < 5 && field[i+1][j+1] == player && field[i+2][j+2] == player)//diagonal
                    {
                        if(i<4 && j<3 && field[i+3][j+3] == 0)// check for open ends of the triple
                            count++;
                        if(i>0 && j>0 && field[i-1][j-1] == 0)
                            count++;
                    }
                    if(i > 1 && field[i-1][j+1] == player && field[i-2][j+2] == player)//diagonal
                    {
                        if(i>2 && j<3 && field[i-3][j+3] == 0) // check for open ends of the triple
                            count++;
                        if(i<6 && j>0 && field[i+1][j-1] == 0)
                            count++;
                    }
                }
            }
        }
    }
    return count;
}

int board::countOpenDoubleEnds(int player)
{
    int count = 0;

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(field[i][j] == player)
            {
                if(i < 6 && field[i+1][j] == player )//horizontal
                    if(i < 5 && field[i+2][j] == 0) // check for open ends of the double
                        count++;
                    if(i > 0 && field[i-1][j] == 0)
                        count++;

                if(j < 5)//bounds check for vertical
                {
                    if(field[i][j+1] == player)//vertical
                    {
                        if(j < 4 && field[i][j+2] == 0) // check for open ends of the double
                            count++;
                        if(j > 0 && field[i][j-1] == 0)
                            count++;
                    }
                    if(i < 6 && field[i+1][j+1] == player)//diagonal
                    {
                        if(i < 5 && j < 4 && field[i+2][j+2] == 0) // check for open ends of the double
                            count++;
                        if(i > 0 && j > 0 && field[i-1][j-1] == 0)
                            count++;
                    }
                    if(i > 0 && field[i-1][j+1] == player)//diagonal
                    {
                        if(i > 1 && j < 4 && field[i-2][j+2] == 0) // check for open ends of the double
                            count++;
                        if(i < 6 && j > 0 && field[i+1][j-1] == 0)
                            count++;
                    }
                }
            }
        }
    }
    return count;
}

int board::drop(int column, int player)
{
    for(int i = 0; i < 6; i++)
    {
        if(field[column][i] == 0)
        {
            field[column][i] = turn;
            return 0;
        }
    }
    return -1;
}

int board::checkDrop()
{
    for(int i = 0; i < 6; i++)
    {
        if(field[highlightColumn][i] == 0)
        {
            return 1;
        }
    }
    return 0;
}

int board::moveHighlight(int move)
{
    highlightColumn = (highlightColumn + move + 7)%7;
    return highlightColumn; 
}

int board::getTurn()
{
    return turn;
}

int board::getHighlightColumn()
{
    return highlightColumn;
}