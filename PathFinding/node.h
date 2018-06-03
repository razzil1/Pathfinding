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
    void setBrush(char c);
    float getG() const;
    void setG(float g);
    int getX() const;
    int getY() const;
    void setF(int f);
    int getF() const;
    Node* getParent() const;
    void setParent(Node *p);
    bool isWall;
private:
    int m_x;
    int m_y;
    char m_color;
    float m_g;
    int m_f;
    QRectF m_item;
    QBrush m_brush;
    Node* m_parent;
};

#endif // NODE_H
