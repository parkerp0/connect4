#include "printer.hpp"
#include "engine.hpp"
#include "board.hpp"

int main()
{
    Engine engine = Engine();
    board *currentBoard = engine.getBoardState();
    initPrinter();


    printMenu();
    
    

    while(1)
    {
        currentBoard = engine.findMove();
        currentBoard->print();
        switch(getch())
        {
            case 'a':
                currentBoard->moveHighlight(-1);
            break;

            case 'd':
                currentBoard->moveHighlight(1);
            break;

            case 's':
                currentBoard = engine.registerMove();
            break;
        }
    }

    deletePrinter();
}