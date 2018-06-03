#include "dfs.h"

dfs::dfs(Grid &grid)
{
   m_grid = &grid;
}

void dfs::executeDFS()
{
    Node* endNode = m_grid->getEndNode();
    Node* startNode = m_grid->getStartNode();

    path.push_back(startNode);
    visitedNodes.push_back(startNode);

    while(!path.empty())
    {

        Node* n = path[path.size() - 1];

        std::vector<Node*> neigbourNodes = getNeighbourNodes(*n);
        bool hasUnvisited = false;
        int notVisitedNode;


        for (unsigned int i=0; i<neigbourNodes.size(); i++)
        {
            bool inVisited = false;
            for (unsigned int j = 0; j < visitedNodes.size(); j++)
            {
                if (neigbourNodes[i]->getX() == visitedNodes[j]->getX() && neigbourNodes[i]->getY() == visitedNodes[j]->getY())
                {
                    inVisited = true;
                }
            }
            if (!inVisited)
            {
                notVisitedNode = i;
                hasUnvisited = true;
                break;
            }

        }

        if (endNode->getX() == n->getX() && endNode->getY() == n->getY())
        {

            for(unsigned int i = 0; i < path.size(); i++)
            {
                path[i]->setBrush('l');
            }

            startNode->setBrush('g');
            endNode->setBrush('r');
            m_grid->drawGrid();

            break;
        } else if (!hasUnvisited)
        {
            path.pop_back();
        }
        else
        {
            Node* m = neigbourNodes[notVisitedNode];
            path.push_back(m);
            visitedNodes.push_back(m);
        }
    }
}

std::vector<Node*> dfs::getNeighbourNodes(Node &node)
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
