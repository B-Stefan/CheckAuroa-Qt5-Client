#include "message.h"

namespace Swagger{

    Message::Message()
    {

    }
        // ALT
    void Message::setAuthor(const QString &a) {
        if (a != m_author) {
       //     QString tmp = QString::number(kpIndex);
            qDebug() << a;
            m_author = a;
            emit authorChanged();
        }
    }

    void Message::getCurRating(SWGRating* summary){
        this->cKp = summary;
        if(cKp){
            kpIndex = cKp->getValue();
            qDebug() << cKp->getWeather()->getCloudCover() << " cloudcover";
        } else {
            kpIndex = 0;
        }
    }

    void Message::setKpIndex(){
        if(cKp){
            kpIndex = cKp->getKp()->getKpValue();
        } else {
            kpIndex = 0;
        }
    }

    double Message::getKpIndex(){
        qDebug() << kpIndex << "testnumber";
        return kpIndex;
    }

    QString Message::getAuthor(){
        return m_author;
    }

    QString Message::kpIndexString() const {
        return QString::number(kpIndex) + "%";
    }
}


