#include "CurrentWeatherManager.h"

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

CurrentWeatherManager::CurrentWeatherManager(QObject *parent) :
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

CurrentWeatherManager::~CurrentWeatherManager() {
    delete d;
}


void CurrentWeatherManager::queryCurrentWeather(double lat, double lng) {
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGWeatherApi * weatherApi = new Swagger::SWGWeatherApi("", "http://check-aurora-api.herokuapp.com");

    connect(weatherApi, SIGNAL(getWeatherCurrentSignal(SWGWeatherInformation* )),
            this, SLOT(handleCurrentWeatherResponse(SWGWeatherInformation* )));

    weatherApi->getWeatherCurrent(lat, lng, new QString("now"));
   // qDebug() << "rating done for: " + QString::number(lat) + ", " + QString::number(lng);
}


void CurrentWeatherManager::handleCurrentWeatherResponse(SWGWeatherInformation* weather) {

  //  qCDebug(requestsLog) << "got weather network data";
  //  qCDebug(requestsLog) << weather->getIcon();
    QString * weatherIcon = new QString("clear-day");
    QString * weatherSummary = new QString("loading..");


    if(weather->getIcon()!=0){
       *weatherIcon = weather->getIcon()->toLatin1();
    }

    if(weather->getSummary()!=0){
       *weatherSummary = weather->getSummary()->toLatin1();
    }
    d->now.setValue(weather->getCloudCover());
    d->now.setIcon(* weatherIcon);
    d->now.setSummary(* weatherSummary);
    d->now.setSunriseTime(weather->getSunriseTime());
    d->now.setSunsetTime(weather->getSunsetTime());
    d->ready = true;
    emit readyChanged();

}
void CurrentWeatherManager::refreshWeather(double lat, double lng) {
    this->queryCurrentWeather(lat, lng);
}

WeatherQmlData *CurrentWeatherManager::currentWeather() const {
    return &(d->now);
}

QQmlListProperty<WeatherQmlData> CurrentWeatherManager::weather() const {
    return *(d->fcProp);
}

bool CurrentWeatherManager::ready() const {
    return d->ready;
}

void CurrentWeatherManager::queryWeather() {

}
