#include "WeatherQmlData.h"
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

WeatherQmlData::WeatherQmlData(QObject *parent) :
        QObject(parent) {
this->m_icon = "blub";

}

WeatherQmlData::WeatherQmlData(const WeatherQmlData &other) :
        QObject(0),
        m_date(other.m_date),
        m_value(other.m_value),
        m_icon(other.m_icon),
        m_summary(other.m_summary),
        m_sunriseTime(other.m_sunriseTime),
        m_sunsetTime(other.m_sunsetTime){
this->m_icon = "blub";
}

QDateTime WeatherQmlData::getDate() {
    return  this->m_date;
}
double WeatherQmlData::getValue(){
    return this->m_value;
}

void WeatherQmlData::setDate(QDateTime &dateTime) {
    m_date = dateTime;
    emit dataChanged();
}

void WeatherQmlData::setValue(double val) {
    m_value = val;
    emit dataChanged();
}

QString WeatherQmlData::getIcon(){
    return this->m_icon;
}

void WeatherQmlData::setIcon(QString ico){
    m_icon = ico;
    emit dataChanged();
}


QString WeatherQmlData::getSummary(){
    return this->m_summary;
}

void WeatherQmlData::setSummary(QString sum){
    m_summary = sum;
    emit dataChanged();
}

qint32 WeatherQmlData::getSunsetTime(){
    return this->m_sunsetTime;
}

void WeatherQmlData::setSunsetTime(qint32 sunset){
    m_sunsetTime = sunset;
    emit dataChanged();
}

qint32 WeatherQmlData::getSunriseTime(){
    return this->m_sunriseTime;
}

void WeatherQmlData::setSunriseTime(qint32 sunrise){
    m_sunriseTime = sunrise;
    emit dataChanged();
}
