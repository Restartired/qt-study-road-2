#ifndef TABLEMIMEDATA_H
#define TABLEMIMEDATA_H

#include <QMimeData>
#include <QTableWidget>

class TableMimeData : public QMimeData
{
    Q_OBJECT
public:
    TableMimeData(const QTableWidget *tableWidget,
                  const QTableWidgetSelectionRange &range);
    const QTableWidget *tableWidget() const
    {
        return dataTableWidget;
    }
    QTableWidgetSelectionRange range() const
    {
        return selectionRange;
    }
    QStringList formats() const
    {
        return dataFormats;
    }
protected:
    QVariant retrieveData(const QString &format,
                          QMetaType preferredType) const;

    // QVariant retrieveData(const QString &format,
    //                       QVariant::Type preferredType) const;
    //tablemimedata.h:27:37: 'Type' is deprecated: Use QMetaType::Type instead.
private:
    static QString toHtml(const QString &plainText);
    static QString toCsv(const QString &plainText);
    QString text(int row, int column) const;
    QString selectionText() const;

    const QTableWidget *dataTableWidget;
    QTableWidgetSelectionRange selectionRange;
    QStringList dataFormats;
};

#endif // TABLEMIMEDATA_H
