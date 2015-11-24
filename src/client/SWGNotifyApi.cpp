#include "SWGNotifyApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGNotifyApi::SWGNotifyApi() {}

SWGNotifyApi::~SWGNotifyApi() {}

SWGNotifyApi::SWGNotifyApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGNotifyApi::createNotification(SWGNotification body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/notification");

    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    

    
    
    
    QString output = body.asJson();
    input.request_body.append(output);
    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGNotifyApi::createNotificationCallback);

    worker->execute(&input);
}

void
SWGNotifyApi::createNotificationCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGOK* output = static_cast<SWGOK*>(create(json, QString("SWGOK")));
    
    
    

    worker->deleteLater();

    emit createNotificationSignal(output);
    
}
void
SWGNotifyApi::deleteNotification() {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/notification");

    

    

    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "DELETE");

    

    

    

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGNotifyApi::deleteNotificationCallback);

    worker->execute(&input);
}

void
SWGNotifyApi::deleteNotificationCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    

    
    
    
    QString json(worker->response);
    SWGOK* output = static_cast<SWGOK*>(create(json, QString("SWGOK")));
    
    
    

    worker->deleteLater();

    emit deleteNotificationSignal(output);
    
}
} /* namespace Swagger */
