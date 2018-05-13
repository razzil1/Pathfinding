#ifndef GRID_H
#define GRID_H

#include <QGraphicsScene>

#include "node.h"

class Grid: public QGraphicsScene
{
public:
    Grid(QObject * parent = 0);
protected:
private:
    Node **m_grid;
    const int m_width = 26;
    const int m_height = 26;
};

#endif // GRID_H
