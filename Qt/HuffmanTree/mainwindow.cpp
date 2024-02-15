#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GraphicsRectItem.h"
#include "HuffmanTree.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <sstream> // Для использования std::ostringstream

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    QFile file("text.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Can't open the file!";
        return;
    }
    ui->stringEdit->setText(file.fileName());

    QFile code("encodeText.txt");
    if (!code.open(QIODevice::ReadOnly)) {
        qDebug() << "Can't open the code!";
        return;
    }
    ui->codeEdit->setText(code.fileName());

    QFile decode("decodeText.txt");
    if (!decode.open(QIODevice::ReadOnly)) {
        qDebug() << "Can't open the code!";
        return;
    }
    ui->decodeEdit->setText(decode.fileName());

    file.close();
    code.close();
    decode.close();

    ui->button_decode->setEnabled(false);
    ui->graphicsView->setScene(m_scene);

    QObject::connect(ui->button_encode, &QPushButton::clicked, this, &MainWindow::on_clicked_encode);
    QObject::connect(ui->button_decode, &QPushButton::clicked, this, &MainWindow::on_clicked_decode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked_encode()
{
    QString str = ui->stringEdit->text();
    if(str != "")
    {
        QString encode = ui->codeEdit->text();
        tree.encode(str.toStdString(),encode.toStdString());
        QFile file(encode);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString str = stream.readAll();
            ui->codeEdit->setText(str);
            file.close();
        }
        ui->stringEdit->setText("encodeText.txt");
        ui->button_decode->setEnabled(true);
        onTreeUpdate(str.toStdString());
    }
    else
        displayError("line of sring is empty");

}

void MainWindow::on_clicked_decode()
{
    QString code = ui->stringEdit->text();
    if(code != "")
    {
        QString decode = ui->decodeEdit->text();
        tree.decode(code.toStdString(),decode.toStdString());
        QFile file(decode);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString code = stream.readAll();
            ui->decodeEdit->setText(code);
            file.close();
        }
    }
    else
        displayError("line of code is empty");
}

void MainWindow::onTreeUpdate(const std::string& fileContent)
{
    tree.build(fileContent);
    printTree();
}

void MainWindow::displayError(QString const& msg)
{
    QMessageBox::warning(this, "error", msg);
}

void MainWindow::printTree()
{
    int posX = 0;
    int posY = 0;
    printEllipse(tree.getRoot(), posX, posY);
}

// Преобразование std::set<char> в std::string
std::string MainWindow::setToString(const std::set<char>& mySet) {
    std::string str;
    for (const auto& c : mySet) {
        str += c;
    }
    return str;
}

void MainWindow::printEllipse(HuffmanTree::Node* nd, int posX, int posY)
{
    if(nd == nullptr)
    {
        return;
    }
    int range = getRange(nd);
    std::string myString = setToString(nd->getSymbols()); // Преобразование в std::string

    CircleItem *sceneNode = new CircleItem(QString::number(nd->m_frequency) + " " + QString::fromStdString(myString));
    sceneNode->setPos(posX, posY);

    QBrush brush(Qt::green);
    sceneNode->setBrush(brush);

    QPen pen(Qt::black);
    sceneNode->setPen(pen);

    m_scene->addItem(sceneNode);

    if(nd->m_left)
    {
        m_scene->addLine(posX + 4 , posY + 10,  posX + 4 - range, posY + 50 + 10)->setZValue(-1);//рисуем линию до левой ноды
        printEllipse(nd->m_left, posX - range, posY + 50 );
    }
    if(nd->m_right)
    {
        m_scene->addLine(posX + 4 , posY + 10,  posX + 4 + range, posY + 50 + 10)->setZValue(-1);
        printEllipse(nd->m_right, posX + range, posY + 50);//рисуем линию до правой ноды
    }
}

int MainWindow::getRange(HuffmanTree::Node* nd)
{
    if (nd == nullptr)
        return 0;

    int levelWidth = 0;
    std::queue<HuffmanTree::Node*> q;
    q.push(nd);

    while (!q.empty())
    {
        int size = q.size();
        levelWidth = std::max(levelWidth, size);

        for (int i = 0; i < size; ++i)
        {
            HuffmanTree::Node* node = q.front();
            q.pop();

            if (node->m_left != nullptr)
                q.push(node->m_left);
            if (node->m_right != nullptr)
                q.push(node->m_right);
        }
    }

    // Ширина уровня определяет количество узлов, умноженное на диаметр узла
    // Плюс некоторая дополнительная величина для разделения узлов
    return levelWidth * (2 * nodeRadius) + 50; // 50 - просто некоторая дополнительная величина
}
