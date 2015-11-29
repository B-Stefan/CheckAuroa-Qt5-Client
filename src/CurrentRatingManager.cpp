#include "CurrentRatingManager.h"

#include "src/client/SWGRatingsApi.h"
#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>


using  namespace Swagger;

Q_LOGGING_CATEGORY(requestsLog, "wapp.CurrentRatingManager")

class AppModelPrivate {
public:
    QString longitude, latitude;
    RatingQmlData now;
    QList<RatingQmlData *> forecast;
    QQmlListProperty<RatingQmlData> *fcProp;

    bool ready;

    AppModelPrivate() :
            fcProp(NULL),
            ready(false)
            {
    }
};


CurrentRatingManager::CurrentRatingManager(QObject *parent) :
        QObject(parent),
        d(new AppModelPrivate) {


}

CurrentRatingManager::~CurrentRatingManager() {
    delete d;
}


void CurrentRatingManager::queryCurrentRating() {
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGRatingsApi * ratingsApi = new Swagger::SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");

    connect(ratingsApi, SIGNAL(getCurrentRatingSignal(SWGRating* )),
            this, SLOT(handleCurrentRatingResponse(SWGRating* )));

    ratingsApi->getCurrentRating(60.0,20.9, new QString("now"));
}


void CurrentRatingManager::handleCurrentRatingResponse(SWGRating* rating) {
    d->now.setValue(0.8);
    d->ready = true;
    emit readyChanged();

}
void CurrentRatingManager::refreshRating() {
    this->queryCurrentRating();
}
RatingQmlData *CurrentRatingManager::currentRating() const {
    return &(d->now);
}

QQmlListProperty<RatingQmlData> CurrentRatingManager::ratings() const {
    return *(d->fcProp);
}

bool CurrentRatingManager::ready() const {
    return d->ready;
}

void CurrentRatingManager::queryRatings() {

}
