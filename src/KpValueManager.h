//
// Created by Stefan B. on 27.11.15.
//

#ifndef QT_CLIENT_KPVALUEMANAGER_H
#define QT_CLIENT_KPVALUEMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>


#include <QtPositioning/QGeoPositionInfoSource>
#include <src/client/SWGRating.h>
#include <src/RatingQmlData.h>


using  namespace Swagger;

class KpValueManagerPrivate;

class KpValueManager : public QObject {

    Q_OBJECT
    Q_PROPERTY(bool ready
               READ ready
               NOTIFY
               readyChanged)

    Q_PROPERTY(double lat
                       READ getLat
                       WRITE setLat
                       NOTIFY
                       latChanged)
    Q_PROPERTY(double  lng
                       READ getLng
                       WRITE setLng
                       NOTIFY
                       lngChanged)

    Q_PROPERTY(QQmlListProperty<RatingQmlData> ratings
            READ ratings
            NOTIFY
    ratingsChanged)

public:
    explicit KpValueManager(QObject *parent = 0);

    ~KpValueManager();

    bool ready() const;

    double getLat() const;

    double getLng() const;

    void setLat(double lat);

    void setLng(double lng);

    QQmlListProperty<RatingQmlData> ratings() const;


public slots:
            Q_INVOKABLE void refreshRatings();

public slots:

    void queryRatings();

    void handleRatingsResponse(QList<SWGRating*>* ratings);

    signals:

        void readyChanged();

        void ratingsChanged();

        void latChanged();

        void lngChanged();


private:
    KpValueManagerPrivate *d;


};


#endif //QT_CLIENT_KPVALUEMANAGER_H
