
#include "mypaint.h"

MyPaint::MyPaint(QWidget * p)
    :   QWidget(p)

{   pressed=false;
    colors.push_back(*(new QColor(0,0,0,255)));
    colors.push_back(*(new QColor(255,0,0,255)));
    colors.push_back(*(new QColor(0,255,0,255)));
    colors.push_back(*(new QColor(0,0,255,255)));
    colors.push_back(*(new QColor(255,255,255,255)));
    figSwitch=0;
    currentColor=colors[0];
    currentFill=colors[4];

}

void line::draw(QPainter & painter)
{
    painter.setPen(linecolor);
    painter.drawLine(p1,p2);
}
line:: line(QPoint _p1,QPoint _p2,QColor _linecolor)
{
    p1=_p1;
    p2=_p2;
    linecolor=_linecolor;
}

elipse::elipse(QPoint _p1, QPoint _p2, QColor _linecolor, QColor _fillcolor)
{
    p1=_p1;
    p2=_p2;
    linecolor=_linecolor;
    fillcolor=_fillcolor;

}

void elipse::draw(QPainter &painter)
{
    painter.setBrush(fillcolor);
    painter.setPen(linecolor);
    painter.drawEllipse(*(new QRect(p1,p2)));
}

rectangle::rectangle(QPoint _p1, QPoint _p2, QColor _linecolor, QColor _fillcolor)
{
    p1=_p1;
    p2=_p2;
    linecolor=_linecolor;
    fillcolor=_fillcolor;

}

void rectangle::draw(QPainter &painter)
{
    painter.setBrush(fillcolor);
    painter.setPen(linecolor);
    painter.drawRect(*(new QRect(p1,p2)));
}

pen::pen()
{}
pen::pen(QColor c,QVector<QPoint> vec)
{
    lineColor=c;
    curve=vec;
}
void pen::clear()
{
    curve.clear();
}

void pen::setColor(QColor c)
{
    lineColor=c;
}

void pen::add(QPoint p)
{
    curve.push_back(p);
}

void pen::draw(QPainter &painter)
{
    painter.setPen(lineColor);
    for(int i=1; i<curve.size();i++)
    {
        painter.drawLine(curve[i-1],curve[i]);
    }
}

void MyPaint::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    defbrush=painter.brush();
    for(auto el: figures)
    {
        el->draw(painter);
        update();
    }
    if(pressed)
    {
    switch (figSwitch)
    {
    case 0:
        painter.setPen(currentColor);
        painter.drawLine(p1,p2);
    break;
     case 1:
        painter.setPen(currentColor);
        painter.setBrush(currentFill);
         painter.drawEllipse(*(new QRect(p1,p2)));
        break;
    case 2:
        painter.setPen(currentColor);
        painter.setBrush(currentFill);
        painter.drawRect(*(new QRect(p1,p2)));
        break;
    case 3:
        temp.setColor(currentColor);
        temp.draw(painter);

      break;
    default:
        exit(0);
      break;
    }
    }


}



void MyPaint::mousePressEvent(QMouseEvent * event)
{
    pressed = true;
    p1 = event->pos();
    if(figSwitch==3)
    {
    temp.add(p1);
    }


}



void MyPaint::mouseReleaseEvent(QMouseEvent * event)
{
    pressed = false;
    p2 = event->pos();

    switch (figSwitch)
    {
    case 0:
        figures.push_back(new line(p1,p2,currentColor));
    break;
     case 1:
        figures.push_back(new elipse(p1,p2,currentColor,currentFill));
        break;
    case 2:
        figures.push_back(new rectangle(p1,p2,currentColor,currentFill));
        break;
    case 3:
        figures.push_back(new pen(currentColor,temp.curve));
        temp.clear();
        break;
    default:
        exit(0);
      break;
    }
    temporaryVectorBardzo.clear();

}



void MyPaint::mouseMoveEvent(QMouseEvent * event)
{
    if (pressed)
    {
        p2 = event->pos();
        update();

        if(figSwitch==3)
        {
            temp.curve.push_back(p2);
            update();
        }
    }
}

void MyPaint:: setColor(int i)
{

    currentColor=colors[i];
}
void MyPaint:: setBrush(int i)
{
    currentFill=colors[i];
}
void MyPaint:: setfigure(int i)
{
    figSwitch=i;
}

void MyPaint :: delateLast()
{
    if (!figures.isEmpty())
    {
        temporaryVectorBardzo.push_back(figures.last());
        figures.pop_back();
    }
    update();
}

void MyPaint :: bringBackToLiveLastElement()
{
    if(!temporaryVectorBardzo.isEmpty())
    {
        figures.push_back(temporaryVectorBardzo.last());
        temporaryVectorBardzo.pop_back();
        update();
    }
}
