#include "viewfinder.h"
#include <QPainter>
#include <QImage>

ViewFinder::ViewFinder(QLabel* parent)
    :QLabel(parent)
{

}

ViewFinder::~ViewFinder()
{

}

void ViewFinder::paintEvent(QPaintEvent* event)
{
   QLabel::paintEvent(event);
   QPainter *painter = new QPainter(this);

   double wwidth = 1000;//ui->label->width();
   double wheight =1000;//ui->label->height();

   //  QSize ViewWH(wwidth,wheight );        //定义视口宽高

   // painter.setViewport(50,50,ViewWH.width(),ViewWH.height());

   painter->setWindow(0,0,wwidth,wheight);

   painter->setBrush(QColor(187,229,253));

   painter->setPen(QPen(QColor(11,67,127),2));

  // painter->drawRect(0,0,wwidth,wheight); //窗口背景

   painter->drawLine(0,wheight/2,wwidth,wheight/2);      //画X坐标

   painter->drawLine(wwidth/2,0,wwidth/2,wheight);
     QLabel::paintEvent(event);//每次调用必须执行,否则样式不显示
}
