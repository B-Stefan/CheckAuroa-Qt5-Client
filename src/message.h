#ifndef MESSAGE_H
#define MESSAGE_H

#include <qobject.h>
#include "src/client/SWGRatingsApi.h"
#include "src/client/SWGRating.h"

namespace Swagger{

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString  kpIndexString   READ kpIndexString      WRITE setAuthor         NOTIFY  dataChanged)
    Q_PROPERTY(QString  latitude        READ latitude           WRITE writeLatitude     NOTIFY  dataChanged)
    Q_PROPERTY(QString  longitude       READ longitude          WRITE writeLongitude    NOTIFY  dataChanged)
public:
    Message();
public:
    void setAuthor(const QString &a);
    void setKpIndex();
    double getKpIndex();
    QString kpIndexString() const;
    QString latitude() const;
    QString longitude() const;
    QString getAuthor();
    void writeLatitude  (const QString &latt);
    void writeLongitude (const QString &lngg);
signals:
    void dataChanged();
private:
    QString m_author;
    SWGRating *cKp;
    double kpIndex = 0;
    QString lat;
    QString lng;
public slots:
    void getCurRating(SWGRating* summary);
};
}
#endif // MESSAGE_H


