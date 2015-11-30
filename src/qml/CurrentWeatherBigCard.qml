
import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3

Item {
   id:currentWeatherCard
      anchors.fill: parent

   property double lat: 0
   property double lng: 0

   state: "loading"


   states: [
       State {
           name: "loading"
           PropertyChanges { target: text1; opacity: 0 }
           PropertyChanges { target: text2; opacity: 0 }
           PropertyChanges { target: text3; opacity: 0 }
           PropertyChanges { target: image1; opacity: 0 }
           PropertyChanges { target: image2; opacity: 0 }
           PropertyChanges { target: image3; opacity: 0 }
           PropertyChanges { target: currentRatingTxt; opacity: 0 }
           PropertyChanges { target: currentRatingWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: text1; opacity: 1 }
           PropertyChanges { target: text2; opacity: 1 }
           PropertyChanges { target: text3; opacity: 1 }
           PropertyChanges { target: image1; opacity: 1 }
           PropertyChanges { target: image2; opacity: 1 }
           PropertyChanges { target: image3; opacity: 1 }
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
          var forbiddenPlatforms = ["osx" , "windows", "wince", "winrt"];
          if( forbiddenPlatforms.indexOf(Qt.platform.os) != -1 ){
              currentWeatherCard.lat = 60;
              currentWeatherCard.lng = 25;
          }
          if(currentWeatherCard.lat + currentWeatherCard.lng != 0){
              currentWeatherCard.state = "loading"
               weatherModel.refreshWeather(currentWeatherCard.lat, currentWeatherCard.lng)
          }
   }

   ProgressCircle {
      id: currentRatingWait
      anchors.centerIn: parent

   }

   Label{
       id: text1
       anchors.left: parent.left
       anchors.leftMargin: 230
       anchors.top: parent.top
       anchors.topMargin: Units.dp(100)
       text: weatherModel.currentWeather.summary
   }

   Label{
       id: text2
       anchors.left: parent.left
       anchors.leftMargin: 230
       anchors.top: parent.top
       anchors.topMargin: Units.dp(220)
       text: ("0" + new Date(weatherModel.currentWeather.sunriseTime*1000).getHours()).toLocaleString().slice(-2) + ":" + ("0" + new Date(weatherModel.currentWeather.sunriseTime*1000).getMinutes().toLocaleString()).slice(-2);
   }

   Label{
       id: text3
       anchors.left: parent.left
       anchors.leftMargin: 230
       anchors.top: parent.top
       anchors.topMargin: Units.dp(330)

       text: ("0" + new Date(weatherModel.currentWeather.sunsetTime*1000).getHours()).toLocaleString().slice(-2) + ":" + ("0" + new Date(weatherModel.currentWeather.sunsetTime*1000).getMinutes().toLocaleString()).slice(-2);
   }

   Image {
       id: image1
       anchors.top: parent.top
       anchors.topMargin: Units.dp(30)
       anchors.left: parent.left
       width: 150; height: 150
       source: "/qml/images/weather/"+weatherModel.currentWeather.icon+".svg"
   }

   Image {
       id: image2
       anchors.top: parent.top
       anchors.topMargin: Units.dp(150)
       anchors.left: parent.left
       width: 150; height: 150
       source: "/qml/images/weather/Sunrise.svg"
   }

   Image {
       id: image3
       anchors.top: parent.top
       anchors.topMargin: Units.dp(270)
       anchors.left: parent.left
       width: 150; height: 150
       source: "/qml/images/weather/Sunset.svg"
   }

}
