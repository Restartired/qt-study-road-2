#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // SPINBOXDELEGATE_H
