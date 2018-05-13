#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "grid.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Grid(ui->graphicsView);
    scene->setSceneRect(0, 0, 10, 10);


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
