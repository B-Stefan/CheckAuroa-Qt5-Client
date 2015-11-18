/*
 * SWGOK.h
 * 
 * 
 */

#ifndef SWGOK_H_
#define SWGOK_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGOK: public SWGObject {
public:
    SWGOK();
    SWGOK(QString* json);
    virtual ~SWGOK();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGOK* fromJson(QString &jsonString);

    QString* getMsg();
    void setMsg(QString* msg);
    

private:
    QString* msg;
    
};

} /* namespace Swagger */

#endif /* SWGOK_H_ */
