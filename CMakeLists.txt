cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0020 NEW)
set(CMAKE_PREFIX_PATH "/Volumes/Daten/Programms/Qt/5.5/clang_64/bin/")

set(PROJECT "QT-Client")

project(${PROJECT})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)


set(MACOSX_BUNDLE_BUNDLE_NAME "Example")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_COPYRIGHT "Copyright (c) 2015")
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.QTExample")
set(MACOSX_BUNDLE_ICON_FILE AppIcon.icns)


##Task 4
set(SOURCE_FILES
        ${SOURCE_FILES}
        ./src/main.cpp
        src/Facade.cpp
        src/Facade.h
        src/CurrentRatingManager.cpp
        src/CurrentRatingManager.h
        src/RatingsManager.cpp
        src/RatingsManager.h
        src/RatingQmlData.h
        src/RatingQmlData.cpp
        src/qml/main.qml
)



##Task 4
set(SOURCE_FILES
        ${SOURCE_FILES}
        src/client/SWGError.cpp
        src/client/SWGGeomagnaticLocation.cpp
        src/client/SWGHelpers.cpp
        src/client/SWGHttpRequest.cpp
        src/client/SWGKPIndexApi.cpp
        src/client/SWGKpInformation.cpp
        src/client/SWGLocation.cpp
        src/client/SWGLocationApi.cpp
        src/client/SWGNotification.cpp
        src/client/SWGNotifyApi.cpp
        src/client/SWGOK.cpp
        src/client/SWGRating.cpp
        src/client/SWGRatingsApi.cpp
        src/client/SWGWeatherApi.cpp
        src/client/SWGWeatherInformation.cpp


        src/client/SWGError.h
        src/client/SWGGeomagnaticLocation.h
        src/client/SWGHelpers.h
        src/client/SWGHttpRequest.h
        src/client/SWGKPIndexApi.h
        src/client/SWGKpInformation.h
        src/client/SWGLocation.h
        src/client/SWGLocationApi.h
        src/client/SWGModelFactory.h
        src/client/SWGNotification.h
        src/client/SWGNotifyApi.h
        src/client/SWGObject.h
        src/client/SWGOK.h
        src/client/SWGRating.h
        src/client/SWGRatingsApi.h
        src/client/SWGWeatherApi.h
        src/client/SWGWeatherInformation.h



)
set(RESOURCE ${CMAKE_SOURCE_DIR}/src/resources.qrc)
qt5_add_resources(RESOURCE_ADDED ${RESOURCE})

add_executable(${PROJECT} MACOSX_BUNDLE
                ${SOURCE_FILES}
                ${RESOURCE_ADDED})

qt5_use_modules(${PROJECT} Widgets)
qt5_use_modules(${PROJECT} Core)
qt5_use_modules(${PROJECT} WebKitWidgets)
qt5_use_modules(${PROJECT} Qml)
qt5_use_modules(${PROJECT} Positioning)
