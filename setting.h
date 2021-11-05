#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QSettings>
#include <QTextCodec>
namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setting *ui;

    void writesetting(QString settingfilename, QString groupname, QString settingname,QString value);
signals:
    void sendblock(int block);
};

#endif // SETTING_H
