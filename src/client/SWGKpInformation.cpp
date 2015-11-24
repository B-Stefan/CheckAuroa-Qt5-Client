
#include "SWGKpInformation.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGKpInformation::SWGKpInformation(QString* json) {
    init();
    this->fromJson(*json);
}

SWGKpInformation::SWGKpInformation() {
    init();
}

SWGKpInformation::~SWGKpInformation() {
    this->cleanup();
}

void
SWGKpInformation::init() {
    utc = 0;
    date = NULL;
    kpValue = 0.0;
    
}

void
SWGKpInformation::cleanup() {
    
    if(date != NULL) {
        delete date;
    }
    
    
}

SWGKpInformation*
SWGKpInformation::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGKpInformation::fromJsonObject(QJsonObject &pJson) {
    setValue(&utc, pJson["utc"], "qint32", "");
    setValue(&date, pJson["date"], "QDateTime", "QDateTime");
    setValue(&kpValue, pJson["kpValue"], "double", "");
    
}

QString
SWGKpInformation::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGKpInformation::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("utc", QJsonValue(utc));
    
    
    toJsonValue(QString("date"), date, obj, QString("QDateTime"));
    
    
    
    obj->insert("kpValue", QJsonValue(kpValue));
    

    return obj;
}

qint32
SWGKpInformation::getUtc() {
    return utc;
}
void
SWGKpInformation::setUtc(qint32 utc) {
    this->utc = utc;
}

QDateTime*
SWGKpInformation::getDate() {
    return date;
}
void
SWGKpInformation::setDate(QDateTime* date) {
    this->date = date;
}

double
SWGKpInformation::getKpValue() {
    return kpValue;
}
void
SWGKpInformation::setKpValue(double kpValue) {
    this->kpValue = kpValue;
}



} /* namespace Swagger */

