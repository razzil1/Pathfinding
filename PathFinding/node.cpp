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
            qDebug() << "Boji u plavo";
            qDebug() << m_x;
            qDebug() << m_y;
            m_brush = QBrush(Qt::blue);
            break;
        case 'l':
            m_brush = QBrush(Qt::lightGray);
            break;
    }
}

float Node::getG() const
{
    return m_g;
}

void Node::setG(float g)
{
    m_g = g;
}

int Node::getX() const
{
    return m_x;
}

int Node::getY() const
{
    return m_y;
}

void Node::setF(int f)
{
    m_f = f;
}

int Node::getF() const
{
    return m_f;
}

Node* Node::getParent() const
{
    return m_parent;
}

void Node::setParent(Node *p)
{
    m_parent = p;
}
