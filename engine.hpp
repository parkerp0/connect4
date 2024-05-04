#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "board.hpp"
#include <limits>

#define TRIPLE_WEIGHT 100
#define DOUBLE_WEIGHT 10

#define maxDepth 6

#define INT_MAX (std::numeric_limits<int>::max())
#define INT_MIN (std::numeric_limits<int>::min())


class Engine {
    public:
        Engine();
        ~Engine();
        void insert(board *boardState, board *parent, int index);
        board* registerMove();
        board* getBoardState();
        void updateEvaluation(board *boardState);
        //takes the selected move and advances the tree to the next while freeing everything else
        friend int evaluate(board *boardState);
        void printEvaluations();
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
        int size;

        board* registerMove(int index);//takes the selected move of the engine
        void evaluateCascade(Node *node,int depth);
        Node* find(board *boardState);
        void nodeInsert(Node *parent, board *boardState, int index);
};

#endif