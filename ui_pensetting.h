/********************************************************************************
** Form generated from reading UI file 'pensetting.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENSETTING_H
#define UI_PENSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pensetting
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *pensetting)
    {
        if (pensetting->objectName().isEmpty())
            pensetting->setObjectName(QStringLiteral("pensetting"));
        pensetting->resize(352, 79);
        gridLayout = new QGridLayout(pensetting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(pensetting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(pensetting);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(pensetting);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(pensetting);

        QMetaObject::connectSlotsByName(pensetting);
    } // setupUi

    void retranslateUi(QWidget *pensetting)
    {
        pensetting->setWindowTitle(QApplication::translate("pensetting", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("pensetting", "\347\272\277\346\235\241\345\256\275\345\272\246", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pensetting", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pensetting: public Ui_pensetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENSETTING_H
