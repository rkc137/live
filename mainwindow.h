#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
//#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QTime>
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QUrl>
#include <stdlib.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene *scena;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent* event);
    static const int map_weith = 180, map_heigth = 80;
    QGraphicsRectItem *map[map_weith][map_heigth];
    int size = 5;
    int kadr = 100;
    int kol1, kol2, kol3, kol4;
    bool **livmap;
    bool **livmap_old;
    bool stop = 0;

private:
    Ui::MainWindow *ui;
public slots:
    void kadrs();
    void pos1();
    void pos2();
    void pos3();
    void pos4();
    void us1();
    void us2();
    void Zaderzh();
    void output();
    void vol();
    void clr();
    void stopF();
    void exit();
};

#endif // MAINWINDOW_H

