
#include "SWGWeatherInformation.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGWeatherInformation::SWGWeatherInformation(QString* json) {
    init();
    this->fromJson(*json);
}

SWGWeatherInformation::SWGWeatherInformation() {
    init();
}

SWGWeatherInformation::~SWGWeatherInformation() {
    this->cleanup();
}

void
SWGWeatherInformation::init() {
    icon = new QString("");
    cloudCover = 0.0;
    summary = new QString("");
    sunsetTime = 0;
    sunriseTime = 0;
    date = NULL;
    
}

void
SWGWeatherInformation::cleanup() {
    if(icon != NULL) {
        delete icon;
    }
    
    if(summary != NULL) {
        delete summary;
    }
    
    
    if(date != NULL) {
        delete date;
    }
    
}

SWGWeatherInformation*
SWGWeatherInformation::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGWeatherInformation::fromJsonObject(QJsonObject &pJson) {
    setValue(&icon, pJson["icon"], "QString", "QString");
    setValue(&cloudCover, pJson["cloudCover"], "double", "");
    setValue(&summary, pJson["summary"], "QString", "QString");
    setValue(&sunsetTime, pJson["sunsetTime"], "qint32", "");
    setValue(&sunriseTime, pJson["sunriseTime"], "qint32", "");
    setValue(&date, pJson["date"], "QDateTime", "QDateTime");
    
}

QString
SWGWeatherInformation::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGWeatherInformation::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("icon"), icon, obj, QString("QString"));
    
    
    
    obj->insert("cloudCover", QJsonValue(cloudCover));
    
    
    toJsonValue(QString("summary"), summary, obj, QString("QString"));
    
    
    
    obj->insert("sunsetTime", QJsonValue(sunsetTime));
    obj->insert("sunriseTime", QJsonValue(sunriseTime));
    
    
    toJsonValue(QString("date"), date, obj, QString("QDateTime"));
    
    
    
    

    return obj;
}

QString*
SWGWeatherInformation::getIcon() {
    return icon;
}
void
SWGWeatherInformation::setIcon(QString* icon) {
    this->icon = icon;
}

double
SWGWeatherInformation::getCloudCover() {
    return cloudCover;
}
void
SWGWeatherInformation::setCloudCover(double cloudCover) {
    this->cloudCover = cloudCover;
}

QString*
SWGWeatherInformation::getSummary() {
    return summary;
}
void
SWGWeatherInformation::setSummary(QString* summary) {
    this->summary = summary;
}

qint32
SWGWeatherInformation::getSunsetTime() {
    return sunsetTime;
}
void
SWGWeatherInformation::setSunsetTime(qint32 sunsetTime) {
    this->sunsetTime = sunsetTime;
}

qint32
SWGWeatherInformation::getSunriseTime() {
    return sunriseTime;
}
void
SWGWeatherInformation::setSunriseTime(qint32 sunriseTime) {
    this->sunriseTime = sunriseTime;
}

QDateTime*
SWGWeatherInformation::getDate() {
    return date;
}
void
SWGWeatherInformation::setDate(QDateTime* date) {
    this->date = date;
}



} /* namespace Swagger */

