/*
 * SWGWeatherInformation.h
 * 
 * 
 */

#ifndef SWGWeatherInformation_H_
#define SWGWeatherInformation_H_

#include <QJsonObject>


#include "QDateTime.h"
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGWeatherInformation: public SWGObject {
public:
    SWGWeatherInformation();
    SWGWeatherInformation(QString* json);
    virtual ~SWGWeatherInformation();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGWeatherInformation* fromJson(QString &jsonString);

    QString* getIcon();
    void setIcon(QString* icon);
    double getCloudCover();
    void setCloudCover(double cloudCover);
    QString* getSummary();
    void setSummary(QString* summary);
    qint32 getSunsetTime();
    void setSunsetTime(qint32 sunsetTime);
    qint32 getSunriseTime();
    void setSunriseTime(qint32 sunriseTime);
    QDateTime* getDate();
    void setDate(QDateTime* date);
    

private:
    QString* icon;
    double cloudCover;
    QString* summary;
    qint32 sunsetTime;
    qint32 sunriseTime;
    QDateTime* date;
    
};

} /* namespace Swagger */

#endif /* SWGWeatherInformation_H_ */
