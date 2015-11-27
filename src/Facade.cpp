#include "Facade.h"

namespace Swagger{

    Facade::Facade()
    {

    }

    void Facade::writeLatitude(const QString &latt) {
        if (latt != lat) {
            lat = latt;
            qDebug() << lat;
            emit dataChanged();
        }
    }

    QString Facade::latitude() const {
        return lat;
    }

    void Facade::writeLongitude(const QString &lngg) {
        if (lngg != lng) {
            lng = lngg;
            qDebug() << lng;
            emit dataChanged();
        }
    }

    QString Facade::longitude() const {
        return lng;
    }

        // ALT
    void Facade::setAuthor(const QString &a) {
        if (a != m_author) {
       //     QString tmp = QString::number(kpIndex);
            qDebug() << a;
            m_author = a;
            emit dataChanged();
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


