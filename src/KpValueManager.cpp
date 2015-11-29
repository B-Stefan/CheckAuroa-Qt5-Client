//
// Created by Stefan B. on 27.11.15.
//

#include <src/client/SWGKPIndexApi.h>
#include "KpValueManager.h"
#include <QObject>

#include <QSignalMapper>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>

#include "src/client/SWGKpInformation.h"
#include "src/KpValueQmlData.h"

using namespace Swagger;

Q_LOGGING_CATEGORY(KpValueManagerLog, "wapp.KpValueManager")

class KpValueManagerPrivate {
public:
    KpValueQmlData now;
    QList<KpValueQmlData *> kpindex;
    QQmlListProperty<KpValueQmlData> *fcProp;
    bool ready;

    KpValueManagerPrivate() :
            fcProp(NULL),
            ready(false)
    {

    }
};

static void kpindexAppend(QQmlListProperty<KpValueQmlData> *prop, KpValueQmlData *val) {
    Q_UNUSED(val);
    Q_UNUSED(prop);
}

static KpValueQmlData *kpindexAt(QQmlListProperty<KpValueQmlData> *prop, int index) {
    KpValueManagerPrivate *d = static_cast<KpValueManagerPrivate *>(prop->data);
    return d->kpindex.at(index);
}

static int kpindexCount(QQmlListProperty<KpValueQmlData> *prop) {
    KpValueManagerPrivate *d = static_cast<KpValueManagerPrivate *>(prop->data);
    return d->kpindex.size();
}

static void kpindexClear(QQmlListProperty<KpValueQmlData> *prop) {
    static_cast<KpValueManagerPrivate *>(prop->data)->kpindex.clear();
}


KpValueManager::KpValueManager(QObject *parent) :
        QObject(parent),
        d(new KpValueManagerPrivate) {
    d->fcProp = new QQmlListProperty<KpValueQmlData>(this, d,
                                                    kpindexAppend,
                                                    kpindexCount,
                                                    kpindexAt,
                                                    kpindexClear);
    

}

KpValueManager::~KpValueManager() {
    delete d;
}


void KpValueManager::querykpindex(){
    //don't update more often then once a minute
    //to keep load on server low

    Swagger::SWGKPIndexApi * kpindexApi = new Swagger::SWGKPIndexApi("", "http://check-aurora-api.herokuapp.com");

    connect(kpindexApi, SIGNAL(getKpIndexSignal(QList<SWGKpInformation*>* )),
            this, SLOT(handleRatingsResponse(QList<SWGKpInformation*>* )));

    kpindexApi->getKpIndex(new QString("now"));
}


void KpValueManager::handleRatingsResponse(QList<SWGKpInformation*>* kpindex) {

    qCDebug(KpValueManagerLog) << "got kp information data ";

    d->now.setValue(0.8);
    d->ready = true;

    foreach (KpValueQmlData *inf, d->kpindex)
            delete inf;
    d->kpindex.clear();


    foreach(Swagger::SWGKpInformation * swgRating, kpindex->toVector()){
            KpValueQmlData * ratingQmlData = new KpValueQmlData(this);

            ratingQmlData->setDate(*swgRating->getDate());
            ratingQmlData->setValue(swgRating->getKpValue());

            d->kpindex.append(ratingQmlData);
        }

    emit readyChanged();

}
void KpValueManager::refreshKPIndex() {
    this->querykpindex();
}

QQmlListProperty<KpValueQmlData> KpValueManager::kpindex() const {
    return *(d->fcProp);
}

bool KpValueManager::ready() const {
    return d->ready;
}
