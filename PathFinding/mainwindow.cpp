#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen pen(Qt::black);
    pen.setWidth(1);

    scene->setSceneRect(0, 0, 10, 10);

    scene->addItem(scene->addRect(-260, -210, 20, 20, pen));
}

MainWindow::~MainWindow()
{
    delete ui;
}
