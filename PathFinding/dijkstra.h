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
    void popNode(Node &node);
    void drawPath(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> m_q;
};

#endif // DIJKSTRA_H
