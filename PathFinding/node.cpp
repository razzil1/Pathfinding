#include "node.h"

Node::Node()
{
}

Node::Node(int x, int y, char c)
    : m_x(x), m_y(y), m_color(c)
{
    m_item = QRectF(x, y, 20, 20);
    m_brush = QBrush(Qt::white);
}

QRectF Node::getItem() const
{
    return m_item;
}

QBrush Node::getBrush() const
{
    return m_brush;
}
