#include "printer.hpp"

void initPrinter()
{//if there is a lot more time at the end/doubt it switch over to openGL for graphics
    initscr();
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_WHITE);
    init_pair(5, COLOR_BLUE, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
}

void deletePrinter()
{
    endwin();
}

int printMenu()
{
    clear();
    mvprintw(0, 0, "Welcome to Connect 4!");
    attron(COLOR_PAIR(1));
    mvprintw(1, 0, "Now in color");
    attroff(COLOR_PAIR(1));
    mvprintw(2, 0, "1. Play against the MINIMAX algorithm");
    return getChoice(3);
}

void printBoard(int **field, int highlight)
{
    clear();
    int offset = 0;
    for(int i = 0; i < 7; i++)
    {
        if(i == highlight)offset = 3;
        else offset = 0;

        for(int j = 0; j < 6; j++)
        {
            if(field[i][j] == 1)
                attron(COLOR_PAIR(1 + offset));
            else if(field[i][j] == 2)
                attron(COLOR_PAIR(2 + offset));
            else
                attron(COLOR_PAIR(3 + offset));
            mvprintw(5-j, i, "O");
        }
    }
    refresh();
}

void printBoardStats(int redWin, int blueWin, int redTriples, int blueTriples, int redDoubles, int blueDoubles,int evaluation)
{
    mvprintw(1,8,"RED WIN: %d", redWin);
    mvprintw(2,8,"BLUE WIN: %d", blueWin);
    mvprintw(3,8,"RED TRIPLES: %d", redTriples);
    mvprintw(4,8,"BLUE TRIPLES: %d", blueTriples);
    mvprintw(5,8,"RED DOUBLES: %d", redDoubles);
    mvprintw(6,8,"BLUE DOUBLES: %d", blueDoubles);
    mvprintw(7,8,"Evalution: %d",evaluation);
}

void printEvals(int *evals, int size)
{
    for(int i = 0; i < size; i++)
    {
        mvprintw(i+8,0, "%d", evals[i]);
    }
    refresh();
}

void printWin(int player)
{
    clear();
    if(player == 1)
    {
        attron(COLOR_PAIR(1));
        mvprintw(0, 0, "Player 1 wins!");
        attroff(COLOR_PAIR(1));
    }
    else
    {
        attron(COLOR_PAIR(2));
        mvprintw(0, 0, "Player 2 wins!");
        attroff(COLOR_PAIR(2));
    }
    refresh();
}

int getChoice(int topBound)
{
    int choice = 0;
    do
    {
        choice = getch() - '0';
    } while (choice > topBound && choice < 1);
    return choice;
}