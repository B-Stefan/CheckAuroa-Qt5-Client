
#include "SWGOK.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGOK::SWGOK(QString* json) {
    init();
    this->fromJson(*json);
}

SWGOK::SWGOK() {
    init();
}

SWGOK::~SWGOK() {
    this->cleanup();
}

void
SWGOK::init() {
    msg = new QString("");
    
}

void
SWGOK::cleanup() {
    if(msg != NULL) {
        delete msg;
    }
    
}

SWGOK*
SWGOK::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGOK::fromJsonObject(QJsonObject &pJson) {
    setValue(&msg, pJson["msg"], "QString", "QString");
    
}

QString
SWGOK::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGOK::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("msg"), msg, obj, QString("QString"));
    
    
    
    

    return obj;
}

QString*
SWGOK::getMsg() {
    return msg;
}
void
SWGOK::setMsg(QString* msg) {
    this->msg = msg;
}



} /* namespace Swagger */

