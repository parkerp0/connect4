#ifndef TREE_HPP
#define TREE_HPP

#include "board.hpp"
#include <limits>

#define INT_MAX (std::numeric_limits<int>::max())
#define INT_MIN (std::numeric_limits<int>::min())

class Tree {
    public:
        Tree();
        ~Tree();
        void insert(board *boardState, board *parent, int index);
        void registerMove(int index);
        board* getBoardState();
        //takes the selected move and advances the tree to the next while freeing everything else
        friend int evaluate(board *boardState);

    private:
        struct Node {
            Node();
            Node(board *boardState,Node *parent);
            ~Node();
            board *boardState;
            Node *parent;
            Node *children[7];
            int evaluation;
        };
        Node *root;

        

        void trimTree(int index);//clears all nodes except the one at index
        Node* find(board *boardState);
};

#endif