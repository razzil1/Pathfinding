#ifndef DFS_H
#define DFS_H
#include "grid.h"
#include "node.h"
#include <vector>



class dfs
{
public:
    dfs(Grid &grid);
    void executeDFS();
    void drawPath(Node &node);
    std::vector<Node*> getNeighbourNodes(Node &node);
private:
    Grid *m_grid;
    std::vector<Node*> path;
    std::vector<Node*> visitedNodes;
};

#endif // DFS_H
