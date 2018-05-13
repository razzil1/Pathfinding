#ifndef GRID_H
#define GRID_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>
#include <math.h>

#include "node.h"

class Grid: public QGraphicsScene
{
public:
    Grid(QObject * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
protected:
private:
    Node **m_grid;
    const int m_width = 26;
    const int m_height = 26;
};

#endif // GRID_H
