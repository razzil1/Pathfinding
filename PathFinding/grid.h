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
    void setColor(const char c);
    void setStart(const int x, const int y);
    void setEnd(const int x, const int y);
protected:
    void drawGrid();
private:
    Node **m_grid;
    const int m_width = 26;
    const int m_height = 26;
    int m_start[2];
    int m_end[2];
    char m_color;
};

#endif // GRID_H
