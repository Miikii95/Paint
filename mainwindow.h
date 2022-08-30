#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include <QMainWindow>

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
    void on_colorbox_currentIndexChanged(int index);

    void on_brushbox_currentIndexChanged(int index);

    void on_figurebox_currentIndexChanged(int index);

    void on_eraser_clicked();

    void on_zombiemaker_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
