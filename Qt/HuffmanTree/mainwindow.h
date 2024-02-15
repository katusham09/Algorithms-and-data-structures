#include <QMainWindow>
#include <iostream>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsScene>
#include "HuffmanTree.h"


namespace Ui {class MainWindow;}
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string setToString(const std::set<char>& mySet);

private slots:
    void on_clicked_encode();
    void onTreeUpdate(const std::string& fileContent);
    void on_clicked_decode();

private:
    int nodeRadius = 40;
    void displayError(QString const& msg);
    Ui::MainWindow *ui;
    HuffmanTree tree;
    QGraphicsScene *m_scene = nullptr;

    void printTree();

    void printEllipse(HuffmanTree::Node* nd, int posX, int posY);

    int getRange(HuffmanTree::Node* nd);
};
