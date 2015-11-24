/*
 * SWGLocation.h
 * 
 * 
 */

#ifndef SWGLocation_H_
#define SWGLocation_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGLocation: public SWGObject {
public:
    SWGLocation();
    SWGLocation(QString* json);
    virtual ~SWGLocation();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGLocation* fromJson(QString &jsonString);

    double getLat();
    void setLat(double lat);
    double getLng();
    void setLng(double lng);
    

private:
    double lat;
    double lng;
    
};

} /* namespace Swagger */

#endif /* SWGLocation_H_ */
