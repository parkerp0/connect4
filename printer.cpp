#include "printer.hpp"

void initPrinter()
{//if there is a lot more time at the end/doubt it switch over to openGL for graphics
    initscr();
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    init_pair(4, COLOR_BLUE, COLOR_WHITE);

}
void deltePrinter()
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
    mvprintw(2, 0, "1. Play against AI");
    mvprintw(3, 0, "2. Online multiplayer");
    mvprintw(4, 0, "3. Quit");
    refresh();
    return getChoice(3);
}
void printBoard(int **field)
{

}
void printWin(int player)
{

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