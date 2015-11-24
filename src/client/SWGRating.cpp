//#include "SWGHelpers.h"
#include "SWGRating.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRating::SWGRating(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRating::SWGRating() {
    init();
}

SWGRating::~SWGRating() {
    this->cleanup();
}

void
SWGRating::init() {
    date = NULL;
    location = new SWGLocation();
    locationGeomagnatic = new SWGGeomagnaticLocation();
    kp = new SWGKpInformation();
    weather = new SWGWeatherInformation();
    value = 0.0;
    
}

void
SWGRating::cleanup() {
    if(date != NULL) {
        delete date;
    }
    if(location != NULL) {
        delete location;
    }
    if(locationGeomagnatic != NULL) {
        delete locationGeomagnatic;
    }
    if(kp != NULL) {
        delete kp;
    }
    if(weather != NULL) {
        delete weather;
    }
    
    
}

SWGRating*
SWGRating::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRating::fromJsonObject(QJsonObject &pJson) {
    setValue(&date, pJson["date"], "QDateTime", "QDateTime");
    setValue(&location, pJson["location"], "SWGLocation", "SWGLocation");
    setValue(&locationGeomagnatic, pJson["locationGeomagnatic"], "SWGGeomagnaticLocation", "SWGGeomagnaticLocation");
    setValue(&kp, pJson["kp"], "SWGKpInformation", "SWGKpInformation");
    setValue(&weather, pJson["weather"], "SWGWeatherInformation", "SWGWeatherInformation");
    setValue(&value, pJson["value"], "double", "");
    
}

QString
SWGRating::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRating::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("date"), date, obj, QString("QDateTime"));
    
    
    
    
    
    toJsonValue(QString("location"), location, obj, QString("SWGLocation"));
    
    
    
    
    
    toJsonValue(QString("locationGeomagnatic"), locationGeomagnatic, obj, QString("SWGGeomagnaticLocation"));
    
    
    
    
    
    toJsonValue(QString("kp"), kp, obj, QString("SWGKpInformation"));
    
    
    
    
    
    toJsonValue(QString("weather"), weather, obj, QString("SWGWeatherInformation"));
    
    
    
    obj->insert("value", QJsonValue(value));
    

    return obj;
}

QDateTime*
SWGRating::getDate() {
    return date;
}
void
SWGRating::setDate(QDateTime* date) {
    this->date = date;
}

SWGLocation*
SWGRating::getLocation() {
    return location;
}
void
SWGRating::setLocation(SWGLocation* location) {
    this->location = location;
}

SWGGeomagnaticLocation*
SWGRating::getLocationGeomagnatic() {
    return locationGeomagnatic;
}
void
SWGRating::setLocationGeomagnatic(SWGGeomagnaticLocation* locationGeomagnatic) {
    this->locationGeomagnatic = locationGeomagnatic;
}

SWGKpInformation*
SWGRating::getKp() {
    return kp;
}
void
SWGRating::setKp(SWGKpInformation* kp) {
    this->kp = kp;
}

SWGWeatherInformation*
SWGRating::getWeather() {
    return weather;
}
void
SWGRating::setWeather(SWGWeatherInformation* weather) {
    this->weather = weather;
}

double
SWGRating::getValue() {
    return value;
}

/*
void
SWGRating::setValue(double value) {
    this->value = value;
}*/



} /* namespace Swagger */

