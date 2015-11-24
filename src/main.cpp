/*
* Papyros Calculator - A calculator application for Papyros
* Copyright (C) 2015 Pierre Jacquier
* http://pierre-jacquier.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QT_NO_WIDGETS
#include <QtWidgets/QApplication>
typedef QApplication Application;
#else
#include <QtGui/QGuiApplication>
typedef QGuiApplication Application;
#endif
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include <QLabel>
#include <QCoreApplication>
#include <QObject>
#include "src/client/SWGRatingsApi.h"
#include "src/client/SWGRating.h"
#include "src/message.h"
#include <QQmlComponent>
#include <QQmlEngine>

using namespace Swagger;

int main(int argc, char **argv)
{
        Application app(argc, argv);


        QQmlApplicationEngine appEngine;
        Message * msg = new Message();
        SWGRatingsApi * ratingsApi = new SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");
        ratingsApi->getCurrentRating(60.0,20.9, new QString("2015-10-10"));

       // QObject::connect(&ratingsApi, SIGNAL(getCurrentRatingSignal(SWGRating)),
       //                  &msg, SLOT(getCurRating(SWGRating)));

        QObject::connect(ratingsApi, &ratingsApi->getCurrentRatingSignal, msg, &msg->getCurRating);
        qDebug() << msg->getKpIndex();


        appEngine.rootContext()->setContextProperty("msg", msg->getKpIndex());
        QQmlComponent component(&appEngine, QUrl("qrc:/qml/main.qml"));



        qDebug() << component.errors();

        if (component.isReady()){
            component.create();
            qDebug() << "created";
        }

        qDebug() << component.objectName();

        return app.exec();
}

