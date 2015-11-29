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
#include <src/client/SWGKpInformation.h>
#include <src/KpValueQmlData.h>


using  namespace Swagger;

class KpValueManagerPrivate;

class KpValueManager : public QObject {

    Q_OBJECT
    Q_PROPERTY(bool ready
               READ ready
               NOTIFY
               readyChanged)

    Q_PROPERTY(QQmlListProperty<KpValueQmlData> kpindex
            READ kpindex
            NOTIFY
    kpIndexChanged)

public:
    explicit KpValueManager(QObject *parent = 0);

    ~KpValueManager();

    bool ready() const;


    QQmlListProperty<KpValueQmlData> kpindex() const;


public slots:
            Q_INVOKABLE void refreshKPIndex();

public slots:

    void querykpindex();

    void handleRatingsResponse(QList<SWGKpInformation*>* ratings);

    signals:

        void readyChanged();

        void kpIndexChanged();


private:
    KpValueManagerPrivate *d;


};


#endif //QT_CLIENT_KPVALUEMANAGER_H
