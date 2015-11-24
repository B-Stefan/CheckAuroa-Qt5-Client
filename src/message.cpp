#include "message.h"

namespace Swagger{

    Message::Message()
    {

    }
    /*
    void Message::setAuthor(const QString &a) {
        if (a != m_author) {
            m_author = a;
            emit authorChanged();
        }
    }*/

    void Message::setAuthor(const QString &a) {
        if (a != m_author) {
            m_author = a;

           // SWGRatingsApi * ratingsApi = new SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");
           // ratingsApi->getCurrentRating(60.0,20.9, new QString("2015-10-10"));
          //  SWGRating tmp;
          //  tmp = ratingsApi->getCurrentRatingSignal();
            emit authorChanged();
        }
    }

    void Message::getCurRating(SWGRating* summary){
        this->cKp = summary;
        setKpIndex();
        qDebug() << "jackpot";
    }

    void Message::setKpIndex(){
        if(cKp){
            kpIndex = cKp->getKp()->getKpValue();
        } else {
            kpIndex = 0;
        }
    }

    double Message::getKpIndex(){
        qDebug() << kpIndex;
        return kpIndex;
    }

    /*
    QString Message::author() const {
        return m_author;
    }*/


    QString Message::author() const {
        return m_author;
    }
}


