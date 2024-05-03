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
    for(int i = 0; i < 7; i++)
    {
        if(root->children[i] != NULL)
            delete root->children[i];
    }
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
    Node *newNode = new Node();
    newNode->boardState = boardState;
    newNode->parent = find(parent);
    newNode->parent->children[index] = newNode;
}

void Tree::registerMove(int index)
{
    trimTree(index);
    root = root->children[index];
    delete root->parent;
    root->parent = NULL;
}

int evaluate(board *boardState)
{
    //TODO: implement evaluation function
    return 0;
}