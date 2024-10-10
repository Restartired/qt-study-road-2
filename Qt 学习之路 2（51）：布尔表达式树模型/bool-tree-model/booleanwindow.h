#ifndef BOOLEANWINDOW_H
#define BOOLEANWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTreeView>

#include "booleanmodel.h"

class BooleanWindow : public QWidget
{
    Q_OBJECT
public:
    BooleanWindow();

private slots:
    void booleanExpressionChanged(const QString &expr);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    BooleanModel *booleanModel;
    QTreeView *treeView;
};

#endif // BOOLEANWINDOW_H
