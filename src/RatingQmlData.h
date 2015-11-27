//
// Created by Stefan B. on 27.11.15.
//

#ifndef QT_CLIENT_RATINGQMLDATA_H
#define QT_CLIENT_RATINGQMLDATA_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>


class RatingQmlData : public QObject {
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
    explicit RatingQmlData(QObject *parent = 0);

    RatingQmlData(const RatingQmlData &other);

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

Q_DECLARE_METATYPE(RatingQmlData)


#endif //QT_CLIENT_RATINGQMLDATA_H
