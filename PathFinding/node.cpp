#include "node.h"

Node::Node()
{
}

Node::Node(int x, int y, char c)
    : m_x(x), m_y(y), m_color(c)
{
    m_item = QRectF(x, y, 20, 20);
    this->setBrush(c);
}

QRectF Node::getItem() const
{
    return m_item;
}

QBrush Node::getBrush() const
{
    return m_brush;
}

void Node::setBrush(char c)
{
    switch(c){
        case 'w':
            m_brush = QBrush(Qt::white);
             break;
        case 'r':
            m_brush = QBrush(Qt::red);
            break;
        case 'g':
            m_brush = QBrush(Qt::green);
            break;
        case 'b':
            qDebug() << "Boji";
            m_brush = QBrush(Qt::blue);
            break;
    }
}
