#ifndef _SWG_SWGLocationApi_H_
#define _SWG_SWGLocationApi_H_

#include "SWGHttpRequest.h"

#include <QString>

#include <QObject>

namespace Swagger {

class SWGLocationApi: public QObject {
    Q_OBJECT

public:
    SWGLocationApi();
    SWGLocationApi(QString host, QString basePath);
    ~SWGLocationApi();

    QString host;
    QString basePath;

    void locationGet();
    void updateLocation(QString* deviceId, QString* deviceType, double lat, double lng);
    
private:
    void locationGetCallback (HttpRequestWorker * worker);
    void updateLocationCallback (HttpRequestWorker * worker);
    
signals:
    void locationGetSignal();
    void updateLocationSignal();
    
};
}
#endif