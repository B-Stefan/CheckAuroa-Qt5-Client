/*
 * SWGNotification.h
 * 
 * 
 */

#ifndef SWGNotification_H_
#define SWGNotification_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGNotification: public SWGObject {
public:
    SWGNotification();
    SWGNotification(QString* json);
    virtual ~SWGNotification();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGNotification* fromJson(QString &jsonString);

    bool getPlaySound();
    void setPlaySound(bool playSound);
    

private:
    bool playSound;
    
};

} /* namespace Swagger */

#endif /* SWGNotification_H_ */
