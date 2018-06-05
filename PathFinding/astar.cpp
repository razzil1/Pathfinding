#include "astar.h"
#include <unistd.h>


astar::astar(Grid &grid)
{
   m_grid = &grid;
}

void astar::executeAstar()
{
    closedList.clear();
    openList.clear();

    Node* endNode = m_grid->getEndNode();
    Node* startNode = m_grid->getStartNode();
    startNode->setG(0);
    calculateF(*startNode);
    openList.push_back(startNode);

    while(!openList.empty())
    {
        int indeksOfBest = 0;
        int bestF = openList[indeksOfBest]->getF();
        for(unsigned int i=1; i<openList.size(); i++)
        {
            int tmpF = openList[i]->getF();
            if(tmpF < bestF){
                indeksOfBest = i;
                bestF = tmpF;
            }
        }
        Node* n = openList[indeksOfBest];
        if (endNode->getX() == n->getX() && endNode->getY() == n->getY())
        {
            drawPath(*n);

            break;
        } else
        {
            std::vector<Node*> neigbourNodes = getNeighbourNodes(*n);
            for (unsigned int i=0; i<neigbourNodes.size(); i++)
            {
                if (!inOpenList(*neigbourNodes[i]) && !inCloesedList(*neigbourNodes[i]))
                {
                    int g = n->getG()+1;
                    neigbourNodes[i]->setG(g);
                    calculateF(*neigbourNodes[i]);
                    neigbourNodes[i]->setBrush('b');
                    openList.push_back(neigbourNodes[i]);
                    neigbourNodes[i]->setParent(n);
                } else
                {
                    int newG = n->getG()+1;
                    if (newG < neigbourNodes[i]->getG())
                    {
                        neigbourNodes[i]->setG(newG);
                        calculateF(*neigbourNodes[i]);
                        neigbourNodes[i]->setParent(n);
                        if (inCloesedList(*neigbourNodes[i]))
                        {
                            for (unsigned int t = 0; t < closedList.size(); t++)
                            {
                                if (closedList[t]->getX() == neigbourNodes[i]->getX() && closedList[t]->getY() == neigbourNodes[i]->getY())
                                {
                                    closedList.erase(closedList.begin() + t);
                                    break;
                                }
                            }
                            openList.push_back(neigbourNodes[i]);
                        }
                    }
                }
            }


            for (unsigned int i = 0; i < openList.size(); i++)
            {

                if (openList[i]->getX() == n->getX() && openList[i]->getY() == n->getY())
                {

                    openList.erase(openList.begin() + i);

                    break;
                }
            }
            closedList.push_back(n);
        }

    }
    m_grid->drawGrid();

}

int astar::calculateF(Node &node)
{
    Node* endNode = m_grid->getEndNode();
    int h = std::abs(node.getX() - endNode->getX()) + std::abs(node.getY() - endNode->getY());
    node.setF(node.getG() + h);
    return node.getF();
}

std::vector<Node*> astar::getNeighbourNodes(Node &node)
{
    Node* tmp;
    std::vector<Node*> returnVector;
    int x = node.getX()/20;
    int y = node.getY()/20;
    if( x == 0 && y == 0) {
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (x == 0 && y == 25) {
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (x == 25 && y == 0) {
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (x == 25 && y == 25) {
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (x == 0) {
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (y == 0) {
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (x == 25) {
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else if (y == 25) {
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    } else {
        tmp = m_grid->getNode(x+1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y+1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x,y-1);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
        tmp = m_grid->getNode(x-1,y);
        if (!tmp->isWall)
            returnVector.push_back(tmp);
    }

    return returnVector;
}

bool astar::inOpenList(Node &node)
{
    for (unsigned int j=0; j<openList.size(); j++)
    {
        if (node.getX() == openList[j]->getX() && node.getY() == openList[j]->getY())
        {
            return true;
        }
    }

    return false;
}

bool astar::inCloesedList(Node &node)
{
    for (unsigned int j=0; j<closedList.size(); j++)
    {
        if (node.getX() == closedList[j]->getX() && node.getY() == closedList[j]->getY())
        {
            return true;
        }
    }
    return false;
}

void astar::drawPath(Node &node)
{
    Node* parent = node.getParent();
    node.setBrush('r');

    while(parent->getParent())
    {
        parent->setBrush('l');
        parent = parent->getParent();
    }
}
