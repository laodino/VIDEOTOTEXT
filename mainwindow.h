#ifndef MainWindow_H

#define MainWindow_H


#include <QMainWindow>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QSettings>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTextCodec>
#include <QMediaPlayer>
#include <QDateTime>
#include <stdio.h>
#include "setting.h"
#include "myvideosurface.h"
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

      QMediaPlayer *mediaPlayer ;
      QPen pen;
      double wwidth;
      double wheight;
      QImage videoImg;
      QCamera*             myCamera;
      QCameraImageCapture* myImageCapture;

      QGraphicsVideoItem* myGraphicsVideoItem;
      QGraphicsScene* myGraphicsScene;
      QGraphicsView*  myGraphicsView;

      QGraphicsLineItem* myGraphicsLineItem   = new QGraphicsLineItem();
      QGraphicsLineItem* myGraphicsLineItem1  = new QGraphicsLineItem();

      QTimer* myTimer;
      bool showText;

      QList <int> num;
       QList <QString> ch;
       QMap <int,QString> charmap;

       int block1 ;

       void setblock(int block);


private slots:
    void slotExitBtn();
    void slotImageCaptureBtn(int, QImage image);
    void slotTimer();

private:

    void openfile();
    void readsetting(QString settingfilename, QString groupname, QString settingname,QString &value);
    void rcvFrame(QVideoFrame m_currentFrame); 
    void grayscaleFast(QImage &image);
    QString GetCh(int data);
    QImage stringTopixmap( const QString& pic );


};

#endif // MainWindow_H

