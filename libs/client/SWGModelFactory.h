#ifndef ModelFactory_H_
#define ModelFactory_H_


#include "SWGOK.h"
#include "SWGError.h"
#include "SWGLocation.h"
#include "SWGGeomagnaticLocation.h"
#include "SWGKpInformation.h"
#include "SWGWeatherInformation.h"
#include "SWGRating.h"
#include "SWGNotification.h"

namespace Swagger {
  inline void* create(QString type) {
    if(QString("SWGOK").compare(type) == 0) {
      return new SWGOK();
    }
    if(QString("SWGError").compare(type) == 0) {
      return new SWGError();
    }
    if(QString("SWGLocation").compare(type) == 0) {
      return new SWGLocation();
    }
    if(QString("SWGGeomagnaticLocation").compare(type) == 0) {
      return new SWGGeomagnaticLocation();
    }
    if(QString("SWGKpInformation").compare(type) == 0) {
      return new SWGKpInformation();
    }
    if(QString("SWGWeatherInformation").compare(type) == 0) {
      return new SWGWeatherInformation();
    }
    if(QString("SWGRating").compare(type) == 0) {
      return new SWGRating();
    }
    if(QString("SWGNotification").compare(type) == 0) {
      return new SWGNotification();
    }
    
    return NULL;
  }

  inline void* create(QString json, QString type) {
    void* val = create(type);
    if(val != NULL) {
      SWGObject* obj = static_cast<SWGObject*>(val);
      return obj->fromJson(json);
    }
    if(type.startsWith("QString")) {
      return new QString();
    }
    return NULL;
  }
} /* namespace Swagger */

#endif /* ModelFactory_H_ */
