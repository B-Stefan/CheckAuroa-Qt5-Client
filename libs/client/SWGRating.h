/*
 * SWGRating.h
 * 
 * 
 */

#ifndef SWGRating_H_
#define SWGRating_H_

#include <QJsonObject>


#include "QDateTime.h"
#include "SWGWeatherInformation.h"
#include "SWGGeomagnaticLocation.h"
#include "SWGLocation.h"
#include "SWGKpInformation.h"

#include "SWGObject.h"


namespace Swagger {

class SWGRating: public SWGObject {
public:
    SWGRating();
    SWGRating(QString* json);
    virtual ~SWGRating();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGRating* fromJson(QString &jsonString);

    QDateTime* getDate();
    void setDate(QDateTime* date);
    SWGLocation* getLocation();
    void setLocation(SWGLocation* location);
    SWGGeomagnaticLocation* getLocationGeomagnatic();
    void setLocationGeomagnatic(SWGGeomagnaticLocation* locationGeomagnatic);
    SWGKpInformation* getKp();
    void setKp(SWGKpInformation* kp);
    SWGWeatherInformation* getWeather();
    void setWeather(SWGWeatherInformation* weather);
    double getValue();
    void setValue(double value);
    

private:
    QDateTime* date;
    SWGLocation* location;
    SWGGeomagnaticLocation* locationGeomagnatic;
    SWGKpInformation* kp;
    SWGWeatherInformation* weather;
    double value;
    
};

} /* namespace Swagger */

#endif /* SWGRating_H_ */
