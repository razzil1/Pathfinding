#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "grid.h"
#include "node.h"

#include <vector>


class dijkstra
{
public:
    dijkstra(Grid &grid);
    void execute();
    std::vector<Node*> getNeighbourNodes(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> m_q;
};

#endif // DIJKSTRA_H
