#ifndef WEATHERDETAIL_H
#define WEATHERDETAIL_H

#include <QString>

class WeatherDetail
{
public:
    WeatherDetail();
    ~WeatherDetail();

    QString getDesc() const;
    void setDesc(const QString &desc);

    QString getIcon() const;
    void setIcon(const QString &icon);

private:
    class Private;
    friend class Private;
    Private *d;

    QString desc;
    QString icon;
};

QDebug operator <<(QDebug dbg, const WeatherDetail &w);

#endif // WEATHERDETAIL_H
