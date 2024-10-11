#include "tablemimedata.h"

TableMimeData::TableMimeData(const QTableWidget *tableWidget,
                             const QTableWidgetSelectionRange &range)
{
    dataTableWidget = tableWidget;
    selectionRange = range;
    dataFormats << "text/csv" << "text/html";
}



QVariant TableMimeData::retrieveData(const QString &format,
                                     QMetaType preferredType) const
{
    if (format == "text/csv") {
        return toCsv(selectionText());
    } else if (format == "text/html") {
        return toHtml(selectionText());
    } else {
        return QMimeData::retrieveData(format, preferredType);
    }
}
