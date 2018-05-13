#include "grid.h"


Grid::Grid(QObject * parent)
{
   //this->setSceneRect(0, 0, 0, 0);

    m_grid = new Node *[m_width];
    for(int i = 0; i < m_width; i++)
        m_grid[i] = new Node [m_height];

    int upperLeftY = 0;

    for(int i = 0; i < m_width; i++)
    {
        int upperLeftX = 0;
        for(int j = 0; j < m_height; j++)
        {
            m_grid[i][j] = Node(upperLeftX ,upperLeftY, 'w');
            upperLeftX += 20;
        }
        upperLeftY += 20;
    }

    m_grid[0][0].setBrush('g');
    m_grid[25][25].setBrush('r');

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

void Grid::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QPointF position;
    int posX, posY;
    int x, y;

    position = event->buttonDownScenePos(Qt::LeftButton);

    posX = position.toPoint().x();
    posY = position.toPoint().y();

    y = floor(posX / 20);
    x = floor(posY / 20);

    m_grid[x][y].setBrush('b');

    qDebug() << "Test!";
    qDebug() << posX << ' ' << x;
    qDebug() << posY << ' ' << y;

    update();
    QPen pen(Qt::black);
    this->addRect(m_grid[x][y].getItem(),pen, m_grid[x][y].getBrush());
}
