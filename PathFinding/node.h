#ifndef NODE_H
#define NODE_H

#include <QRectF>
#include <QBrush>
#include <QDebug>

class Node
{
public:
    Node();
    Node(int x, int y, char c);
    QRectF getItem() const;
    QBrush getBrush() const;
    void setBrush(char c);
private:
    int m_x;
    int m_y;
    char m_color;
    QRectF m_item;
    QBrush m_brush;
};

#endif // NODE_H
