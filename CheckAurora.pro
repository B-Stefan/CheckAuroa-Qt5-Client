QT += core
QT -= gui
QT += network

TARGET = CheckAurora
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += src/main.cpp
SOURCES += libs/client/SWGError.cpp
SOURCES += libs/client/SWGGeomagnaticLocation.cpp
SOURCES += libs/client/SWGHelpers.cpp
SOURCES += libs/client/SWGHttpRequest.cpp
SOURCES += libs/client/SWGKPIndexApi.cpp
SOURCES += libs/client/SWGKpInformation.cpp
SOURCES += libs/client/SWGLocation.cpp
SOURCES += libs/client/SWGLocationApi.cpp
SOURCES += libs/client/SWGNotification.cpp
SOURCES += libs/client/SWGNotifyApi.cpp
SOURCES += libs/client/SWGOK.cpp
SOURCES += libs/client/SWGRating.cpp
SOURCES += libs/client/SWGRatingsApi.cpp
SOURCES += libs/client/SWGWeatherApi.cpp
SOURCES += libs/client/SWGWeatherInformation.cpp




HEADERS += libs/client/SWGError.h
HEADERS += libs/client/SWGGeomagnaticLocation.h
HEADERS += libs/client/SWGHelpers.h
HEADERS += libs/client/SWGHttpRequest.h
HEADERS += libs/client/SWGKPIndexApi.h
HEADERS += libs/client/SWGKpInformation.h
HEADERS += libs/client/SWGLocation.h
HEADERS += libs/client/SWGLocationApi.h
HEADERS += libs/client/SWGNotification.h
HEADERS += libs/client/SWGNotifyApi.h
HEADERS += libs/client/SWGOK.h
HEADERS += libs/client/SWGRating.h
HEADERS += libs/client/SWGRatingsApi.h
HEADERS += libs/client/SWGWeatherApi.h
HEADERS += libs/client/SWGWeatherInformation.h

