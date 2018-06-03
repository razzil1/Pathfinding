#include "dijkstra.h"
#include"node.h"
#include <climits>
#include <math.h>

dijkstra::dijkstra(Grid &grid)
{
    m_grid = &grid;
}

void dijkstra::execute()
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            Node *tmp = m_grid->getNode(i,j);
            tmp->setG(INT_MAX);
            m_q.push_back(tmp);
        }
    }
    Node *startNode = m_grid->getStartNode();
    startNode->setG(0);

    while(!m_q.empty())
    {
        Node* n = m_q[0];

        for(unsigned int i=1;i<m_q.size();i++)
        {
            if(n->getG() > m_q[i]->getG())
            {
                n = m_q[i];
            }
        }

        popNode(*n);

        Node* endNode = m_grid->getEndNode();

        if (n->getX() == endNode->getX() && n->getY() == endNode->getY())
        {
            drawPath(*n);
            return;
        }
        std::vector<Node*> neighbourNodes = getNeighbourNodes(*n);
        for(unsigned int i=0; i<neighbourNodes.size(); i++)
        {
            neighbourNodes[i]->setBrush('b');
        }

    }
}

std::vector<Node*> dijkstra::getNeighbourNodes(Node &node)
{
    Node* tmp;
    std::vector<Node*> returnVector;
    int x = int(node.getX()/20);
    int y = int(node.getY()/20);
    if( x == 0 && y == 0) {
        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x+1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (x == 0 && y == 25) {
        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x+1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (x == 25 && y == 0) {
        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (x == 25 && y == 25) {
        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x-1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (x == 0) {
        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x+1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x+1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (y == 0) {
        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x-1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x+1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (x == 25) {
        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else if (y == 25) {
        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x+1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    } else {
        tmp = m_grid->getNode(x+1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+1){
                tmp->setG(node.getG()+1);
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }

        tmp = m_grid->getNode(x-1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x+1,y-1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x-1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
        tmp = m_grid->getNode(x+1,y+1);
        if(!tmp->isWall){
            if(tmp->getG() > node.getG()+sqrt(2)){
                tmp->setG(node.getG()+sqrt(2));
                tmp->setParent(&node);
            }
            returnVector.push_back(tmp);
        }
    }

    m_grid->drawGrid();
    return returnVector;
}

void dijkstra::popNode(Node &n)
{
    int nodeToErase = -1;
    for (unsigned int i = 0; i < m_q.size(); i++){
        if (m_q[i]->getX() == n.getX() && m_q[i]->getY() == n.getY())
        {
            nodeToErase = i;
        }
    }
    if (nodeToErase != -1)
    {
        m_q.erase(m_q.begin() + nodeToErase);
    }
}

void dijkstra::drawPath(Node &node)
{
    Node* parent = node.getParent();
    node.setBrush('r');
    while(parent)
    {
        parent->setBrush('l');
        parent = parent->getParent();
    }
    Node* startNode = m_grid->getStartNode();
    startNode->setBrush('g');
    m_grid->drawGrid();
}

