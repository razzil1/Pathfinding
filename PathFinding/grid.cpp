#include "grid.h"


Grid::Grid()
{

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
    m_start[0] = 0;
    m_start[1] = 0;
    m_end[0] = 25;
    m_end[1] = 25;
    m_grid[0][0].setBrush('g');
    m_grid[25][25].setBrush('r');

    drawGrid();
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


    m_grid[x][y].setBrush(m_color);

    if (m_color == 'g') {
        m_grid[m_start[0]][m_start[1]].setBrush('w');
        setStart(x, y);
    }

    if (m_color == 'r') {
        m_grid[m_end[0]][m_end[1]].setBrush('w');
        setEnd(x, y);
    }

    drawGrid();
}

void Grid::setColor(const char c)
{
    m_color = c;
}

void Grid::setStart(const int x, const int y)
{
    m_start[0] = x;
    m_start[1] = y;
}

void Grid::setEnd(const int x, const int y)
{
    m_end[0] = x;
    m_end[1] = y;
}

void Grid::drawGrid()
{
    this->clear();
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

Node* Grid::getStartNode()
{
    return &m_grid[m_start[0]][m_start[1]];
}

Node* Grid::getEndNode()
{
    return &m_grid[m_end[0]][m_end[1]];
}

Node* Grid::getNode(int x, int y) const
{
    return &m_grid[y][x];
}

void Grid::clearPath()
{
    for(int i = 0; i < m_width; i++)
    {
        for(int j = 0; j < m_height; j++)
        {
            m_grid[i][j].setBrush('w');
            m_grid[i][j].setParent(NULL);
        }
    }
    Node* startNode = getStartNode();
    startNode->setBrush('g');
    Node* endNode = getEndNode();
    endNode->setBrush('r');
}
