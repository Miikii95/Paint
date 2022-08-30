#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_colorbox_currentIndexChanged(int index)
{
    ui->widget->setColor(index);
}

void MainWindow::on_brushbox_currentIndexChanged(int index)
{
    ui->widget->setBrush(index);
}

void MainWindow::on_figurebox_currentIndexChanged(int index)
{
    ui->widget->setfigure(index);
    if(index==0||index==3)
    {
        ui->brushbox->setEnabled(0);
    }
    else
    {
        ui->brushbox->setEnabled(1);
    }
}

void MainWindow::on_eraser_clicked()
{
    ui->widget->delateLast();
}

void MainWindow::on_zombiemaker_clicked()
{
    ui->widget->bringBackToLiveLastElement();
}
