#include "mainwindow.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);

    tableWidget = new QTableWidget(8, 4, widget);
    selectionModel = tableWidget->selectionModel();

    // QModelIndex topLeft = tableWidget->model()->index(0, 0, QModelIndex());
    // QModelIndex bottomRight = tableWidget->model()->index(5, 2, QModelIndex());

    // // QItemSelection selection(topLeft, bottomRight);
    // // selectionModel->select(selection, QItemSelectionModel::Select);


    // // QItemSelection toggleSelection;
    // // topLeft = tableWidget->model()->index(2, 1, QModelIndex());
    // // bottomRight = tableWidget->model()->index(7, 3, QModelIndex());
    // // toggleSelection.select(topLeft, bottomRight);
    // // selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);





    // QItemSelection columnSelection;
    // topLeft = tableWidget->model()->index(0, 1, QModelIndex());
    // bottomRight = tableWidget->model()->index(0, 2, QModelIndex());
    // columnSelection.select(topLeft, bottomRight);
    // selectionModel->select(columnSelection,
    //                        QItemSelectionModel::Select | QItemSelectionModel::Columns);


    // QItemSelection rowSelection;
    // topLeft = tableWidget->model()->index(0, 0, QModelIndex());
    // bottomRight = tableWidget->model()->index(1, 0, QModelIndex());
    // rowSelection.select(topLeft, bottomRight);
    // selectionModel->select(rowSelection,
    //                        QItemSelectionModel::Select | QItemSelectionModel::Rows);



    QModelIndex topLeft = tableWidget->model()->index(0, 0);
    QModelIndex bottomRight = tableWidget->model()->index(tableWidget->model()->rowCount()-1,
                                           tableWidget->model()->columnCount()-1);

    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);


    tableWidget->show();

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::updateSelection);
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, &MainWindow::changeCurrent);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(tableWidget);

}



MainWindow::~MainWindow() {}



void MainWindow::updateSelection(const QItemSelection &selected,
                                 const QItemSelection &deselected)
{
    QModelIndex index;
    QModelIndexList items = selected.indexes();

    foreach (index, items) {
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        tableWidget->model()->setData(index, text);
    }

    items = deselected.indexes();

    foreach (index, items) {
        tableWidget->model()->setData(index, "");
    }
}



void MainWindow::changeCurrent(const QModelIndex &current,
                               const QModelIndex &previous)
{
    statusBar()->showMessage(
        tr("Moved from (%1,%2) to (%3,%4)")
            .arg(previous.row()).arg(previous.column())
            .arg(current.row()).arg(current.column()));
}
