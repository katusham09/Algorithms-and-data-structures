#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <QDebug>

MainWindow::MainWindow(int size, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , table(size)
{
    ui->setupUi(this);
    ui->keyEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyEdit->setText("0");
    ui->valueEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->valueEdit->setText("0");
    ui->keyForDelete->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyForDelete->setText("0");
    ui->tableWidget->setColumnCount(1);

    ui->tableWidget->setRowCount(table.getCapacity());
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "[Key, Value]");

    QObject::connect(ui->addValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_addValue);
    QObject::connect(ui->deleteValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_deleteValue);
}

void MainWindow::on_clicked_addValue()
{
    bool ok1;
    int key = ui->keyEdit->text().toInt(&ok1);
    bool ok2;
    int value = ui->valueEdit->text().toInt(&ok2);

    if(ok1 && ok2)
    {
        int hash = table.add(key, value);

        std::cout << "table" << std::endl;
        table.printTable();

        QTableWidgetItem *existingItem = ui->tableWidget->item(hash, 0);


        if (existingItem) {
            QString existingData = existingItem->text();
            existingData += QString(" [%1, %2]").arg(QString::number(key), QString::number(value));
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(existingData));
        }
        else {
            ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(QString("[%1, %2]").arg(QString::number(key), QString::number(value))));
        }
    }
    else {
        displayError(QString {"addValue: invalid key value: must be an integer"});
    }
}

void MainWindow::on_clicked_deleteValue()
{
    bool ok;
    int keyToDelete = ui->keyForDelete->text().toInt(&ok);
    if(ok)
    {
        if(table.contains(keyToDelete))
        {
            HashFunction hashFunction;
            int hash = hashFunction.getHash(keyToDelete, table.getCapacity());

            QTableWidgetItem *existingItem = ui->tableWidget->item(hash, 0);

            if (existingItem) {
                QString existingData = existingItem->text();
                QStringList dataList = existingData.split(" ");
                for (int i = 0; i < dataList.size(); ++i) {
                    if (dataList[i].startsWith(QString("[%1,").arg(keyToDelete))) {
//                        qDebug() << "Contents of dataList:";
//                        for (const QString &item : dataList) {
//                            qDebug() << item;
//                        }
                        dataList.removeAt(i+1); // Удаляем значение (пара идет [ключ, значение])
                        dataList.removeAt(i);   // Удаляем ключ
                        break;
                    }
                }
                QString updatedData = dataList.join(" ");
                ui->tableWidget->setItem(hash, 0, new QTableWidgetItem(updatedData));
            }

            table.remove(keyToDelete);
        }
        else {
            displayError("deleteValue: this key not found");
        }
    }
    else {
        displayError("deleteValue: invalid key value: must be an integer");
    }

    table.printTable();
}

void MainWindow::displayError(QString const& msg)
{
    QMessageBox::warning(this, "error", msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
