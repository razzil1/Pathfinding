#ifndef BFS_H
#define BFS_H
#include "grid.h"
#include "node.h"
#include <vector>


class bfs
{
public:
    bfs(Grid &grid);
    void executeBFS();
    void drawPath(Node &node);
    std::vector<Node*> getNeighbourNodes(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> openList;
};

#endif // BFS_H
