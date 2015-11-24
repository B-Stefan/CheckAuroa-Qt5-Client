#ifndef _SWG_SWGKPIndexApi_H_
#define _SWG_SWGKPIndexApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGKpInformation.h"

#include <QObject>

namespace Swagger {

class SWGKPIndexApi: public QObject {
    Q_OBJECT

public:
    SWGKPIndexApi();
    SWGKPIndexApi(QString host, QString basePath);
    ~SWGKPIndexApi();

    QString host;
    QString basePath;

    void getKpIndex(QString* uTCDateTime);
    void getCurrentKpIndex(QString* uTCDateTime);
    
private:
    void getKpIndexCallback (HttpRequestWorker * worker);
    void getCurrentKpIndexCallback (HttpRequestWorker * worker);
    
signals:
    void getKpIndexSignal(QList<SWGKpInformation*>* summary);
    void getCurrentKpIndexSignal(SWGKpInformation* summary);
    
};
}
#endif