#ifndef MESSAGE_H
#define MESSAGE_H

#include <qobject.h>
#include "src/client/SWGRatingsApi.h"
#include "src/client/SWGRating.h"

namespace Swagger{

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
public:
    Message();
public:
    void setAuthor(const QString &a);
    void setKpIndex();
    double getKpIndex();
    QString author() const;
signals:
    void authorChanged();
private:
    QString m_author;
    double kpIndex = 0;
    SWGRating *cKp;
public slots:
    void getCurRating(SWGRating* summary);
};
}
#endif // MESSAGE_H


