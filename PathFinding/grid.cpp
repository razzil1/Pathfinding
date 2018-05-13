#include "grid.h"


Grid::Grid(QObject * parent)
{

    this->setSceneRect(0, 0, 0, 0);

    m_grid = new Node *[m_width];
    for(int i = 0; i < m_width; i++)
        m_grid[i] = new Node [m_height];

    int upperLeftY = -210;

    for(int i = 0; i < m_width; i++)
    {
        int upperLeftX = -260;
        for(int j = 0; j < m_height; j++)
        {
            m_grid[i][j] = Node(upperLeftX ,upperLeftY, 'w');
            upperLeftX += 20;
        }
        upperLeftY += 20;
    }

    for(int i = 0; i < m_width; i++)
    {
        for(int j = 0; j < m_height; j++)
        {
            QPen pen(Qt::black);
            pen.setWidth(1);
            this->addRect(m_grid[i][j].getItem(),pen, m_grid[i][j].getBrush());
        }
    }
}
