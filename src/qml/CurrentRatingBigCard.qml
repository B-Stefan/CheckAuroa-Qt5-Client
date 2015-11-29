
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
   id:currentRatingCard
   property double lat: 0
   property double lng: 0

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

  Component.onCompleted: {
          var forbiddenPlatforms = ["osx" , "windows", "wince", "winrt"];
          if( forbiddenPlatforms.indexOf(Qt.platform.os) != -1 ){
              currentRatingCard.lat = 60;
              currentRatingCard.lng = 25;
          }
          if(currentRatingCard.lat + currentRatingCard.lng != 0){
              model.refreshRating(currentRatingCard.lat, currentRatingCard.lng)
          }
     }
   PositionSource {
          id: positionSource
          updateInterval: 36000
          active: (currentRatingCard.lat + currentRatingCard.lng) != 0
          onPositionChanged: {
                currentRatingCard.state = "loading"
                console.log("Position Changed" + positionSource.position.coordinate.latitude);
                model.refreshRating(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
          }

          onUpdateTimeout: {
              activityText.fadeOut = true
          }
      }

   CurrentRatingManager {
       id: model
       onReadyChanged: {
           currentRatingCard.state = "ready"
       }
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
       text: (model.currentRating.value*100)  + "%"

   }

}
