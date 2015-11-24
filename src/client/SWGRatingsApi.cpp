#include "SWGRatingsApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <qqmlapplicationengine.h>

#include <src/message.h>

namespace Swagger {
SWGRatingsApi::SWGRatingsApi() {}

SWGRatingsApi::~SWGRatingsApi() {}

SWGRatingsApi::SWGRatingsApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGRatingsApi::getRating(double lng, double lat, QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/ratings");

    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("lng"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(lng)));


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
    fullPath.append(QUrl::toPercentEncoding("uTCDateTime"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(uTCDateTime)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGRatingsApi::getRatingCallback);

    worker->execute(&input);
}

void
SWGRatingsApi::getRatingCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGRating*>* output = new QList<SWGRating*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGRating* o = new SWGRating();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit getRatingSignal(output);
    
}
void
SWGRatingsApi::getCurrentRating(double lng, double lat, QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/ratings/current");

    

    
    
    if(fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("lng"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(lng)));
    

    
    
    
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
    fullPath.append(QUrl::toPercentEncoding("uTCDateTime"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(uTCDateTime)));
    

    
    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGRatingsApi::getCurrentRatingCallback);

    worker->execute(&input);
}

void
SWGRatingsApi::getCurrentRatingCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    QString json(worker->response);
    SWGRating* output = static_cast<SWGRating*>(create(json, QString("SWGRating")));
    
    double tmp = output->getKp()->getKpValue();

    qDebug() << tmp;
    qDebug() << "trigger";

    worker->deleteLater();

    emit getCurrentRatingSignal(output);
    
}
} /* namespace Swagger */
