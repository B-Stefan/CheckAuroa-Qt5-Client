
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
   height: Units.dp(100)

   property double lat: 0

   state: "loading"

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
                weatherModel.refreshWeather(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
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
       // weatherModel.refreshWeather(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
   }

   ProgressCircle {
      id: currentRatingWait
      anchors.centerIn: parent

   }

   Text {
       font.pixelSize: 100
       id: currentRatingTxt
       anchors.centerIn: parent
       font.pointSize: 25
     //  text: (weatherModel.currentWeather.value*100)  + "% ccover"
       text: (weatherModel.currentWeather.icon)
   }

}
