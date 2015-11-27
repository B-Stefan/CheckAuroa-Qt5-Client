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

public:
    explicit WeatherQmlData(QObject *parent = 0);

    WeatherQmlData(const WeatherQmlData &other);

    void setValue(double val);

    double getValue();

    void setDate(QDateTime &dateTime);

    QDateTime getDate();

    void setIcon(QString ico);

    QString getIcon();

    signals:

    void dataChanged();

private:
    double m_value;
    QDateTime m_date;
    QString m_icon;
};

Q_DECLARE_METATYPE(WeatherQmlData)


#endif //QT_CLIENT_WEATHERQMLDATA_H
