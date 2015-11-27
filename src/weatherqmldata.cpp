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

WeatherQmlData::WeatherQmlData(QObject *parent) :
        QObject(parent) {
}

WeatherQmlData::WeatherQmlData(const WeatherQmlData &other) :
        QObject(0),
        m_date(other.m_date),
        m_value(other.m_value),
        m_icon(other.m_icon){
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
