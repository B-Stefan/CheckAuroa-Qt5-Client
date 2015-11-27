#ifndef _SWG_SWGRatingsApi_H_
#define _SWG_SWGRatingsApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGRating.h"
#include "SWGError.h"

#include <QObject>

namespace Swagger {

class SWGRatingsApi: public QObject {
    Q_OBJECT

public:
    SWGRatingsApi();
    SWGRatingsApi(QString host, QString basePath);
    ~SWGRatingsApi();

    QString host;
    QString basePath;

    void getRating(double lng, double lat, QString* uTCDateTime);
    void getCurrentRating(double lng, double lat, QString* uTCDateTime);
    
private:
    void getRatingCallback (HttpRequestWorker * worker);
    void getCurrentRatingCallback (HttpRequestWorker * worker);

signals:
    void getRatingSignal(QList<SWGRating*>* summary);
    void getCurrentRatingSignal(SWGRating* summary);
};
}
#endif
