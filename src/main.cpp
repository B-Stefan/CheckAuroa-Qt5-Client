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
#include "CurrentRatingManager.h"
#include <QQmlComponent>
#include <QQmlEngine>

#include "RatingQmlData.h"
using namespace Swagger;

int main(int argc, char **argv)
{
        Application app(argc, argv);

        qmlRegisterType<RatingQmlData>("CheckAurora", 1, 0, "RatingQmlData");
        qmlRegisterType<CurrentRatingManager>("CheckAurora", 1, 0, "CurrentRatingManager");

        SWGRatingsApi * ratingsApi = new SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");
        ratingsApi->getCurrentRating(60.0,20.9, new QString("now"));
        QObject::connect(ratingsApi, SIGNAL(Swagger::SWGRatingsApi::getCurrentRatingSignal(SWGRating* summary)), msg, SLOT(Swagger::Message::getCurRating(SWGRating* summary)));

        QQmlApplicationEngine appEngine;

        //appEngine.rootContext()->setContextProperty("msg", &*facade);
        QQmlComponent component(&appEngine, QUrl("qrc:/qml/main.qml"));



       // qDebug() << component.errors();

        if (component.isReady()){
            component.create();
            qDebug() <<   " created";
        }

        return app.exec();
}

