#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "board.hpp"
#include <limits>

#define TRIPLE_WEIGHT 100
#define DOUBLE_WEIGHT 10

#define maxDepth 5

#define INT_MAX (std::numeric_limits<int>::max())
#define INT_MIN (std::numeric_limits<int>::min())


class Engine {
    public:
        Engine();
        ~Engine();
        void insert(board *boardState, board *parent, int index);
        void registerMove(int index);
        board* getBoardState();
        void updateEvaluation(board *boardState);
        //takes the selected move and advances the tree to the next while freeing everything else
        friend int evaluate(board *boardState);
        board* findMove();

    private:
        struct Node {
            Node();
            Node(board *boardState,Node *parent);
            ~Node();
            board *boardState;
            Node *parent;
            Node *children[7];
            int evaluation;
            int invalid;
        };
        Node *root;

        
        void evaluateCascade(Node *node,int depth);
        void trimTree(int index);//clears all nodes except the one at index
        Node* find(board *boardState);
        void nodeInsert(Node *parent, board *boardState, int index);
};

#endif