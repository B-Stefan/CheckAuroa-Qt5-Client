QT += quick qml
QT += widgets
QT += svg
QTPLUGIN += qsvg



SOURCES += src/main.cpp \
    src/client/SWGError.cpp \
    src/client/SWGGeomagnaticLocation.cpp \
    src/client/SWGHelpers.cpp \
    src/client/SWGHttpRequest.cpp \
    src/client/SWGKPIndexApi.cpp \
    src/client/SWGKpInformation.cpp \
    src/client/SWGLocation.cpp \
    src/client/SWGLocationApi.cpp \
    src/client/SWGNotification.cpp \
    src/client/SWGNotifyApi.cpp \
    src/client/SWGOK.cpp \
    src/client/SWGRating.cpp \
    src/client/SWGRatingsApi.cpp \
    src/client/SWGWeatherApi.cpp \
    src/client/SWGWeatherInformation.cpp \
    src/qmlData/RatingQmlData.cpp \
    src/qmlData/WeatherQmlData.cpp \
    src/qmlData/KpValueQmlData.cpp \
    src/qmlManager/CurrentWeatherManager.cpp \
    src/qmlManager/RatingsManager.cpp \
    src/qmlManager/CurrentRatingManager.cpp \
    src/qmlManager/KpValueManager.cpp

OTHER_FILES = README.md

RESOURCES += src/resources.qrc

CONFIG += staticlib

target.path = /usr/bin

RC_ICONS += icons/check-aurora.ico
ICON += icons/check-aurora.icns

HEADERS += \
    src/client/SWGError.h \
    src/client/SWGGeomagnaticLocation.h \
    src/client/SWGHelpers.h \
    src/client/SWGHttpRequest.h \
    src/client/SWGKPIndexApi.h \
    src/client/SWGKpInformation.h \
    src/client/SWGLocation.h \
    src/client/SWGLocationApi.h \
    src/client/SWGModelFactory.h \
    src/client/SWGNotification.h \
    src/client/SWGNotifyApi.h \
    src/client/SWGObject.h \
    src/client/SWGOK.h \
    src/client/SWGRating.h \
    src/client/SWGRatingsApi.h \
    src/client/SWGWeatherApi.h \
    src/client/SWGWeatherInformation.h \
    src/qmlData/RatingQmlData.h \
    src/qmlData/WeatherQmlData.h \
    src/qmlData/KpValueQmlData.h \
    src/qmlManager/CurrentWeatherManager.h \
    src/qmlManager/RatingsManager.h \
    src/qmlManager/CurrentRatingManager.h \
    src/qmlManager/KpValueManager.h \
