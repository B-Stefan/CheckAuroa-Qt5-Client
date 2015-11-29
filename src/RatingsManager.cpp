//
// Created by Stefan B. on 27.11.15.
//

#include <src/client/SWGRatingsApi.h>
#include "RatingsManager.h"
#include <QObject>

#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>

#include "src/client/SWGRating.h"

using namespace Swagger;

Q_LOGGING_CATEGORY(RatingsManagerLog, "wapp.RatingsManager")

class RatingsManagerPrivate {
public:
    double lat;
    double lng;
    RatingQmlData now;
    QList<RatingQmlData *> ratings;
    QQmlListProperty<RatingQmlData> *fcProp;
    bool ready;

    RatingsManagerPrivate() :
            fcProp(NULL),
            ready(false)
    {

    }
};

static void ratingsAppend(QQmlListProperty<RatingQmlData> *prop, RatingQmlData *val) {
    Q_UNUSED(val);
    Q_UNUSED(prop);
}

static RatingQmlData *ratingsAt(QQmlListProperty<RatingQmlData> *prop, int index) {
    RatingsManagerPrivate *d = static_cast<RatingsManagerPrivate *>(prop->data);
    return d->ratings.at(index);
}

static int ratingsCount(QQmlListProperty<RatingQmlData> *prop) {
    RatingsManagerPrivate *d = static_cast<RatingsManagerPrivate *>(prop->data);
    return d->ratings.size();
}

static void ratingsClear(QQmlListProperty<RatingQmlData> *prop) {
    static_cast<RatingsManagerPrivate *>(prop->data)->ratings.clear();
}


RatingsManager::RatingsManager(QObject *parent) :
        QObject(parent),
        d(new RatingsManagerPrivate) {
    d->fcProp = new QQmlListProperty<RatingQmlData>(this, d,
                                                    ratingsAppend,
                                                    ratingsCount,
                                                    ratingsAt,
                                                    ratingsClear);
    

}

RatingsManager::~RatingsManager() {
    delete d;
}


void RatingsManager::queryRatings(){
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGRatingsApi * ratingsApi = new Swagger::SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");

    connect(ratingsApi, SIGNAL(getRatingSignal(QList<SWGRating*>* )),
            this, SLOT(handleRatingsResponse(QList<SWGRating*>* )));

    ratingsApi->getRating(60.0,20.9, new QString("now"));
}


void RatingsManager::handleRatingsResponse(QList<SWGRating*>* ratings) {

    qCDebug(RatingsManagerLog) << "got weather network data";

    d->now.setValue(0.8);
    d->ready = true;

    foreach (RatingQmlData *inf, d->ratings)
            delete inf;
    d->ratings.clear();



    foreach(Swagger::SWGRating * swgRating, ratings->toVector()){
            RatingQmlData * ratingQmlData = new RatingQmlData(this);

            ratingQmlData->setDate(*swgRating->getDate());
            ratingQmlData->setValue(swgRating->getValue());

            d->ratings.append(ratingQmlData);
        }

    emit readyChanged();

}
void RatingsManager::refreshRatings() {
    this->queryRatings();
}

QQmlListProperty<RatingQmlData> RatingsManager::ratings() const {
    return *(d->fcProp);
}

bool RatingsManager::ready() const {
    return d->ready;
}

double RatingsManager::getLat() const {
    return d->lat;
}

double RatingsManager::getLng() const {
    return d->lng;
}
void RatingsManager::setLat(double lat) {
    d->lat = lat;
}
void RatingsManager::setLng(double lng) {
    d->lng = lng;
}