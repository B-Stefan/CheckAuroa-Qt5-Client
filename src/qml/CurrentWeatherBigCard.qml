
import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3

Card {
   id:currentWeatherCard
   anchors.centerIn: parent
   height: Units.dp(220)

   state: "loading"
  // var sunset = "";


   states: [
       State {
           name: "loading"
           PropertyChanges { target: currentRatingTxt; opacity: 0 }
           PropertyChanges { target: currentRatingWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: currentRatingTxt; opacity: 1 }
           PropertyChanges { target: currentRatingWait; opacity: 0 }
       }
   ]

   PositionSource {
          id: positionSource
          updateInterval: 36000
          active: true
          onPositionChanged: {
                console.log("Position Changed" + positionSource.position.coordinate.latitude);
                weatherModel.refreshWeather(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude);
                var sunriseDate = new Date(weatherModel.currentWeather.sunsetTime*1000);
                var sunsetDate = new Date(weatherModel.currentWeather.sunsetTime*1000);
                console.log(sunriseDate);
              //  var sunrise =   sunriseDate.getHours() + ':' + sunriseDate.getMinutes().substr(-2);
               // var sunset =    sunriseDate.getHours() + ':' + sunriseDate.getMinutes().substr(-2);
                console.log(sunrise);
          }

          onUpdateTimeout: {
              activityText.fadeOut = true
          }
      }

   CurrentWeatherManager {
       id: weatherModel
       onReadyChanged: {
           currentWeatherCard.state = "ready"
           console.log("yeeeah ready")
       }
   }
   Component.onCompleted: {
        weatherModel.refreshWeather(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
   }

   ProgressCircle {
      id: currentRatingWait
      anchors.centerIn: parent

   }

   Image {
       id: currentRatingTxt
       anchors.left: parent.left
       width: 200; height: 200
       source: "/qml/images/weather/"+weatherModel.currentWeather.icon+".svg"
   }

   Text{
       anchors.left: parent.left
       anchors.leftMargin: 200
       anchors.top: parent.top
       anchors.topMargin: 50
       font.pointSize: 25
       text: weatherModel.currentWeather.summary
   }

   Text{
       anchors.left: parent.left
       anchors.leftMargin: 200
       anchors.top: parent.top
       anchors.topMargin: 160
       font.pointSize: 25
       text: ("0" + new Date(weatherModel.currentWeather.sunriseTime*1000).getHours()).toLocaleString().slice(-2) + ":" + ("0" + new Date(weatherModel.currentWeather.sunriseTime*1000).getMinutes().toLocaleString()).slice(-2);
   }

   Text{
       anchors.left: parent.left
       anchors.leftMargin: 200
       anchors.top: parent.top
       anchors.topMargin: 270
       font.pointSize: 25
       text: ("0" + new Date(weatherModel.currentWeather.sunsetTime*1000).getHours()).toLocaleString().slice(-2) + ":" + ("0" + new Date(weatherModel.currentWeather.sunsetTime*1000).getMinutes().toLocaleString()).slice(-2);
   }

   Image {
     //  id: currentRatingTxt
       anchors.top: parent.top
       anchors.topMargin: 110
       anchors.left: parent.left
       width: 200; height: 200
       source: "/qml/images/weather/Sunrise.svg"
   }

   Image {
     //  id: currentRatingTxt
       anchors.top: parent.top
       anchors.topMargin: 220
       anchors.left: parent.left
       width: 200; height: 200
       source: "/qml/images/weather/Sunset.svg"
   }

}
