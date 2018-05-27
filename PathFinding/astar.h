#ifndef ASTAR_H
#define ASTAR_H
#include "grid.h"
#include <vector>

class astar
{
public:
    astar(Grid &grid);
    void executeAstar();
    int calculateF(Node &node);
    int calculateG(Node &node);
    int calculateH(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> openList;
    std::vector<Node*> closedList;

};

#endif // ASTAR_H
