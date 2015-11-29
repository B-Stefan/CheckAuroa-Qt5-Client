#ifndef QT_CLIENT_WEATHERQMLDATA_H
#define QT_CLIENT_WEATHERQMLDATA_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>
#include <QtQml/QQmlListProperty>

class WeatherQmlData : public QObject {
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

    Q_PROPERTY(QString icon
               READ getIcon
               WRITE setIcon
               NOTIFY
               dataChanged)
    Q_PROPERTY(QString summary
               READ getSummary
               WRITE setSummary
               NOTIFY
               dataChanged)
    Q_PROPERTY(qint32 sunsetTime
               READ getSunsetTime
               WRITE setSunsetTime
               NOTIFY
               dataChanged)
    Q_PROPERTY(qint32 sunriseTime
               READ getSunriseTime
               WRITE setSunriseTime
               NOTIFY
               dataChanged)

public:
    explicit WeatherQmlData(QObject *parent = 0);

    WeatherQmlData(const WeatherQmlData &other);

    void setValue(double val);

    double getValue();

    void setDate(QDateTime &dateTime);

    QDateTime getDate();

    void setIcon(QString ico);

    QString getIcon();

    QString getSummary();

    void setSummary(QString sum);

    qint32 getSunsetTime();

    void setSunsetTime(qint32 sunset);

    qint32 getSunriseTime();

    void setSunriseTime(qint32 sunrise);


    signals:

    void dataChanged();

private:
    double m_value;
    QDateTime m_date;
    QString m_icon;
    QString m_summary;
    qint32 m_sunsetTime;
    qint32 m_sunriseTime;
};

Q_DECLARE_METATYPE(WeatherQmlData)


#endif //QT_CLIENT_WEATHERQMLDATA_H
