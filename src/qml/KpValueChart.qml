
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

   KpValueManager {
       id: model
       onReadyChanged: {

           function addZero(i) {
               if (i < 10) {
                   i = "0" + i;
               }
               return i;
           }

            function createLabel(kpValueQmlData){
                 var str = addZero(kpValueQmlData.date.getHours()) +  ":" + addZero(kpValueQmlData.date.getMinutes())

                 if(kpValueQmlData.date.getDate() == now.getDate()){
                     str = str + " - Today"
                 }else if (Math.abs(kpValueQmlData.date.getDate()-now.getDate()) == 1){
                     str = str + " - Tomorrow"
                 }else {
                    str = str   + " - "+ kpValueQmlData.date.getDate() + "." + kpValueQmlData.date.getMonth()  + "." + kpValueQmlData.date.getYear()
                 }
                 return str;
            }
           var labels = [];
           var kpValue  = [];
           var predictionValues =[];
           var datasets = [];
           var now = new Date();

            console.log("For start")
            console.log(model.kpindex.length + " length")


            var numberOfLegendEntries = 4;
            var legendSkip = Math.round(model.kpindex.length / numberOfLegendEntries)
            console.log(legendSkip)
           for(var i = 0; i < model.kpindex.length; i++){
            var m = model.kpindex[i];
            var str = " "

            if(i != 0 && i !== model.kpindex.length-1){
                if(i % legendSkip == 0){
                      str = createLabel(m)
                }
            }else if(i == model.kpindex.length-1){
                str =  createLabel(m)
            }else {
                str = createLabel(m)
            }


            labels.push(str)
            predictionValues.push(m.value);


           }
           datasets.push({    label: "My Second dataset",
                              fillColor: "rgba(151,187,205,0.2)",
                              strokeColor: "rgba(151,187,205,1)",
                              pointColor: "rgba(151,187,205,1)",
                              pointStrokeColor: "#fff",
                              pointHighlightFill: "#fff",
                              pointHighlightStroke: "rgba(151,187,205,1)",
                              data: predictionValues
                      })

           var data = {
                 labels: labels,
                 datasets: datasets
         }

           kpValueChart.state = "ready"
           kpValueChartChart.chartData = data;
           kpValueChartChart.chartOptions = {
            scaleOverride: true,
            scaleSteps: 7,
            scaleStepWidth: 1,
            scaleStartValue: 0,
           }
       }

   }
   Component.onCompleted: {
        model.refreshKPIndex()
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
       chartType: Charts.ChartType.LINE;
     }


 


}
