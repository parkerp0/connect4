#include "printer.hpp"
#include "engine.hpp"
#include "board.hpp"
#include <chrono>
#include <thread>

int main()
{
    Engine *engine = new Engine();
    board *currentBoard = engine->getBoardState();
    initPrinter();


    printMenu();
    
    

    while(1)
    {
        currentBoard->print();
        engine->printEvaluations();
        switch(getch())
        {
            case 'a':
                currentBoard->moveHighlight(-1);
            break;

            case 'd':
                currentBoard->moveHighlight(1);
            break;

            case 's':
                if(currentBoard->checkDrop())
                {
                    currentBoard = engine->registerMove();
                    currentBoard->print();
                    engine->printEvaluations();
                    if(currentBoard->checkWin())
                    {
                        printWin(currentBoard->getTurn());
                        return 0;
                    }
                    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    currentBoard = engine->findMove();
                    if(currentBoard->checkWin())
                    {
                        printWin(currentBoard->getTurn());
                        return 0;
                    }
                }
            break;
        }
        // if(currentBoard->checkWin())
        // {
        //     printWin(currentBoard->getTurn());
        //     break;
        // }
    }

    deletePrinter();
}