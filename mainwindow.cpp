#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>


#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ch <<" "<<"` "<<". "<<"^ "<<", "<<": "<<"~ "<<"\" "<< "< "<<"! "<< "c "<<"t "<<"+ "<<"{ "<<"i "<<"7 "<<"? "<<"u "<<"3 "<<"0 "<<"p "<<"w "<<"4 "<<"A "<<"8 "<<"D "<<"X "<<"% "<<"# "<<"H "<<"W "<<"M ";
    num<< 0<<5<<7<<9<<13<<15<<17<<19<<21<<23<<25<<27<<29<<31<<33<<35<<37<<39<<41<<43<<45<<47<<49<<51<<53<<55<<59<<61<<63<<66<<68<<70;
    // for(int i=0;i!=32;i++)
    // {
    //   charmap.insert(num.at(i),ch.at(i));
    // }

    setWindowState(Qt::WindowFullScreen);
    QString strblock;
    readsetting("setting","media","block",strblock);
    block1=strblock.toInt();
    qDebug()<<block1;
    setWindowTitle("QCamera");

    //自己用QPainter将每一帧视频画出来
    myvideosurface *_surface = new myvideosurface(this);
    mediaPlayer = new QMediaPlayer;
    _surface = new myvideosurface;
    setting *_setting = new setting();

    mediaPlayer->setVideoOutput(_surface);


    //  QVideoWidget * videowidget_ = new QVideoWidget();
    // ui->verticalLayout->addWidget(videowidget_);
    // mediaPlayer->setVideoOutput(videowidget_);
    //  myGraphicsView = new QGraphicsView(this);
    // ui->verticalLayout->addWidget(myGraphicsView);


    //处理myvideosurface中每一帧视频
    connect(_surface, &myvideosurface::frameAvailable, this, &MainWindow::rcvFrame);

    connect(_setting,&setting::sendblock,this,&MainWindow::setblock);


    // 添加菜单
    QMenu *pFile = ui->menuBar->addMenu("选项");
    // 添加菜单项
    QAction *pStart = pFile->addAction("文件");
    QAction *pSetting= pFile->addAction("设置");
    QAction *pExit= pFile->addAction("退出");
    connect(pStart, &QAction::triggered,this,&MainWindow::openfile);

    connect(pSetting, &QAction::triggered,
            [_setting] ()
    {
       _setting->show();
    }
    );

    connect(pExit, &QAction::triggered,
            [] ()
    {
        QApplication* app;
        app->exit(0);
    }
    );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setblock(int block)
{
    block1 = block;
}

void MainWindow::readsetting(QString settingfilename, QString groupname, QString settingname,QString &value)
{
    QSettings settings(QCoreApplication::applicationDirPath()+"/"+settingfilename+".ini", QSettings::IniFormat);
    settings.setIniCodec(QTextCodec::codecForName("GBK")); //在此添加设置，即可读写ini文件中的中文
    //参数1，代表新建ini文件的位置的绝对路径；  参数2，将设置存储在ini文件中
    settings.beginGroup(""+groupname+"");
    value =  settings.value(""+settingname+"").toString();
    settings.endGroup();
}

void MainWindow::slotExitBtn()
{
   // myCamera->stop();
    close();
}

void MainWindow::slotImageCaptureBtn(int, QImage image)
{
    QString savepath = QFileDialog::getSaveFileName(this,"Save Capture","Capture","Image png(*.png);;Image jpg(*.jpg);;Image bmp(*.bmp)");
    if(!savepath.isEmpty()){
        image.save(savepath);
    }
}

void MainWindow::slotTimer()
{
    myCamera->start();
}

void MainWindow::openfile()
{
    // QImage picimage ;
    // picimage.load("D:/122.jpg");
    // grayscaleFast(picimage);
    QString filepath = QFileDialog::getOpenFileName(this,"打开视频",".","*.mp4");
    qDebug()<<"openfile"<<filepath;
    mediaPlayer->setMedia(QUrl(filepath));
     qDebug()<<"play";
    mediaPlayer->play();

}

void MainWindow::rcvFrame(QVideoFrame m_currentFrame)
{
    if(m_currentFrame.isValid())
    {
        QVideoFrame framecopy = m_currentFrame;
        framecopy.map(QAbstractVideoBuffer::ReadOnly);
        //将视频帧转化成QImage,devicePixelRatio设备像素比，bytesPerLine一行的像素字节（1280*4=5120）
        videoImg =  QImage(framecopy.bits(),
                           framecopy.width(),
                           framecopy.height(),
                           framecopy.bytesPerLine(),
                           QVideoFrame::imageFormatFromPixelFormat(framecopy.pixelFormat()));       //这里要做一个copy,因为char* pdata在emit后释放了
        // videoImg = videoImg.mirrored(false, true);                          //水平翻转，原始图片是反的
         qDebug() <<  "image" << videoImg;  //可以看看输出啥东西
        grayscaleFast(videoImg);
        QString currentTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        // QString savefile = QString("D:/2021-03/%1.jpg").arg(currentTime);
        //  qDebug() << videoImg.save(savefile);
        framecopy.unmap();                                         //释放map拷贝的内存
        //  QWidget::update();                                              //更新了，就会触发paintEvent画图
    }
}




void MainWindow::grayscaleFast( QImage& image)
{
    QString imagestring;
    ui->plainTextEdit->clear();
    qDebug()<<"grayscale";
  //  qDebug()<<image.width()<<image.height();
    int gray;   //灰度值
    for (int i = 0; i < image.height() / block1; ++i)
    {
        for (int j = 0; j < image.width() / block1; ++j)
        {
            gray = 0;   //清零
            for (int x = 0; x < block1; ++x)
            {
                for (int y = 0; y < block1; ++y)
                {
                    //统计这个区域中的灰度值 求平均
                    gray += qGray(image.pixel(j * block1 + x, i * block1 + y));
                }
            }
            gray /= block1 * block1;  //取平均值
            //将灰度值  转换成0~70之间的值  匹配数组中的数字  找到对应字符
            imagestring+= GetCh(70 - gray * 70 / 255);//0~255之间  --->0~70之间的数字
                   // (gray)>127?"*":" ";
        }
        imagestring+="\n";
    }

qDebug()<<"over";

    // printf(imagestring.toLatin1().data());

    // qDebug()<<"hahah";
    //qDebug()<<imagestring.size();

    // cha
    ui->plainTextEdit->appendPlainText(imagestring);
    // image = stringTopixmap(imagestring);


}


QString MainWindow::GetCh(int data)
{
    //快速查找
    int left = 0, right = 31, index;    //num的最大元素下标是31
    while (left < right)
    {
        index = (left + right) / 2;
        if (num.at(index) == data) return ch.at(index);       //找到数字 直接返回对应的字符
        else if (num.at(index) > data) right = index - 1;    //往左找
        else left = index + 1;
    }
    //退出的条件  left>=right
    return ch.at(left);    //return ch[right]也可以
}

QImage  MainWindow::stringTopixmap( const QString& pic )
{
    QByteArray byte_array = QByteArray::fromBase64(pic.toLocal8Bit());
    QImage pix;
    QDataStream data_stream(&byte_array,QIODevice::ReadOnly);
    data_stream>>pix;
    return pix;
}
