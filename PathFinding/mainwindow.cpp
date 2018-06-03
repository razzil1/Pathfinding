#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "grid.h"
#include "astar.h"
#include "dijkstra.h"
#include "bfs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Grid(ui->graphicsView);
    scene->setSceneRect(0, 0, 520, 520);



//    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


//    QPen pen(Qt::black);
//    pen.setWidth(1);



//    scene->addItem(scene->addRect(-260, -210, 20, 20, pen));

//    scene = new Grid(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bla()
{
    qDebug() << ui->graphicsView->width();
    qDebug() << ui->graphicsView->height();

}

void MainWindow::on_radioButton_clicked(bool checked)
{
    scene->setColor('g');
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    scene->setColor('r');
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentIndex() == 0){
        astar *Astar = new astar(*scene);
        Astar->executeAstar();
    } else if (ui->comboBox->currentIndex() == 1) {
        dijkstra *Dijkstra = new dijkstra(*scene);
        Dijkstra->execute();
    } else if (ui->comboBox->currentIndex() == 2) {
        bfs *Bfs = new bfs(*scene);
        Bfs->executeBFS();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    scene->clearPath();
    scene->drawGrid();
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
    scene->setColor('z');
}
