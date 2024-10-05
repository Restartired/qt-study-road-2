#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QAbstractItemView>
#include <QStringListModel>
#include <QListView>

class MyListView : public QListView
{
    Q_OBJECT
public:
    MyListView();

public slots:
    void insertData();
    void deleteData();
    void showData();

private:
    QStringListModel *model;
    QListView *listView;
};

#endif // MYLISTVIEW_H
