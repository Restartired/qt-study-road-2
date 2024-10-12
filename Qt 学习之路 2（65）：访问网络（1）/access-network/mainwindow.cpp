#include "mainwindow.h"
#include "networker.h"
#include "weatherinfo.h"

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QMessageBox>

enum RemoteRequest {
    FetchWeatherInfo,
    FetchWeatherIcon
};

class MainWindow::Private
{
public:
    Private(MainWindow *q) :
        mainWindow(q)
    {
        netWorker = NetWorker::instance();
    }

    void fetchWeather(const QString &cityName)
    {
        QNetworkReply *reply = netWorker->get(QString("http://api.openweathermap.org/data/2.5/weather?q=%1&mode=json&units=metric&lang=zh_cn&appid=YOUR API KEY").arg(cityName));
        replyMap.insert(reply, FetchWeatherInfo);
    }

    void fetchIcon(const QString &iconName)
    {
        QNetworkReply *reply = netWorker->get(QString("http://openweathermap.org/img/w/%1.png").arg(iconName));
        replyMap.insert(reply, FetchWeatherIcon);
    }

    NetWorker *netWorker;
    MainWindow *mainWindow;
    QMap<QNetworkReply *, RemoteRequest> replyMap;
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    d(new MainWindow::Private(this))
{
    QComboBox *cityList = new QComboBox(this);
    cityList->addItem(tr("Beijing"), QLatin1String("Beijing,cn"));
    cityList->addItem(tr("Shanghai"), QLatin1String("Shanghai,cn"));
    cityList->addItem(tr("Nanjing"), QLatin1String("Nanjing,cn"));
    QLabel *cityLabel = new QLabel(tr("City: "), this);
    QPushButton *refreshButton = new QPushButton(tr("Refresh"), this);
    QHBoxLayout *cityListLayout = new QHBoxLayout;
    cityListLayout->setDirection(QBoxLayout::LeftToRight);
    cityListLayout->addWidget(cityLabel);
    cityListLayout->addWidget(cityList);
    cityListLayout->addWidget(refreshButton);

    QVBoxLayout *weatherLayout = new QVBoxLayout;
    weatherLayout->setDirection(QBoxLayout::TopToBottom);
    QLabel *cityNameLabel = new QLabel(this);
    weatherLayout->addWidget(cityNameLabel);
    QLabel *dateTimeLabel = new QLabel(this);
    weatherLayout->addWidget(dateTimeLabel);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->addLayout(cityListLayout);
    mainLayout->addLayout(weatherLayout);
    setCentralWidget(mainWidget);
    resize(320, 120);
    setWindowTitle(tr("Weather"));

    QHBoxLayout *weatherDetailLayout = new QHBoxLayout;
    weatherDetailLayout->setDirection(QBoxLayout::LeftToRight);
    weatherLayout->addLayout(weatherDetailLayout);
    weatherDetailLayout->addWidget(new QLabel(this));
    weatherDetailLayout->addWidget(new QLabel(this));

    connect(d->netWorker, &NetWorker::finished, [=] (QNetworkReply *reply) {
        // qDebug() << reply;
        RemoteRequest request = d->replyMap.value(reply);
        switch (request) {
        case FetchWeatherInfo:
        {
            QJsonParseError error;
            QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
            if (error.error == QJsonParseError::NoError) {
                if (!(jsonDocument.isNull() || jsonDocument.isEmpty()) && jsonDocument.isObject()) {
                    QVariantMap data = jsonDocument.toVariant().toMap();
                    WeatherInfo weather;
                    weather.setCityName(data[QLatin1String("name")].toString());
                    QDateTime dateTime;
                    dateTime.setSecsSinceEpoch(data[QLatin1String("dt")].toLongLong());
                    weather.setDateTime(dateTime);
                    QVariantMap main = data[QLatin1String("main")].toMap();
                    weather.setTemperature(main[QLatin1String("temp")].toFloat());
                    weather.setPressure(main[QLatin1String("pressure")].toFloat());
                    weather.setHumidity(main[QLatin1String("humidity")].toFloat());
                    QVariantList detailList = data[QLatin1String("weather")].toList();
                    QList<WeatherDetail *> details;
                    foreach (QVariant w, detailList) {
                        QVariantMap wm = w.toMap();
                        WeatherDetail *detail = new WeatherDetail;
                        detail->setDesc(wm[QLatin1String("description")].toString());
                        detail->setIcon(wm[QLatin1String("icon")].toString());
                        details.append(detail);

                        QHBoxLayout *weatherDetailLayout = (QHBoxLayout *)weatherLayout->itemAt(2)->layout();
                        // QHBoxLayout *weatherDetailLayout = new QHBoxLayout;
                        // weatherDetailLayout->setDirection(QBoxLayout::LeftToRight);
                        QLabel *descLabel = (QLabel *)weatherDetailLayout->itemAt(0)->widget();
                        descLabel->setText(detail->getDesc());
                        // weatherDetailLayout->addWidget(new QLabel(detail->getDesc(), this));
                        // weatherDetailLayout->addWidget(new QLabel(this));
                        // weatherLayout->addLayout(weatherDetailLayout);

                        d->fetchIcon(detail->getIcon());
                    }
                    weather.setDetails(details);

                    cityNameLabel->setText(weather.getCityName());
                    dateTimeLabel->setText(weather.getDateTime().toString());
                }
            } else {
                QMessageBox::critical(this, tr("Error"), error.errorString());
            }
            break;
        }
        case FetchWeatherIcon:
        {
            QHBoxLayout *weatherDetailLayout = (QHBoxLayout *)weatherLayout->itemAt(2)->layout();
            QLabel *iconLabel = (QLabel *)weatherDetailLayout->itemAt(1)->widget();
            QPixmap pixmap;
            pixmap.loadFromData(reply->readAll());
            iconLabel->setPixmap(pixmap);
            break;
        }
        }

        reply->deleteLater();
    });
    connect(refreshButton, &QPushButton::clicked, [=] () {
        d->fetchWeather(cityList->itemData(cityList->currentIndex()).toString());
    });
}



MainWindow::~MainWindow()
{
    delete d;
    d = 0;
}
