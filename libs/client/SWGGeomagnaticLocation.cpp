
#include "SWGGeomagnaticLocation.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGGeomagnaticLocation::SWGGeomagnaticLocation(QString* json) {
    init();
    this->fromJson(*json);
}

SWGGeomagnaticLocation::SWGGeomagnaticLocation() {
    init();
}

SWGGeomagnaticLocation::~SWGGeomagnaticLocation() {
    this->cleanup();
}

void
SWGGeomagnaticLocation::init() {
    latG = 0.0;
    lngG = 0.0;
    
}

void
SWGGeomagnaticLocation::cleanup() {
    
    
    
}

SWGGeomagnaticLocation*
SWGGeomagnaticLocation::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGGeomagnaticLocation::fromJsonObject(QJsonObject &pJson) {
    setValue(&latG, pJson["latG"], "double", "");
    setValue(&lngG, pJson["lngG"], "double", "");
    
}

QString
SWGGeomagnaticLocation::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGGeomagnaticLocation::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("latG", QJsonValue(latG));
    obj->insert("lngG", QJsonValue(lngG));
    

    return obj;
}

double
SWGGeomagnaticLocation::getLatG() {
    return latG;
}
void
SWGGeomagnaticLocation::setLatG(double latG) {
    this->latG = latG;
}

double
SWGGeomagnaticLocation::getLngG() {
    return lngG;
}
void
SWGGeomagnaticLocation::setLngG(double lngG) {
    this->lngG = lngG;
}



} /* namespace Swagger */

