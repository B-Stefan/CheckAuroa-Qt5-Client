/*
 * SWGError.h
 * 
 * 
 */

#ifndef SWGError_H_
#define SWGError_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGError: public SWGObject {
public:
    SWGError();
    SWGError(QString* json);
    virtual ~SWGError();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGError* fromJson(QString &jsonString);

    QString* getMsg();
    void setMsg(QString* msg);
    QString* getCode();
    void setCode(QString* code);
    

private:
    QString* msg;
    QString* code;
    
};

} /* namespace Swagger */

#endif /* SWGError_H_ */
