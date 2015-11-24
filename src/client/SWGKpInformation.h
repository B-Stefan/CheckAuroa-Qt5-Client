/*
 * SWGKpInformation.h
 * 
 * 
 */

#ifndef SWGKpInformation_H_
#define SWGKpInformation_H_

#include <QJsonObject>


#include "QDateTime.h"

#include "SWGObject.h"


namespace Swagger {

class SWGKpInformation: public SWGObject {
public:
    SWGKpInformation();
    SWGKpInformation(QString* json);
    virtual ~SWGKpInformation();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGKpInformation* fromJson(QString &jsonString);

    qint32 getUtc();
    void setUtc(qint32 utc);
    QDateTime* getDate();
    void setDate(QDateTime* date);
    double getKpValue();
    void setKpValue(double kpValue);
    

private:
    qint32 utc;
    QDateTime* date;
    double kpValue;
    
};

} /* namespace Swagger */

#endif /* SWGKpInformation_H_ */
