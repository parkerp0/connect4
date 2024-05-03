#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "board.hpp"
#include "tree.hpp"
class engine
{
    public:
        engine();
        ~engine();
        int pickMove(board *boardInstance);
    private:
        Tree *tree;
};

#endif