#ifndef ASTAR_H
#define ASTAR_H
#include "grid.h"
#include "node.h"
#include <vector>

class astar
{
public:
    astar(Grid &grid);
    void executeAstar();
    int calculateF(Node &node);
    int calculateG(Node &node);
    int calculateH(Node &node);
    std::vector<Node*> getNeighbourNodes(Node &node);
    bool inOpenList(Node &node);
    bool inCloesedList(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> openList;
    std::vector<Node*> closedList;

};

#endif // ASTAR_H
