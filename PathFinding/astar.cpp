#include "astar.h"
#include <unistd.h>


astar::astar(Grid &grid)
{
   m_grid = &grid;
}

void astar::executeAstar()
{
    closedList.clear();
    openList.clear();

    Node* endNode = m_grid->getEndNode();
    Node* startNode = m_grid->getStartNode();
    startNode->setG(0);
    calculateF(*startNode);
    openList.push_back(startNode);

    while(!openList.empty())
    {
        qDebug() << "While 1";
        int max = 0;
        int maxF = openList[max]->getF();
        for(int i=1; i<openList.size(); i++)
        {
//            qDebug() << "For: trazi cvor sa najblojim f iz openList";
            int tmpF = openList[i]->getF();
            qDebug() << "F: " << openList[i]->getF() << " G: " << openList[i]->getG() << "\n";
            if(tmpF < maxF){
                max = i;
                maxF = tmpF;
            }
        }
        Node* n = openList[max];
        qDebug() << "F: " << n->getF() << " G: " << n->getG() << "\n";
        if (endNode->getX() == n->getX() && endNode->getY() == n->getY())
        {
            qDebug() << "Kraj";
            startNode->setBrush('g');
            break;
        } else
        {
            std::vector<Node*> neigbourNodes = getNeighbourNodes(*n);
            for (int i=0; i<neigbourNodes.size(); i++)
            {
                qDebug() << "For: za svaki susedni cvor ...";
//                neigbourNodes[i]->setBrush('b');
                //sleep(1);
                if (!inOpenList(*neigbourNodes[i]) && !inCloesedList(*neigbourNodes[i]))
                {
                    int g = n->getG()+1;
                    neigbourNodes[i]->setG(g);
                    calculateF(*neigbourNodes[i]);
                    openList.push_back(neigbourNodes[i]);
                } else
                {
                    int newG = n->getG()+1;
                    if (neigbourNodes[i]->getG() > newG)
                    {
                        neigbourNodes[i]->setG(newG);
                        calculateF(*neigbourNodes[i]);
                        if (inCloesedList(*neigbourNodes[i]))
                        {
                            bool flag = true;
                            int nodeToErase1 = -1;
                            for (int t = 0; t < closedList.size(); t++){
                                if (closedList[t]->getX() == neigbourNodes[i]->getX() && closedList[t]->getY() == neigbourNodes[i]->getY() && flag)
                                {
                                    nodeToErase1 = t;
                                    //closedList.erase(closedList.begin() + t);
                                    flag = false;
                                }
                            }
                            closedList.erase(closedList.begin() + nodeToErase1);
                            openList.push_back(neigbourNodes[i]);
                        }
                    }
                }
            }
            bool flag = true;
            int nodeToErase = -1;
            for (int i = 0; i < openList.size(); i++){
                if (openList[i]->getX() == n->getX() && openList[i]->getY() == n->getY() && flag)
                {
                    //openList.erase(openList.begin() + i);
                    nodeToErase = i;
                    flag = false;
                }
            }
            if (nodeToErase != -1)
            {
                openList.erase(openList.begin() + nodeToErase);
            }
            n->setBrush('b');
            closedList.push_back(n);
        }

    }
    qDebug() << "Je l crta";
    m_grid->drawGrid();

}

int astar::calculateF(Node &node)
{
    Node* endNode = m_grid->getEndNode();
    int h = std::abs(node.getX() - endNode->getX()) + std::abs(node.getY() - endNode->getY());
    node.setF(node.getG() + h);
    return node.getF();
}

std::vector<Node*> astar::getNeighbourNodes(Node &node)
{
    std::vector<Node*> returnVector;
    int x = int(node.getX()/20);
    int y = int(node.getY()/20);
    if( x == 0 && y == 0) {
        returnVector.push_back(m_grid->getNode(x+1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
    } else if (x == 0 && y == 25) {
        returnVector.push_back(m_grid->getNode(x+1,y));
        returnVector.push_back(m_grid->getNode(x,y-1));
    } else if (x == 25 && y == 0) {
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
    } else if (x == 25 && y == 25) {
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x,y-1));
    } else if (x == 0) {
        returnVector.push_back(m_grid->getNode(x+1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
        returnVector.push_back(m_grid->getNode(x,y-1));
    } else if (y == 0) {
        returnVector.push_back(m_grid->getNode(x+1,y));
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
    } else if (x == 25) {
        returnVector.push_back(m_grid->getNode(x,y-1));
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
    } else if (y == 25) {
        returnVector.push_back(m_grid->getNode(x,y-1));
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x+1,y));
    } else {
        returnVector.push_back(m_grid->getNode(x+1,y));
        returnVector.push_back(m_grid->getNode(x-1,y));
        returnVector.push_back(m_grid->getNode(x,y+1));
        returnVector.push_back(m_grid->getNode(x,y-1));
    }

    qDebug() << "Susedi od: " << node.getX() << " " << node.getY() << "\n";
    for(int i = 0; i < returnVector.size(); i++)
        qDebug() << "i: " << returnVector[i]->getX() << " " << returnVector[i]->getY() << "\n";

    return returnVector;
}

bool astar::inOpenList(Node &node)
{
    for (int j=0; j<openList.size(); j++)
    {
//        qDebug() << "For: provera da li je u otvorenoj list";
        if (node.getX() == openList[j]->getX() && node.getY() == openList[j]->getY())
        {
            return true;
        }
    }

    return false;
}

bool astar::inCloesedList(Node &node)
{
    for (int j=0; j<closedList.size(); j++)
    {
//        qDebug() << "For: provera da li je u zatvorenoj list list";
        if (node.getX() == closedList[j]->getX() && node.getY() == closedList[j]->getY())
        {
            qDebug() << "vraca true";
            return true;
        }
    }
    qDebug() << "vraca false";
    return false;
}
