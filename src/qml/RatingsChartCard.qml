
import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0

import QtPositioning 5.3


import "charts/QChart.js" as Charts

import "charts/" as QCharts


Item {
   id:ratingsChartCard
   anchors.fill: parent

   property double lat: 0

   property double lng: 0

   state: "loading"

   states: [
       State {
           name: "loading"
           PropertyChanges { target: ratingsChartTxt; opacity: 0 }
           PropertyChanges { target: ratingsChartWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: ratingsChartTxt; opacity: 1 }
           PropertyChanges { target: ratingsChartWait; opacity: 0 }
       }
   ]


   Component.onCompleted: {
        var forbiddenPlatforms = ["osx" , "windows", "wince", "winrt"];
        if( forbiddenPlatforms.indexOf(Qt.platform.os) != -1 ){
            ratingsChartCard.lat = 60;
            ratingsChartCard.lng = 25;
        }
        if(ratingsChartCard.lat + ratingsChartCard.lng != 0){
            model.refreshRatings(ratingsChartCard.lat, ratingsChartCard.lng)
        }
   }
   PositionSource {
          id: positionSource
          updateInterval: 36000
          active: (ratingsChartCard.lat + ratingsChartCard.lng) != 0
          onPositionChanged: {
                      ratingsChartCard.state = "loading"
                      console.log("Position Changed" + positionSource.position.coordinate.latitude);
                      model.refreshRatings(positionSource.position.coordinate.latitude, positionSource.position.coordinate.longitude)
                }

         onUpdateTimeout: {
            console.log("TIMEOUT")
         }
   }
   RatingsManager {
       id: model
       onReadyChanged: {

           function addZero(i) {
               if (i < 10) {
                   i = "0" + i;
               }
               return i;
           }

           var labels = [];
           var kpValue  = [];
           var predictionValues =[];
           var datasets = [];
           var now = new Date();

            console.log("For start")
           for(var i = 0; i < model.ratings.length; i++){
            var m = model.ratings[i];
            var str = addZero(m.date.getHours()) +  ":" + addZero(m.date.getMinutes())
            if(m.date.getDate() == now.getDate()){
                str = str + " - Today"
            }else {
                str = str + " - Tomorrow"
            }
            labels.push(str)
            predictionValues.push(m.value);
            //predictionValues.push(Math.random()*100);

           }
           datasets.push({
                            fillColor: "rgba(0,220,0,0.5)",
                            strokeColor: "rgba(0,220,0,1)",
                            data: predictionValues
                      })

           var data = {
                 labels: labels,
                 datasets: datasets
         }

           ratingsChartCard.state = "ready"
           ratingsChartTxt.chartData = data;
       }

   }

   ProgressCircle {
      id: ratingsChartWait
      anchors.centerIn: parent

   }

   QCharts.QChart {
       anchors.centerIn: parent
       id: ratingsChartTxt;
       width: parent.width;
       height: parent.height;
       chartAnimated: true;
       chartAnimationEasing: Easing.OutBounce;
       chartAnimationDuration: 2000;
       chartType: Charts.ChartType.BAR;
     }


 


}
