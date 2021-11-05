#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
}

setting::~setting()
{
    delete ui;
}

void setting::writesetting(QString settingfilename, QString groupname, QString settingname,QString value)
{
    QSettings settings(QCoreApplication::applicationDirPath()+"/"+settingfilename+".ini", QSettings::IniFormat);
    settings.setIniCodec(QTextCodec::codecForName("GBK")); //在此添加设置，即可读写ini文件中的中文
    settings.beginGroup(""+groupname+"") ;
    settings.setValue(""+settingname+"", value) ;
    settings.endGroup( ) ;
}
void setting::on_pushButton_clicked()
{
    emit sendblock(ui->lineEdit->text().trimmed().toDouble());
    writesetting("setting","media","block",QString::number(ui->lineEdit->text().trimmed().toDouble()));
    hide();
}
