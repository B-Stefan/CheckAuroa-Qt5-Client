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
#include "src/qmlManager/CurrentRatingManager.h"
#include "src/qmlManager/RatingsManager.h"
#include "src/qmlManager/CurrentWeatherManager.h"
#include <QQmlComponent>
#include <QQmlEngine>
#include <QtQuick>

#include "src/qmlData/RatingQmlData.h"
#include "src/qmlManager/KpValueManager.h"
#include "src/qmlData/KpValueQmlData.h"
#include "src/qmlData/weatherqmldata.h"
using namespace Swagger;

int main(int argc, char **argv)
{
        Application app(argc, argv);

        //Ratings
        qmlRegisterType<RatingQmlData>("CheckAurora", 1, 0, "RatingQmlData");
        qmlRegisterType<CurrentRatingManager>("CheckAurora", 1, 0, "CurrentRatingManager");
        qmlRegisterType<RatingsManager>("CheckAurora", 1, 0, "RatingsManager");

        //Weather
        qmlRegisterType<WeatherQmlData>("CheckAurora", 1, 0, "WeatherQmlData");
        qmlRegisterType<CurrentWeatherManager>("CheckAurora", 1, 0, "CurrentWeatherManager");


        //KP Information
        qmlRegisterType<KpValueManager>("CheckAurora", 1, 0, "KpValueManager");
        qmlRegisterType<KpValueQmlData>("CheckAurora", 1, 0, "KpValueQmlData");

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

