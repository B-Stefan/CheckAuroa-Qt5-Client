
#include "SWGLocation.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGLocation::SWGLocation(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLocation::SWGLocation() {
    init();
}

SWGLocation::~SWGLocation() {
    this->cleanup();
}

void
SWGLocation::init() {
    lat = 0.0;
    lng = 0.0;
    
}

void
SWGLocation::cleanup() {
    
    
    
}

SWGLocation*
SWGLocation::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLocation::fromJsonObject(QJsonObject &pJson) {
    setValue(&lat, pJson["lat"], "double", "");
    setValue(&lng, pJson["lng"], "double", "");
    
}

QString
SWGLocation::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGLocation::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("lat", QJsonValue(lat));
    obj->insert("lng", QJsonValue(lng));
    

    return obj;
}

double
SWGLocation::getLat() {
    return lat;
}
void
SWGLocation::setLat(double lat) {
    this->lat = lat;
}

double
SWGLocation::getLng() {
    return lng;
}
void
SWGLocation::setLng(double lng) {
    this->lng = lng;
}



} /* namespace Swagger */

