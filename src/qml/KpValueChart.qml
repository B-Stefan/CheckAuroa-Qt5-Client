
import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0


import "charts/QChart.js" as Charts

import "charts/" as QCharts


Item {
   id:kpValueChart
   anchors.fill: parent

   property double lat: 0

   property double lng: 0

   state: "loading"

   states: [
       State {
           name: "loading"
           PropertyChanges { target: kpValueChartChart; opacity: 0 }
           PropertyChanges { target: kpValueChartWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: kpValueChartChart; opacity: 1 }
           PropertyChanges { target: kpValueChartWait; opacity: 0 }
       }
   ]

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
            console.log("For start2" + m.date.getDate() + " - ",now)
            if(m.date.getDate() == now.getDate()){
                str = str + " - Today"
                console.log("Today")
            }else {
                str = str + " - Tomorrow"
                console.log("For tomorrw")
            }
            labels.push(str)
            //predictionValue.pus(m.value);
            predictionValues.push(Math.random()*100);

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

           kpValueChart.state = "ready"
           kpValueChartChart.chartData = data;
       }

   }
   Component.onCompleted: {
        model.lng = 60;
        model.lng = 25;
        model.refreshRatings()
   }

   ProgressCircle {
      id: kpValueChartWait
      anchors.centerIn: parent

   }

   QCharts.QChart {
       anchors.centerIn: parent
       id: kpValueChartChart;
       width: parent.width;
       height: parent.height;
       chartAnimated: true;
       chartAnimationEasing: Easing.OutBounce;
       chartAnimationDuration: 2000;
       chartType: Charts.ChartType.BAR;
     }


 


}
