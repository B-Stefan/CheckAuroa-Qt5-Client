#ifndef APPMODEL_H
#define APPMODEL_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>


#include <QtPositioning/QGeoPositionInfoSource>
#include <src/client/SWGRating.h>
#include <src/RatingQmlData.h>

using namespace Swagger;

class AppModelPrivate;

class CurrentRatingManager : public QObject {

    Q_OBJECT
    Q_PROPERTY(bool ready
                       READ ready
                       NOTIFY
                       readyChanged)

    Q_PROPERTY(RatingQmlData *currentRating
                       READ currentRating
                       NOTIFY
                       ratingsChanged)
    Q_PROPERTY(QQmlListProperty<RatingQmlData> ratings
                       READ ratings
                       NOTIFY
                       ratingsChanged)

public:
    explicit CurrentRatingManager(QObject *parent = 0);

    ~CurrentRatingManager();

    bool ready() const;

    QQmlListProperty<RatingQmlData> ratings() const;

    RatingQmlData *currentRating() const;

public slots:
    Q_INVOKABLE void refreshRating();

public slots:

    void queryCurrentRating();

    void queryRatings();

    void handleCurrentRatingResponse(SWGRating* summary);

signals:

    void readyChanged();

    void currentRatingChanged();

    void ratingsChanged();


private:
    AppModelPrivate *d;

};

#endif // APPMODEL_H