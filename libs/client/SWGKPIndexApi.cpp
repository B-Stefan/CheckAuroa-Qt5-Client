#include "SWGKPIndexApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGKPIndexApi::SWGKPIndexApi() {}

SWGKPIndexApi::~SWGKPIndexApi() {}

SWGKPIndexApi::SWGKPIndexApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGKPIndexApi::getKpIndex(QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/kpIndex");

    

    
    
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
            &SWGKPIndexApi::getKpIndexCallback);

    worker->execute(&input);
}

void
SWGKPIndexApi::getKpIndexCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGKpInformation*>* output = new QList<SWGKpInformation*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGKpInformation* o = new SWGKpInformation();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }
    

    

    worker->deleteLater();

    emit getKpIndexSignal(output);
    
}
void
SWGKPIndexApi::getCurrentKpIndex(QString* uTCDateTime) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/kpIndex/current");

    

    
    
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
            &SWGKPIndexApi::getCurrentKpIndexCallback);

    worker->execute(&input);
}

void
SWGKPIndexApi::getCurrentKpIndexCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGKpInformation* output = static_cast<SWGKpInformation*>(create(json, QString("SWGKpInformation")));
    
    
    

    worker->deleteLater();

    emit getCurrentKpIndexSignal(output);
    
}
} /* namespace Swagger */
