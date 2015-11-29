//
// Created by Stefan B. on 27.11.15.
//

#include "src/qmlData/KpValueQmlData.h"
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

KpValueQmlData::KpValueQmlData(QObject *parent) :
        QObject(parent) {
}

KpValueQmlData::KpValueQmlData(const KpValueQmlData &other) :
        QObject(0),
        m_date(other.m_date),
        m_value(other.m_value){
}
KpValueQmlData::KpValueQmlData(Swagger::SWGRating * other) :
        QObject(0){

}


QDateTime KpValueQmlData::getDate() {
    return  this->m_date;
}
double KpValueQmlData::getValue(){
    return this->m_value;
}

void KpValueQmlData::setDate(QDateTime &dateTime) {
    m_date = dateTime;
    emit dataChanged();
}

void KpValueQmlData::setValue(double val) {
    m_value = val;
    emit dataChanged();
}
