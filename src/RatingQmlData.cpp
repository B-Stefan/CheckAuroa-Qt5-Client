//
// Created by Stefan B. on 27.11.15.
//

#include "RatingQmlData.h"

RatingQmlData::RatingQmlData(QObject *parent) :
        QObject(parent) {
}

RatingQmlData::RatingQmlData(const RatingQmlData &other) :
        QObject(0),
        m_date(other.m_date),
        m_value(other.m_value){
}

QDateTime RatingQmlData::getDate() {
    return  this->m_date;
}
double RatingQmlData::getValue(){
    return this->m_value;
}

void RatingQmlData::setDate(QDateTime &dateTime) {
    m_date = dateTime;
    emit dataChanged();
}

void RatingQmlData::setValue(double val) {
    m_value = val;
    emit dataChanged();
}