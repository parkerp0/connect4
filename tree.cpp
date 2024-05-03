#include "tree.hpp"

Tree::Tree()
{
    root = new Node();
    root->boardState = new board();
    root->parent = NULL;
    for(int i = 0; i < 7; i++)
    {
        root->children[i] = NULL;
    }
}

Tree::~Tree()
{
    delete root;
}

void Tree::trimTree(int index)
{
    for(int i = 0; i < 7; i++)
    {
        if(i != index && root->children[i] != NULL)
        {
            delete root->children[i];
        }
    }
}
board* Tree::getBoardState()
{
    return root->boardState;
}

void Tree::insert(board *boardState, board *parent, int index)
{
    Node *temp = find(parent);
    Node *newNode = new Node(boardState,temp);
    newNode->parent->children[index] = newNode;
}

void Tree::registerMove(int index)
{
    trimTree(index);
    root = root->children[index];
    delete root->parent;
    root->parent = NULL;
}

Tree::Node::Node()
{
    //TODO: write node default constructor
}

Tree::Node::Node(board *boardState,Node *parent)
{
    this->boardState = boardState;
    this->parent = parent;
    for(int i = 0; i < 7; i++)
    {
        children[i] = NULL;
    }
    evaluation = 0;
    
}

Tree::Node::~Node()
{
    delete boardState;
    for(int i = 0; i < 7; i++)
    {
        if(children[i] != NULL)
            delete children[i];
    }
}

int evaluate(board *boardState)//the engine will also be player 2
{//engine will be the maximizer and player will be the minimizer
    int win = boardState->checkWin();//returns 0 if the position is still open
    if(win)return (win == 2)? INT_MAX : INT_MIN;

    

    return 0;
}