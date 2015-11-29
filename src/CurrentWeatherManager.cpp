#include "currentweathermanager.h"

#include "src/client/SWGWeatherApi.h"
#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>
#include <QtQuick>


using  namespace Swagger;

Q_LOGGING_CATEGORY(requestsLogWeather, "wapp.CurrentWeahterManager")

class CurrentWeatherManagerPrivate {
public:
    QString longitude, latitude;
    WeatherQmlData now;
    QList<WeatherQmlData *> forecast;
    QQmlListProperty<WeatherQmlData> *fcProp;
    QSignalMapper *currentWeatherReplyMapper,
                   *forecastWeatherReplyMapper;
    bool ready;

    CurrentWeatherManagerPrivate() :
            fcProp(NULL),
            ready(false)
            {
    }
};

static void forecastAppend(QQmlListProperty<WeatherQmlData> *prop, WeatherQmlData *val) {
    Q_UNUSED(val);
    Q_UNUSED(prop);
}

static WeatherQmlData *forecastAt(QQmlListProperty<WeatherQmlData> *prop, int index) {
    CurrentWeatherManagerPrivate *d = static_cast<CurrentWeatherManagerPrivate *>(prop->data);
    return d->forecast.at(index);
}

static int forecastCount(QQmlListProperty<WeatherQmlData> *prop) {
    CurrentWeatherManagerPrivate *d = static_cast<CurrentWeatherManagerPrivate *>(prop->data);
    return d->forecast.size();
}

static void forecastClear(QQmlListProperty<WeatherQmlData> *prop) {
    static_cast<CurrentWeatherManagerPrivate *>(prop->data)->forecast.clear();
}

currentweathermanager::currentweathermanager(QObject *parent) :
        QObject(parent),
        d(new CurrentWeatherManagerPrivate) {
    d->fcProp = new QQmlListProperty<WeatherQmlData>(this, d,
                                                  forecastAppend,
                                                  forecastCount,
                                                  forecastAt,
                                                  forecastClear);

    d->currentWeatherReplyMapper = new QSignalMapper(this);
    d->forecastWeatherReplyMapper = new QSignalMapper(this);


}

currentweathermanager::~currentweathermanager() {
    delete d;
}


void currentweathermanager::queryCurrentWeather(double lat, double lng) {
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGWeatherApi * weatherApi = new Swagger::SWGWeatherApi("", "http://check-aurora-api.herokuapp.com");

    connect(weatherApi, SIGNAL(getWeatherCurrentSignal(SWGWeatherInformation* )),
            this, SLOT(handleCurrentWeatherResponse(SWGWeatherInformation* )));

    weatherApi->getWeatherCurrent(lat, lng, new QString("now"));
   // qDebug() << "rating done for: " + QString::number(lat) + ", " + QString::number(lng);
}


void currentweathermanager::handleCurrentWeatherResponse(SWGWeatherInformation* weather) {
    qCDebug(requestsLogWeather) << "got weather network data";
    qCDebug(requestsLogWeather) << weather->getIcon();
    //d->now.setValue(weather->getCloudCover());
   // QString* tmp = weather->getIcon();
    //qDebug() << "&: " + &tmp;
    //qDebug() << *tmp;
    // d->now.setValue(weather->getCloudCover());
    // setting the Icon will crash the Application for an unknown reason
  //  d->now.setIcon(*weather->getIcon());
   // d->now.setValue(weather->getCloudCover());
    QString * hans = new QString(weather->getIcon()->toLatin1());

    //qDebug() << "Ausgabe: " +  d->now.getIcon();

    d->now.setIcon(* hans);

    d->ready = true;
    emit readyChanged();

}
void currentweathermanager::refreshWeather(double lat, double lng) {
    this->queryCurrentWeather(lat, lng);
}

WeatherQmlData *currentweathermanager::currentWeather() const {
    return &(d->now);
}

QQmlListProperty<WeatherQmlData> currentweathermanager::weather() const {
    return *(d->fcProp);
}

bool currentweathermanager::ready() const {
    return d->ready;
}

void currentweathermanager::queryWeather() {

}
