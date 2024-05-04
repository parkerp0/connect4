#include "engine.hpp"

Engine::Engine()
{
    root = new Node();
    root->boardState = new board();
    root->parent = NULL;
    for(int i = 0; i < 7; i++)
    {
        root->children[i] = NULL;
    }

}

Engine::~Engine()
{
    delete root;
}


board* Engine::getBoardState()
{
    return root->boardState;
}

// void Engine::insert(board *boardState, board *parent, int index)
// {
//     Node *temp = find(parent);
//     Node *newNode = new Node(boardState,temp);
//     newNode->parent->children[index] = newNode;
// }

board* Engine::registerMove()
{
    int index = root->boardState->getHighlightColumn();
    root = root->children[index];
    root->parent->children[index] = NULL;//this is to prevent the tree from being deleted when the root is deleted
    delete root->parent;
    root->parent = NULL;
    return root->boardState;
}


Engine::Node::Node()
{
    //TODO: write node default constructor
}

Engine::Node::Node(board *boardState,Node *parent)
{
    this->boardState = boardState;
    this->parent = parent;
    for(int i = 0; i < 7; i++)
    {
        children[i] = NULL;
    }
    evaluation = 0;
    invalid = 0;
}

Engine::Node::~Node()
{
    delete boardState;
    for(int i = 0; i < 7; i++)
    {
        if(children[i] != NULL)
            delete children[i];
    }
}

void Engine::nodeInsert(Node *parent, board *boardState, int index)
{
    parent->children[index] = new Node(boardState,parent);
}

int evaluate(board *boardState)//the engine will also be player 2
{//engine will be the maximizer and player will be the minimizer
    int win = boardState->checkWin();//returns 0 if the position is still open
    if(win)return (win == 2)? INT_MAX : INT_MIN;

    int tripleDif = boardState->countOpenTripleEnds(2) - boardState->countOpenTripleEnds(1);
    int doubleDif = boardState->countOpenDoubleEnds(2) - boardState->countOpenDoubleEnds(1);

    return tripleDif*TRIPLE_WEIGHT + doubleDif*DOUBLE_WEIGHT;//allows for the board evaluation to be tuned by changing the weights
}

// void Engine::updateEvaluation(board *boardState)
// {
//     Node *temp = find(boardState);
//     evaluateCascade(temp,0);
// }

void Engine::evaluateCascade(Node *node,int depth)
{//evaluates a tree up to a certain depth to make a descion

    if(depth == maxDepth)
    {//if the max depth is reached evaluate the board without considering the future
        node->evaluation = evaluate(node->boardState);
        return;
    }

    //if not at max depth evalute the children 
    int average = 0;
    for(int i = 0; i < 7; i++)
    {

        if(node->children[i] == NULL)
        {
            int dropState;
            board *temp = new board(node->boardState,(node->boardState->getTurn() == 1)?2:1);
            dropState = temp->drop(i,node->boardState->getTurn());//if the move is invalid
            nodeInsert(node,temp,i);
            if(dropState == -1)
            {
                node->children[i]->evaluation = 0;//if the move is invalid set eval to 0 so it does not move the average
                node->children[i]->invalid = 1;
            }else // if the move is valid evaluate the child
                evaluateCascade(node->children[i],depth+1);
        }
        else if(!node->children[i]->invalid)//if not invalid evaluate the child with cascade
        {
            evaluateCascade(node->children[i],depth+1);
            average += node->children[i]->evaluation;
        }
    }
    node->evaluation = average/7;
}

board* Engine::findMove()
{
    evaluateCascade(root,0);
    int max = INT_MIN;
    for(int i = 0; i < 7; i++)
    {
        if(root->children[i]->evaluation > max)
        {
            max = root->children[i]->evaluation;
        }
    }
    return registerMove(max);
}

board* Engine::registerMove(int index)
{
    //trimTree(index);
    root = root->children[index];
    root->parent->children[index] = NULL;//this is to prevent the tree from being deleted when the root is deleted
    delete root->parent;
    root->parent = NULL;
    return root->boardState;
}