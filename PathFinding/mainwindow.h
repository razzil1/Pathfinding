#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "grid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startRadioButton_clicked();
    void on_endRadioButton_clicked();
    void on_wallRadioButton_clicked();

    void on_findPathButton_clicked();
    void on_clearPathButton_clicked();


private:
    Ui::MainWindow *ui;
    Grid *scene;
    QGraphicsRectItem *rectangle1;
    QGraphicsRectItem *rectangle2;
};

#endif // MAINWINDOW_H
