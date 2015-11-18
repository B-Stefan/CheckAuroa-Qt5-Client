#include "SWGWeatherApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGWeatherApi::SWGWeatherApi() {}

SWGWeatherApi::~SWGWeatherApi() {}

SWGWeatherApi::SWGWeatherApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGWeatherApi::getWeatherPrediction(double lat, double lng, QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/weather");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("uTCDateTime"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(uTCDateTime)));
    

    
    
    
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
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGWeatherApi::getWeatherPredictionCallback);

    worker->execute(&input);
}

void
SWGWeatherApi::getWeatherPredictionCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGWeatherInformation*>* output = new QList<SWGWeatherInformation*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGWeatherInformation* o = new SWGWeatherInformation();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit getWeatherPredictionSignal(output);
    
}
void
SWGWeatherApi::getWeatherCurrent(double lat, double lng, QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/weather/current");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("uTCDateTime"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(uTCDateTime)));
    

    
    
    
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
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGWeatherApi::getWeatherCurrentCallback);

    worker->execute(&input);
}

void
SWGWeatherApi::getWeatherCurrentCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGWeatherInformation* output = static_cast<SWGWeatherInformation*>(create(json, QString("SWGWeatherInformation")));
    
    
    

    worker->deleteLater();

    emit getWeatherCurrentSignal(output);
    
}
} /* namespace Swagger */
