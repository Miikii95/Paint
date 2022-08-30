#ifndef MYPAINT
#define MYPAINT
#include <QColorDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class figure
{
public:
    virtual void draw(QPainter & painter) = 0;
};

class line : public figure
{
    QColor linecolor;

    QPoint p1,p2;
public:
    line(QPoint _p1,QPoint _p2,QColor _linecolor);
    void draw(QPainter & painter);

};

class elipse : public figure
{
    QColor linecolor;
    QColor fillcolor;
    QPoint p1, p2;
    int width, heigth;

public:
    elipse(QPoint _p1,QPoint _p2,QColor _linecolor, QColor _fillcolor);
    void draw(QPainter &painter);
};

class rectangle : public figure
{
    QColor linecolor;
    QColor fillcolor;
    QPoint p1, p2,p15;
    int width, heigth;

public:
    rectangle (QPoint _p1,QPoint _p2,QColor _linecolor, QColor _fillcolor);
    void draw(QPainter &painter);
};

class pen : public figure
{
public:
    QVector<QPoint> curve;
    QColor lineColor;
    pen();
    pen(QColor c,QVector<QPoint> vec);
    void setColor(QColor c);
    void draw(QPainter &painter);
    void add(QPoint p);
    void clear();

};

class MyPaint: public QWidget //glowna klasa co ma wszystkie potrzebne (przekazywane) wartosci, i funkcje
{
    QPoint p1, p2;
    bool pressed;
    QColor currentColor;
    QColor currentFill;
    QVector <figure*> figures;
    QVector <figure*> temporaryVectorBardzo;
    int figSwitch;
    QVector<QColor> colors;
    pen temp;
    QBrush defbrush;
public:
    MyPaint(QWidget * p);
    void setColor(int i);
    void setBrush(int i);
    void delateLast();
    void bringBackToLiveLastElement();
    void setfigure(int i);
    void paintEvent(QPaintEvent * event); // najwazniejsze - update() to jest to
    void mousePressEvent(QMouseEvent * event); // przy wcisnieciu
    void mouseReleaseEvent(QMouseEvent * event); //przy puszczeniu
    void mouseMoveEvent(QMouseEvent * event);  // przy ruchu myszka
};

#endif // MYPAINT

