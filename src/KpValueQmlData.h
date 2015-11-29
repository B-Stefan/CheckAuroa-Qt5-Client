#ifndef QT_CLIENT_KPVALUEQMLDATA_H
#define QT_CLIENT_KPVALUEQMLDATA_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>
#include "src/client/SWGRating.h"

class KpValueQmlData : public QObject {
    Q_OBJECT
            Q_PROPERTY(QDateTime date
                       READ getDate
                       WRITE setDate
                       NOTIFY
                       dataChanged)
    Q_PROPERTY(double value
               READ getValue
               WRITE setValue
               NOTIFY
               dataChanged)


public:
    explicit KpValueQmlData(QObject *parent = 0);

    KpValueQmlData(const KpValueQmlData &other);
    KpValueQmlData(Swagger::SWGRating *rating);

    void setValue(double val);

    double getValue();

    void setDate(QDateTime &dateTime);

    QDateTime getDate();

    signals:

    void dataChanged();

private:
    double m_value;
    QDateTime m_date;


};

Q_DECLARE_METATYPE(KpValueQmlData)


#endif //QT_CLIENT_KPVALUEQMLDATA_H
