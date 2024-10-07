#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include <QTableWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateSelection(const QItemSelection &selected, const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);

private:
    QTableWidget *tableWidget;
    QItemSelectionModel *selectionModel;

};
#endif // MAINWINDOW_H
