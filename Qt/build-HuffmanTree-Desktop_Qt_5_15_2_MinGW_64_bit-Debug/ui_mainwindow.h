/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *codeEdit;
    QPushButton *button_decode;
    QLineEdit *decodeEdit;
    QPushButton *button_encode;
    QLineEdit *stringEdit;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        codeEdit = new QLineEdit(centralwidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));

        gridLayout->addWidget(codeEdit, 2, 0, 1, 1);

        button_decode = new QPushButton(centralwidget);
        button_decode->setObjectName(QString::fromUtf8("button_decode"));

        gridLayout->addWidget(button_decode, 3, 0, 1, 2);

        decodeEdit = new QLineEdit(centralwidget);
        decodeEdit->setObjectName(QString::fromUtf8("decodeEdit"));

        gridLayout->addWidget(decodeEdit, 4, 0, 1, 1);

        button_encode = new QPushButton(centralwidget);
        button_encode->setObjectName(QString::fromUtf8("button_encode"));

        gridLayout->addWidget(button_encode, 0, 0, 1, 2);

        stringEdit = new QLineEdit(centralwidget);
        stringEdit->setObjectName(QString::fromUtf8("stringEdit"));

        gridLayout->addWidget(stringEdit, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(graphicsView);

        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GraphicsSceneExample", nullptr));
        button_decode->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        button_encode->setText(QCoreApplication::translate("MainWindow", "Encode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
