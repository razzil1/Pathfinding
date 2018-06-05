#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ctime>
#include <sstream>
#include <sys/time.h>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "grid.h"
#include "astar.h"
#include "dijkstra.h"
#include "bfs.h"
#include "dfs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Grid();
    scene->setSceneRect(0, 0, 520, 520);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startRadioButton_clicked()
{
    scene->setColor('g');
}

void MainWindow::on_endRadioButton_clicked()
{
    scene->setColor('r');
}

void MainWindow::on_wallRadioButton_clicked()
{
    scene->setColor('z');
}


void MainWindow::on_findPathButton_clicked()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms_s = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    if(ui->comboBox->currentIndex() == 0){
        astar *Astar = new astar(*scene);
        Astar->executeAstar();
    } else if (ui->comboBox->currentIndex() == 1) {
        dijkstra *Dijkstra = new dijkstra(*scene);
        Dijkstra->execute();
    } else if (ui->comboBox->currentIndex() == 2) {
        bfs *Bfs = new bfs(*scene);
        Bfs->executeBFS();
    } else if (ui->comboBox->currentIndex() == 3) {
        dfs *Dfs = new dfs(*scene);
        Dfs->executeDFS();
    }
    gettimeofday(&tp, NULL);
    long int ms_e = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    int diff = ms_e-ms_s;
    std::string s;
    std::stringstream out;
    out << diff;
    s = out.str();
    QString qstr = QString::fromStdString("Time: "+s+"ms");
    ui->label->setText(qstr);
}

void MainWindow::on_clearPathButton_clicked()
{
    scene->clearPath();
    scene->drawGrid();
    ui->label->setText("");
}


void MainWindow::on_importButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Open file"),
                    "C://",
                    "All files (*.*);;Text files (*.txt)"
                    );

        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly))
            ui->label->setText("Error!");

        QTextStream in(&file);

        unsigned int i, j;
        char color;

        while(!in.atEnd())
        {
           QString line = in.readLine();
           QStringList fields = line.split(" ");
           j = fields[0].toInt();
           i = fields[1].toInt();
           color = fields[2][0].toLatin1();

           Node* node = scene->getNode(i, j);
           node->setBrush(color);

           if (color == 'g')
           {
               scene->setStart(j, i);
           }
           else if(color == 'r')
           {
               scene->setEnd(j, i);
           }
           else if (color == 'z')
           {
               node->isWall = true;
           }


        }

        scene->drawGrid();
}
