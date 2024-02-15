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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QPushButton *deleteValueButton;
    QLineEdit *keyForDelete;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addValueButton;
    QLineEdit *keyEdit;
    QLineEdit *valueEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(690, 544);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        deleteValueButton = new QPushButton(centralwidget);
        deleteValueButton->setObjectName(QString::fromUtf8("deleteValueButton"));
        deleteValueButton->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, deleteValueButton);

        keyForDelete = new QLineEdit(centralwidget);
        keyForDelete->setObjectName(QString::fromUtf8("keyForDelete"));
        keyForDelete->setMaximumSize(QSize(16777215, 28));
        keyForDelete->setMaxLength(32770);

        formLayout->setWidget(2, QFormLayout::FieldRole, keyForDelete);


        verticalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addValueButton = new QPushButton(centralwidget);
        addValueButton->setObjectName(QString::fromUtf8("addValueButton"));
        addValueButton->setMaximumSize(QSize(80, 29));

        horizontalLayout->addWidget(addValueButton);

        keyEdit = new QLineEdit(centralwidget);
        keyEdit->setObjectName(QString::fromUtf8("keyEdit"));
        keyEdit->setMaximumSize(QSize(16777215, 28));

        horizontalLayout->addWidget(keyEdit);

        valueEdit = new QLineEdit(centralwidget);
        valueEdit->setObjectName(QString::fromUtf8("valueEdit"));

        horizontalLayout->addWidget(valueEdit);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 690, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        deleteValueButton->setText(QCoreApplication::translate("MainWindow", "deleteValue", nullptr));
        addValueButton->setText(QCoreApplication::translate("MainWindow", "addValue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
