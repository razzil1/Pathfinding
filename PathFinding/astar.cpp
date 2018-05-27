#include "astar.h"

astar::astar(Grid &grid)
{
   m_grid = &grid;
}

void astar::executeAstar()
{
    closedList.clear();
    openList.clear();

    openList.push_back(m_grid->getStartNode());

    while(!openList.empty())
    {

    }
}

int astar::calculateG(Node &node)
{
    return
}
