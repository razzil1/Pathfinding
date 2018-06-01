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
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (x == 0 && y == 25) {
        tmp = m_grid->getNode(x+1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (x == 25 && y == 0) {
        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (x == 25 && y == 25) {
        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (x == 0) {
        tmp = m_grid->getNode(x+1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (y == 0) {
        tmp = m_grid->getNode(x+1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (x == 25) {
        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else if (y == 25) {
        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    } else {
        tmp = m_grid->getNode(x+1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y+1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x,y-1);
        if(tmp->getG() > node.getG()+1)
            tmp->setG(node.getG()+1);
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y-1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x-1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);

        tmp = m_grid->getNode(x+1,y+1);
        if(tmp->getG() > node.getG()+sqrt(2))
            tmp->setG(node.getG()+sqrt(2));
        returnVector.push_back(tmp);
    }

    qDebug() << "Susedi od: " << node.getX() << " " << node.getY() << "\n";
    for(int i = 0; i < returnVector.size(); i++)
        qDebug() << "i: " << returnVector[i]->getX() << " " << returnVector[i]->getY() << "\n";

    return returnVector;
}

