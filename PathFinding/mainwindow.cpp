#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_radioButton_clicked()
{
    scene->setColor('g');
}

void MainWindow::on_radioButton_2_clicked()
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
    } else if (ui->comboBox->currentIndex() == 3) {
        dfs *Dfs = new dfs(*scene);
        Dfs->executeDFS();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    scene->clearPath();
    scene->drawGrid();
}

void MainWindow::on_radioButton_3_clicked()
{
    scene->setColor('z');
}
