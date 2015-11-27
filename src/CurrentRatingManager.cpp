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

//Q_LOGGING_CATEGORY(requestsLog, "wapp.requests")

class AppModelPrivate {
public:
    QString longitude, latitude;
    RatingQmlData now;
    QList<RatingQmlData *> forecast;
    QQmlListProperty<RatingQmlData> *fcProp;
    QSignalMapper *weatherReplyMapper,
                   *forecastReplyMapper;
    bool ready;

    AppModelPrivate() :
            fcProp(NULL),
            ready(false)
            {
    }
};

static void forecastAppend(QQmlListProperty<RatingQmlData> *prop, RatingQmlData *val) {
    Q_UNUSED(val);
    Q_UNUSED(prop);
}

static RatingQmlData *forecastAt(QQmlListProperty<RatingQmlData> *prop, int index) {
    AppModelPrivate *d = static_cast<AppModelPrivate *>(prop->data);
    return d->forecast.at(index);
}

static int forecastCount(QQmlListProperty<RatingQmlData> *prop) {
    AppModelPrivate *d = static_cast<AppModelPrivate *>(prop->data);
    return d->forecast.size();
}

static void forecastClear(QQmlListProperty<RatingQmlData> *prop) {
    static_cast<AppModelPrivate *>(prop->data)->forecast.clear();
}

CurrentRatingManager::CurrentRatingManager(QObject *parent) :
        QObject(parent),
        d(new AppModelPrivate) {
    d->fcProp = new QQmlListProperty<RatingQmlData>(this, d,
                                                  forecastAppend,
                                                  forecastCount,
                                                  forecastAt,
                                                  forecastClear);

    d->weatherReplyMapper = new QSignalMapper(this);
    d->forecastReplyMapper = new QSignalMapper(this);


}

CurrentRatingManager::~CurrentRatingManager() {
    delete d;
}


void CurrentRatingManager::queryCurrentRating(double lat, double lng) {
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGRatingsApi * ratingsApi = new Swagger::SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");

    connect(ratingsApi, SIGNAL(getCurrentRatingSignal(SWGRating* )),
            this, SLOT(handleCurrentRatingResponse(SWGRating* )));

    ratingsApi->getCurrentRating(lat, lng, new QString("now"));
    qDebug() << "rating done for: " + QString::number(lat) + ", " + QString::number(lng);
}


void CurrentRatingManager::handleCurrentRatingResponse(SWGRating* rating) {
   // qCDebug(requestsLog) << "got weather network data";
   // qCDebug(requestsLog) << rating->getValue();
    d->now.setValue(rating->getValue());
    d->ready = true;
    emit readyChanged();

}
void CurrentRatingManager::refreshRating(double lat, double lng) {
    this->queryCurrentRating(lat, lng);
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
