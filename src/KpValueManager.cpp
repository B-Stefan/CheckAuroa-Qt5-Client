//
// Created by Stefan B. on 27.11.15.
//

#include <src/client/SWGRatingsApi.h>
#include "KpValueManager.h"
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

Q_LOGGING_CATEGORY(KpValueManagerLog, "wapp.KpValueManager")

class KpValueManagerPrivate {
public:
    double lat;
    double lng;
    RatingQmlData now;
    QList<RatingQmlData *> ratings;
    QQmlListProperty<RatingQmlData> *fcProp;
    bool ready;

    KpValueManagerPrivate() :
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
    KpValueManagerPrivate *d = static_cast<KpValueManagerPrivate *>(prop->data);
    return d->ratings.at(index);
}

static int ratingsCount(QQmlListProperty<RatingQmlData> *prop) {
    KpValueManagerPrivate *d = static_cast<KpValueManagerPrivate *>(prop->data);
    return d->ratings.size();
}

static void ratingsClear(QQmlListProperty<RatingQmlData> *prop) {
    static_cast<KpValueManagerPrivate *>(prop->data)->ratings.clear();
}


KpValueManager::KpValueManager(QObject *parent) :
        QObject(parent),
        d(new KpValueManagerPrivate) {
    d->fcProp = new QQmlListProperty<RatingQmlData>(this, d,
                                                    ratingsAppend,
                                                    ratingsCount,
                                                    ratingsAt,
                                                    ratingsClear);
    

}

KpValueManager::~KpValueManager() {
    delete d;
}


void KpValueManager::queryRatings(){
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGRatingsApi * ratingsApi = new Swagger::SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");

    connect(ratingsApi, SIGNAL(getRatingSignal(QList<SWGRating*>* )),
            this, SLOT(handleRatingsResponse(QList<SWGRating*>* )));

    ratingsApi->getRating(60.0,20.9, new QString("now"));
}


void KpValueManager::handleRatingsResponse(QList<SWGRating*>* ratings) {

    qCDebug(KpValueManagerLog) << "got weather network data";

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
void KpValueManager::refreshRatings() {
    this->queryRatings();
}

QQmlListProperty<RatingQmlData> KpValueManager::ratings() const {
    return *(d->fcProp);
}

bool KpValueManager::ready() const {
    return d->ready;
}

double KpValueManager::getLat() const {
    return d->lat;
}

double KpValueManager::getLng() const {
    return d->lng;
}
void KpValueManager::setLat(double lat) {
    d->lat = lat;
}
void KpValueManager::setLng(double lng) {
    d->lng = lng;
}