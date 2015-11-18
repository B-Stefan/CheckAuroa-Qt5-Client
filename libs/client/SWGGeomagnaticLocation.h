/*
 * SWGGeomagnaticLocation.h
 * 
 * 
 */

#ifndef SWGGeomagnaticLocation_H_
#define SWGGeomagnaticLocation_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGGeomagnaticLocation: public SWGObject {
public:
    SWGGeomagnaticLocation();
    SWGGeomagnaticLocation(QString* json);
    virtual ~SWGGeomagnaticLocation();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGGeomagnaticLocation* fromJson(QString &jsonString);

    double getLatG();
    void setLatG(double latG);
    double getLngG();
    void setLngG(double lngG);
    

private:
    double latG;
    double lngG;
    
};

} /* namespace Swagger */

#endif /* SWGGeomagnaticLocation_H_ */
