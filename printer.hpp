#ifndef printer_hpp
#define printer_hpp

#include <ncurses.h>
#include <cstdlib>

void initPrinter();
void deletePrinter();
int printMenu();
void printBoard(int **field,int highlight);
void printWin(int player);
int getChoice(int topBound);
void printEvals(int *evals, int size);
void printBoardStats(int redWin, int blueWin, int redTriples, int blueTriples, int redDoubles, int blueDoubles,int evaluation);

#endif