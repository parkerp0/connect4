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

#endif