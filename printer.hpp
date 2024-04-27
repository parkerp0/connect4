#ifndef printer_hpp
#define printer_hpp

#include <ncurses.h>
#include <cstdlib>

void initPrinter();
void deletePrinter();
int printMenu();
void printBoard(int **field);
void printWin(int player);


#endif