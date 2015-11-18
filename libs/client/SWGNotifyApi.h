#ifndef _SWG_SWGNotifyApi_H_
#define _SWG_SWGNotifyApi_H_

#include "SWGHttpRequest.h"

#include "SWGNotification.h"
#include "SWGOK.h"
#include "SWGError.h"

#include <QObject>

namespace Swagger {

class SWGNotifyApi: public QObject {
    Q_OBJECT

public:
    SWGNotifyApi();
    SWGNotifyApi(QString host, QString basePath);
    ~SWGNotifyApi();

    QString host;
    QString basePath;

    void createNotification(SWGNotification body);
    void deleteNotification();
    
private:
    void createNotificationCallback (HttpRequestWorker * worker);
    void deleteNotificationCallback (HttpRequestWorker * worker);
    
signals:
    void createNotificationSignal(SWGOK* summary);
    void deleteNotificationSignal(SWGOK* summary);
    
};
}
#endif