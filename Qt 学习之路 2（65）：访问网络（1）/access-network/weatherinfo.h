#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include "weatherdetail.h"

#include <QString>
#include <QDateTime>

class WeatherInfo
{
public:
    WeatherInfo();
    ~WeatherInfo();

    QString getCityName() const;
    void setCityName(const QString &cityName);

    quint32 getId() const;
    void setId(quint32 id);

    QDateTime getDateTime() const;
    void setDateTime(const QDateTime &dateTime);

    float getTemperature() const;
    void setTemperature(float temperature);

    float getHumidity() const;
    void setHumidity(float humidity);

    float getPressure() const;
    void setPressure(float pressure);

    QList<WeatherDetail *> getDetails() const;
    void setDetails(const QList<WeatherDetail *> details);

private:
    class Private;
    friend class Private;
    Private *d;

    QString cityName;
    quint32 id;
    QDateTime dateTime;
    float temperature;
    float humidity;
    float pressure;
    QList<WeatherDetail *> details;
};

QDebug operator <<(QDebug dbg, const WeatherInfo &w);

#endif // WEATHERINFO_H
