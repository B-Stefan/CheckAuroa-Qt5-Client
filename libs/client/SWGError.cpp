
#include "SWGError.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGError::SWGError(QString* json) {
    init();
    this->fromJson(*json);
}

SWGError::SWGError() {
    init();
}

SWGError::~SWGError() {
    this->cleanup();
}

void
SWGError::init() {
    msg = new QString("");
    code = new QString("");
    
}

void
SWGError::cleanup() {
    if(msg != NULL) {
        delete msg;
    }
    if(code != NULL) {
        delete code;
    }
    
}

SWGError*
SWGError::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGError::fromJsonObject(QJsonObject &pJson) {
    setValue(&msg, pJson["msg"], "QString", "QString");
    setValue(&code, pJson["code"], "QString", "QString");
    
}

QString
SWGError::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGError::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("msg"), msg, obj, QString("QString"));
    
    
    
    
    
    toJsonValue(QString("code"), code, obj, QString("QString"));
    
    
    
    

    return obj;
}

QString*
SWGError::getMsg() {
    return msg;
}
void
SWGError::setMsg(QString* msg) {
    this->msg = msg;
}

QString*
SWGError::getCode() {
    return code;
}
void
SWGError::setCode(QString* code) {
    this->code = code;
}



} /* namespace Swagger */

