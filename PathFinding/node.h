#ifndef NODE_H
#define NODE_H

#include <QRectF>
#include <QBrush>

class Node
{
public:
    Node();
    Node(int x, int y, char c);
    QRectF getItem() const;
    QBrush getBrush() const;
private:
    int m_x;
    int m_y;
    char m_color;
    QRectF m_item;
    QBrush m_brush;
};

#endif // NODE_H
