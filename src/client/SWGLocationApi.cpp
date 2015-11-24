#include "SWGLocationApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGLocationApi::SWGLocationApi() {}

SWGLocationApi::~SWGLocationApi() {}

SWGLocationApi::SWGLocationApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGLocationApi::locationGet() {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/location");

    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGLocationApi::locationGetCallback);

    worker->execute(&input);
}

void
SWGLocationApi::locationGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    worker->deleteLater();

    
    emit locationGetSignal();
}
void
SWGLocationApi::updateLocation(QString* deviceId, QString* deviceType, double lat, double lng) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/location");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("deviceId"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(deviceId)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("deviceType"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(deviceType)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("lat"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(lat)));
    

    
    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("lng"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(lng)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGLocationApi::updateLocationCallback);

    worker->execute(&input);
}

void
SWGLocationApi::updateLocationCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    worker->deleteLater();

    
    emit updateLocationSignal();
}
} /* namespace Swagger */
