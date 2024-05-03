#ifndef TREE_HPP
#define TREE_HPP

#include "board.hpp"

class Tree {
    public:
        Tree();
        ~Tree();
        void insert(board *boardState, board *parent, int index);
        void registerMove(int index);
        board* getBoardState();
        //takes the selected move and advances the tree to the next while freeing everything else


    private:
        struct Node {
            Node();
            ~Node();
            board *boardState;
            Node *parent;
            Node *children[7];
        };
        Node *root;

        void trimTree(int index);//clears all nodes except the one at index
        Node* find(board *boardState);
}

#endif