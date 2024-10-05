#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTableWidget>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //添加了widget不然setLayout()报错
    // QWidget *widget = new QWidget(this);
    // this->setCentralWidget(widget);

    // QLabel *label = new QLabel(this);
    // label->setFixedWidth(70);

    // QListWidget *listWidget = new QListWidget(this);

    // new QListWidgetItem(QIcon(":/Chrome.png"), tr("Chrome"), listWidget);
    // new QListWidgetItem(QIcon(":/Firefox.png"), tr("Firefox"), listWidget);

    // listWidget->addItem(new QListWidgetItem(QIcon(":/IE.png"), tr("IE")));
    // listWidget->addItem(new QListWidgetItem(QIcon(":/Netscape.png"), tr("Netscape")));
    // listWidget->addItem(new QListWidgetItem(QIcon(":/Opera.png"), tr("Opera")));
    // listWidget->addItem(new QListWidgetItem(QIcon(":/Safari.png"), tr("Safari")));
    // listWidget->addItem(new QListWidgetItem(QIcon(":/TheWorld.png"), tr("TheWorld")));
    // listWidget->addItem(new QListWidgetItem(QIcon(":/Traveler.png"), tr("Traveler")));

    // QListWidgetItem *newItem = new QListWidgetItem;
    // newItem->setIcon(QIcon(":/Maxthon.png"));
    // newItem->setText(tr("Maxthon"));
    // listWidget->insertItem(3, newItem);

    // // listWidget->setViewMode(QListView::IconMode);

    // QHBoxLayout *layout = new QHBoxLayout;
    // layout->addWidget(label);
    // layout->addWidget(listWidget);

    // // setLayout(layout);//不可以对主界面进行布局，要先创建子widget
    // centralWidget()->setLayout(layout);

    // connect(listWidget, SIGNAL(currentTextChanged(QString)),
    //         label, SLOT(setText(QString)));

    // this->setWindowTitle(tr("ListWidget"));






    // this->setWindowTitle(tr("tetetet"));
    // QWidget *widget = new QWidget(this);
    // this->setCentralWidget(widget);

    // QTreeWidget *treeWidget = new QTreeWidget(widget);
    // // treeWidget->setColumnCount(1);

    // QStringList headers;
    // headers << "Name" << "Number";
    // treeWidget->setHeaderLabels(headers);

    // QStringList rootTextList;
    // rootTextList << "Root" << "0";
    // QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget, rootTextList);

    // // QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget,
    // //                                             QStringList(QString("Root")));
    // // new QTreeWidgetItem(root, QStringList(QString("Leaf 1")));
    // // QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root, QStringList(QString("Leaf 2")));

    // new QTreeWidgetItem(root, QStringList() << QString("Leaf 1") << "1");
    // QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root,
    //                                              QStringList() << QString("Leaf 2") << "2");

    // leaf2->setCheckState(0, Qt::Checked);

    // QList<QTreeWidgetItem *> rootList;
    // rootList << root;
    // treeWidget->insertTopLevelItems(0, rootList);

    // treeWidget->show();

    // QVBoxLayout *layout = new QVBoxLayout;
    // layout->addWidget(treeWidget);
    // centralWidget()->setLayout(layout);




    this->setWindowTitle(tr("uitest"));
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);

    QTableWidget *tableWidget = new QTableWidget(widget);
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(5);

    QStringList headers;
    headers << "ID" << "Name" << "Age" << "Sex";
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->setItem(0, 0, new QTableWidgetItem(QString("0001")));
    tableWidget->setItem(1, 0, new QTableWidgetItem(QString("0002")));
    tableWidget->setItem(2, 0, new QTableWidgetItem(QString("0003")));
    tableWidget->setItem(3, 0, new QTableWidgetItem(QString("0004")));
    tableWidget->setItem(4, 0, new QTableWidgetItem(QString("0005")));
    tableWidget->setItem(0, 1, new QTableWidgetItem(QString("20100112")));

    tableWidget->show();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget);
    centralWidget()->setLayout(layout);

}

MainWindow::~MainWindow() {}
