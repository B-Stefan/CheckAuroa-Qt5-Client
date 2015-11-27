#ifndef MESSAGE_H
#define MESSAGE_H

#include <qobject.h>
#include "src/client/SWGRatingsApi.h"
#include "src/client/SWGRating.h"

namespace Swagger{

class Facade : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString kpIndexString READ kpIndexString WRITE setAuthor NOTIFY authorChanged)
public:
    Facade();
public:
    void setAuthor(const QString &a);
    void setKpIndex();
    double getKpIndex();
    QString kpIndexString() const;
    QString getAuthor();
signals:
    void authorChanged();
private:
    QString m_author;
    SWGRating *cKp;
    double kpIndex = 0;
public slots:
    void getCurRating(SWGRating* summary);
};
}
#endif // MESSAGE_H


