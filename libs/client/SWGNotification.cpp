
#include "SWGNotification.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGNotification::SWGNotification(QString* json) {
    init();
    this->fromJson(*json);
}

SWGNotification::SWGNotification() {
    init();
}

SWGNotification::~SWGNotification() {
    this->cleanup();
}

void
SWGNotification::init() {
    playSound = false;
    
}

void
SWGNotification::cleanup() {
    
    
}

SWGNotification*
SWGNotification::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGNotification::fromJsonObject(QJsonObject &pJson) {
    setValue(&playSound, pJson["playSound"], "bool", "");
    
}

QString
SWGNotification::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGNotification::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("playSound", QJsonValue(playSound));
    

    return obj;
}

bool
SWGNotification::getPlaySound() {
    return playSound;
}
void
SWGNotification::setPlaySound(bool playSound) {
    this->playSound = playSound;
}



} /* namespace Swagger */

