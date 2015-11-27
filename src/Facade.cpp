#include "Facade.h"

namespace Swagger{

    Facade::Facade()
    {

    }
        // ALT
    void Facade::setAuthor(const QString &a) {
        if (a != m_author) {
       //     QString tmp = QString::number(kpIndex);
            qDebug() << a;
            m_author = a;
            emit authorChanged();
        }
    }

    void Facade::getCurRating(SWGRating* summary){
        this->cKp = summary;
        if(cKp){
            kpIndex = cKp->getValue();
            qDebug() << cKp->getWeather()->getCloudCover() << " cloudcover";
        } else {
            kpIndex = 0;
        }
    }

    void Facade::setKpIndex(){
        if(cKp){
            kpIndex = cKp->getKp()->getKpValue();
        } else {
            kpIndex = 0;
        }
    }

    double Facade::getKpIndex(){
        qDebug() << kpIndex << "testnumber";
        return kpIndex;
    }


    QString Facade::kpIndexString() const {
        return QString::number(kpIndex) + "%";
    }

}


