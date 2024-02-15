#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include "HashTable.h"
#include <QMainWindow>
#include<QListWidget>
#include<QLineEdit>
#include <QPushButton>
#include <QGraphicsScene>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int size = 5, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clicked_addValue();
    void on_clicked_deleteValue();


private:

    void displayError(QString const& msg);
    void printTableInUI();
    Ui::MainWindow *ui;
    HashTable table;
};
#endif // MAINWINDOW_H
