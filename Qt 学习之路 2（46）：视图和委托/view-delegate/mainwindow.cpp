#include "mainwindow.h"
#include "spinboxdelegate.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);

    QStringList data;
    data << "0" << "1" << "2";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);

    listView->setItemDelegate(new SpinBoxDelegate(listView));

    QPushButton *btnShow = new QPushButton(tr("Show Model"), this);
    connect(btnShow, SIGNAL(clicked()),
            this, SLOT(showModel()));
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btnShow);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listView);
    layout->addLayout(buttonLayout);

    widget->setLayout(layout);


}

MainWindow::~MainWindow() {}
