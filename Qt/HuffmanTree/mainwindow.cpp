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
    ui->stringEdit->setPlaceholderText("Введите сообщение");
    ui->codeEdit->setPlaceholderText("Закодированное сообщение");
    ui->decodeEdit->setPlaceholderText("Раскодированное сообщение");

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
    QFile file("text.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << str;
        file.close();
    }
    else
    {
        displayError("Не удалось создать и записать файл");
    }
    onTreeUpdate(file.fileName().toStdString());
    if(str != "")
    {
        QFile code("encodeText.txt");
        tree.encode(file.fileName().toStdString(),code.fileName().toStdString());
        if(code.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&code);
            QString string = stream.readAll();
            ui->codeEdit->setText(string);
            code.close();
        }
        ui->button_decode->setEnabled(true);
    }
    else
        displayError("line of sring is empty");
}

void MainWindow::on_clicked_decode()
{
    QString code = ui->codeEdit->text();
    if(code != "")
    {
        QFile code("encodeText.txt");
        if (!code.open(QIODevice::ReadOnly))
        {
            qDebug() << "Can't open the code!";
            return;
        }
        QFile decode("decodeText.txt");
        tree.decode(code.fileName().toStdString(),decode.fileName().toStdString());
        if(decode.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&decode);
            QString string = stream.readAll();
            ui->decodeEdit->setText(string);
            decode.close();
        }
    }
    else
        displayError("line of code is empty");
}

void MainWindow::onTreeUpdate(const std::string& fileContent)
{
    m_scene->clear();
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
