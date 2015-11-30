
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
   id:searchByCity
   anchors.fill: parent

   state: "ready"

   states: [
       State {
           name: "loading"
           PropertyChanges { target: searchByCityTxt; opacity: 0 }
           PropertyChanges { target: searchByCityWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: searchByCityTxt; opacity: 1 }
           PropertyChanges { target: searchByCityWait; opacity: 0 }
       }
   ]

   ProgressCircle {
      id: searchByCityWait
      anchors.centerIn: parent

   }


    // this function is included locally, but you can also include separately via a header definition
    function request(url, callback) {
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = (function(myxhr) {
            return function() {
                callback(myxhr);
            }
        })(xhr);
        xhr.open('GET', url, true);
        xhr.send('');
    }

    OverviewPage {
        id: myCard
        visible: false
    }
    ColumnLayout{
                   spacing: 10
                   anchors.centerIn: parent


    Card {

        Layout.alignment: Qt.AlignLeft
        Layout.preferredWidth: Units.dp(400)

        ColumnLayout{
               spacing: Units.dp(10)
               anchors.centerIn: parent
               width: parent.width * 0.8
               height: parent.height * 0.8
               Label {
                   Layout.alignment: Qt.AlignLeft
                   Layout.preferredWidth: parent.width
                   text: "Search probability for your City"
                   style: "subheading"
               }

               TextField {
                id: searchByCityTxt
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: parent.width
                text: "Search for a city"
                onEditingFinished:{
                         request("https://maps.googleapis.com/maps/api/geocode/json?address=" + searchByCityTxt.text + "&sensor=false", function(response){
                              listview.model.clear();
                              var obj = JSON.parse(response.responseText)
                              console.log(JSON.stringify(obj));
                               for(var i = 0; i < obj.results.length; i++) {
                                   var item = obj.results[i]

                                   for(var r = 0; r < item.address_components.length; r++){
                                      var addPart = item.address_components[r]
                                      var index = addPart.types.indexOf("locality");
                                      console.log(addPart.long_name);
                                      if(index > -1 ){
                                          item.city = addPart.long_name;
                                          item.city_extended = addPart.short_name;
                                          break;
                                      }

                                   }

                                  listview.model.append(item)
                              }
                         })
                    }
                }

        }
    }

    Card {
        Layout.alignment: Qt.AlignLeft
        Layout.preferredWidth: Units.dp(400)

        ListModel {
                            id: model
                        }

                        ListView {
                            id: listview
                            width: parent.width
                            height: Units.dp(300)
                            model: model
                            delegate: ListItem.Subtitled {
                                  text: city
                                  subText: city_extended


                                  onClicked: {
                                    console.log("yeeeah+ " + geometry.location.lat )
                                    myCard.lat =  geometry.location.lat;
                                    myCard.lng =  geometry.location.lng;
                                    pageStack.push({item: Qt.resolvedUrl("OverviewPage.qml"),properties: {cityName:city, lat: geometry.location.lat, lng: geometry.location.lng}})
                                  }

                                  action: Icon {
                                      anchors.centerIn: parent
                                      name: "device/access_alarm"
                                      size: Units.dp(32)
                                  }
                              }

                        }
            }
      }


}
