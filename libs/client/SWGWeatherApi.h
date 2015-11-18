#ifndef _SWG_SWGWeatherApi_H_
#define _SWG_SWGWeatherApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGWeatherInformation.h"

#include <QObject>

namespace Swagger {

class SWGWeatherApi: public QObject {
    Q_OBJECT

public:
    SWGWeatherApi();
    SWGWeatherApi(QString host, QString basePath);
    ~SWGWeatherApi();

    QString host;
    QString basePath;

    void getWeatherPrediction(double lat, double lng, QString* uTCDateTime);
    void getWeatherCurrent(double lat, double lng, QString* uTCDateTime);
    
private:
    void getWeatherPredictionCallback (HttpRequestWorker * worker);
    void getWeatherCurrentCallback (HttpRequestWorker * worker);
    
signals:
    void getWeatherPredictionSignal(QList<SWGWeatherInformation*>* summary);
    void getWeatherCurrentSignal(SWGWeatherInformation* summary);
    
};
}
#endif