#ifndef CurrentWeatherManager_H
#define CurrentWeatherManager_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>

#include <QtPositioning/QGeoPositionInfoSource>
#include <src/client/SWGWeatherInformation.h>
#include <src/WeatherQmlData.h>

using namespace Swagger;

class CurrentWeatherManagerPrivate;

class currentweathermanager : public QObject {

    Q_OBJECT
    Q_PROPERTY(bool ready
                       READ ready
                       NOTIFY
                       readyChanged)

    Q_PROPERTY(WeatherQmlData *currentWeather
                       READ currentWeather
                       NOTIFY
                       weatherChanged)
    Q_PROPERTY(QQmlListProperty<WeatherQmlData> weather
                       READ weather
                       NOTIFY
                       weatherChanged)

public:
    explicit currentweathermanager(QObject *parent = 0);

    ~currentweathermanager();

    bool ready() const;

    QQmlListProperty<WeatherQmlData> weather() const;

    WeatherQmlData  *currentWeather()   const;
//  RatingQmlData   *currentRating()    const;

public slots:
    Q_INVOKABLE void refreshWeather(double lat, double lng);

public slots:

    void queryCurrentWeather(double lat, double lng);

    void queryWeather();

    void handleCurrentWeatherResponse(SWGWeatherInformation* summary);

signals:

    void readyChanged();

    void currentWeatherChanged();

    void weatherChanged();


private:
    CurrentWeatherManagerPrivate *d;

};

#endif // APPMODEL_H
