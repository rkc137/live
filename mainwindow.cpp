#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("live"));
    scena = new QGraphicsScene;
    scena->setSceneRect(1, 1, 900, 400);
    QMessageBox::warning(this, "", "plz use button below to exit\n");
    ui->graphicsView->setScene(scena);
    connect(ui->pos1, SIGNAL(clicked(bool)), this, SLOT(pos1()));
    connect(ui->pos2, SIGNAL(clicked(bool)), this, SLOT(pos2()));
    connect(ui->pos3, SIGNAL(clicked(bool)), this, SLOT(pos3()));
    connect(ui->pos4, SIGNAL(clicked(bool)), this, SLOT(pos4()));
    connect(ui->rule1, SIGNAL(clicked(bool)), this, SLOT(us1()));
    connect(ui->rule2, SIGNAL(clicked(bool)), this, SLOT(us2()));
    connect(ui->exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    connect(ui->pause, SIGNAL(clicked(bool)), this, SLOT(stopF()));
    connect(ui->clr, SIGNAL(clicked(bool)), this, SLOT(clr()));
    connect(ui->kadr1, SIGNAL(clicked(bool)), this, SLOT(kadrs()));
    vol();
    for(int i = 0; i < map_weith; i++)
    {
        for(int j = 0; j < map_heigth; j++)
        {
                map[i][j] = new QGraphicsRectItem (i * size, j * size, size, size);
                map[i][j]->setBrush(QBrush(QColor(0, 0, 0)));
                scena->addItem(map[i][j]);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    vol();
    int x, y, i, j;
    for (i = 0; i < map_weith + 2; i++)
    {
        for(j = 0; j < map_heigth + 2; j++)
        {
            livmap[i][j] = livmap_old[i][j];
        }
    }
    x = (event->x() / size) - 1;
    y = (event->y() / size) - 1;
    livmap[x][y] = !livmap[x][y];
    output();
}

void MainWindow::vol()
{
    int i, j;
    livmap_old = livmap;
    livmap = new bool*[map_weith + 2];
    for (i = 0; i < map_weith + 2; i++)
    {
        livmap[i] = new bool[map_heigth + 2];
        for(j = 0; j < map_heigth + 2; j++)
        {
            livmap[i][j] = 0;
        }
    }
}

void MainWindow::pos1()
{
    vol();
    livmap[45][19] = 1;
    livmap[45][20] = 1;
    livmap[45][21] = 1;
    livmap[46][19] = 1;
    livmap[44][20] = 1;
    output();
}

void MainWindow::pos2()
{
    vol();
    livmap[1][13] = 1;
    livmap[2][14] = 1;
    livmap[3][14] = 1;
    livmap[4][14] = 1;
    livmap[5][14] = 1;
    livmap[5][13] = 1;
    livmap[5][12] = 1;
    livmap[4][11] = 1;
    Zaderzh();
    output();
}

void MainWindow::pos3()
{
    vol();
    livmap[22][23] = 1;
    livmap[23][23] = 1;
    livmap[22][24] = 1;
    livmap[23][24] = 1;

    livmap[32][23] = 1;
    livmap[32][24] = 1;
    livmap[32][25] = 1;
    livmap[33][26] = 1;
    livmap[33][22] = 1;
    livmap[34][27] = 1;
    livmap[35][27] = 1;
    livmap[34][21] = 1;
    livmap[35][21] = 1;

    livmap[36][24] = 1;
    livmap[37][26] = 1;
    livmap[38][25] = 1;
    livmap[38][24] = 1;
    livmap[38][23] = 1;
    livmap[37][22] = 1;
    livmap[39][24] = 1;

    livmap[43][22] = 1;
    livmap[42][23] = 1;
    livmap[42][22] = 1;
    livmap[43][23] = 1;
    livmap[42][21] = 1;
    livmap[43][21] = 1;

    livmap[44][20] = 1;
    livmap[44][24] = 1;
    livmap[46][20] = 1;
    livmap[46][19] = 1;
    livmap[46][24] = 1;
    livmap[46][25] = 1;

    livmap[56][21] = 1;
    livmap[56][22] = 1;
    livmap[57][21] = 1;
    livmap[57][22] = 1;
    output();
}

void MainWindow::pos4()
{
    vol();
    livmap[1][3] = 1;
    livmap[2][3] = 1;
    livmap[3][3] = 1;
    livmap[3][2] = 1;
    livmap[2][1] = 1;
    output();
}

void MainWindow::us1()
{
    int i, j, chek;
    stop = 0;
    while(stop == 0)
    {
        vol();
        for(i = 1; i <= map_weith; i++)
        {
            for(j = 1; j <= map_heigth; j++)
            {
                chek = livmap_old[i - 1][j - 1] + livmap_old[i - 1][j] + livmap_old[i - 1][j + 1] + livmap_old[i][j - 1] + livmap_old[i][j + 1] + livmap_old[i + 1][j - 1] + livmap_old[i + 1][j] + livmap_old[i + 1][j + 1];
                if((chek == 2 || chek == 3) && livmap_old[i][j] == 1)
                {
                    livmap[i][j] = 1;
                }
                else if(chek == 3 && (livmap_old[i][j] == 0))
                {
                    livmap[i][j] = 1;
                }
                else if((chek < 2 || chek > 3) && livmap_old[i][j] == 1)
                {
                    livmap[i][j] = 0;
                }
            }
        }
        Zaderzh();
        scena->update();
        output();
    }
}

void MainWindow::us2()
{
    int i, j, chek;
    stop = 0;
    while(stop == 0)
    {
        vol();
        for(i = 1; i <= map_weith; i++)
        {
            for(j = 1; j <= map_heigth; j++)
            {
                chek = livmap_old[i - 1][j - 1] + livmap_old[i - 1][j] + livmap_old[i - 1][j + 1] + livmap_old[i][j - 1] + livmap_old[i][j + 1] + livmap_old[i + 1][j - 1] + livmap_old[i + 1][j] + livmap_old[i + 1][j + 1];
                if(chek == 2 || chek == 3)
                {
                    livmap[i][j] = 1;
                }
                else if(chek < 2 || chek > 3)
                {
                    livmap[i][j] = 0;
                }
            }
        }
        Zaderzh();
        scena->update();
        output();
    }
}

void MainWindow::output()
{
    int i, j;
    for (i = 1; i <= map_weith; i++)
    {
        for(j = 1; j <= map_heigth; j++)
        {
            if(livmap[i][j] != livmap_old[i][j])
            {
                if(livmap[i][j] == 1)
                {
                    map[i - 1][j - 1]->setBrush(QBrush(QColor(255, 255, 255)));
                }
                else
                {
                    map[i - 1][j - 1]->setBrush(QBrush(QColor(0, 0, 0)));
                }
            }
        }
     }
}

void MainWindow::Zaderzh()
{
    QTime Zaderzh;
    Zaderzh.start();
    for(;Zaderzh.elapsed() < kadr;)
        qApp->processEvents();
}

void MainWindow::kadrs()
{
    kadr = ui->lineEdit->text().toInt();
}

void MainWindow::clr()
{
    stop = 1;
    for(int i = 0; i < map_weith; i++)
    {
        for(int j = 0; j < map_heigth; j++)
        {
                livmap[i][j] = 0;
        }
    }
    output();
}

void MainWindow::stopF()
{
    stop = !stop;
}

void MainWindow::exit()
{
    stop = 1;
    QApplication::exit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
