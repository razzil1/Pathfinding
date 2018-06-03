#include "bfs.h"

bfs::bfs(Grid &grid)
{
   m_grid = &grid;
}

void bfs::executeBFS()
{


    Node* endNode = m_grid->getEndNode();
    Node* startNode = m_grid->getStartNode();
    startNode->setParent(endNode);

    openList.push_back(startNode);

    while(!openList.empty())
    {

        Node* n = openList[0];
        openList.erase(openList.begin());

        if (endNode->getX() == n->getX() && endNode->getY() == n->getY())
        {
            qDebug() << "Kraj!" << "\n";
            startNode->setParent(NULL);
            drawPath(*n);
            startNode->setBrush('g');
            break;
        } else
        {
            std::vector<Node*> neigbourNodes = getNeighbourNodes(*n);
            for (int i=0; i<neigbourNodes.size(); i++)
            {
                neigbourNodes[i]->setBrush('b');
                if (!neigbourNodes[i]->getParent())
                {
                    neigbourNodes[i]->setParent(n);
                    openList.push_back(neigbourNodes[i]);
                }
            }
        }
    }
}

std::vector<Node*> bfs::getNeighbourNodes(Node &node)
{
    Node* tmp;
    std::vector<Node*> returnVector;
    int x = int(node.getX()/20);
    int y = int(node.getY()/20);
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

void bfs::drawPath(Node &node)
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
