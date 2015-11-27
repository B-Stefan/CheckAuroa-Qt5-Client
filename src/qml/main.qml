/*
* Papyros Calculator - A calculator application for Papyros
* Copyright (C) 2015 Pierre Jacquier
* http://pierre-jacquier.com/
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3

ApplicationWindow {
    id: calculator
    visible: true
    title: 'Calculator'
    property bool bigsize: true
    property string accentchosen: "#E91E63"
    property var history: []
    property var history_pos: history.length - 1
    height: Units.dp(300)
    minimumHeight:  Units.dp(200)
    width: bigsize ? Units.dp(400) : Units.dp(247)
    minimumWidth: bigsize ? Units.dp(280): Units.dp(247)
    maximumWidth: bigsize ? 99999999 : Units.dp(247)
    onWidthChanged: calculator.width


    theme {
        accentColor: accentchosen
        primaryColor: "#000025"
    }
    Settings {
        id: settings
        property alias x: calculator.x
        property alias y: calculator.y
        property alias width: calculator.width
        property alias height: calculator.height
        property alias accentchosen: calculator.accentchosen
        property alias bigsize: calculator.bigsize
        property alias history: calculator.history
        property alias history_pos: calculator.history_pos
    }
    initialPage: main

    MainView {
        /*PositionSource {
               id: positionSource
               onPositionChanged: { console.log("Position Changed"); }
        
               onUpdateTimeout: {
                   activityText.fadeOut = true
               }
           }*/

        TabbedPage {
            id: main
            Component.onCompleted: entry.forceActiveFocus()


            Tab {
                title: "Search by City"
                //iconName: "action/home"

                Rectangle {
                    color: Palette.colors.white["200"]

                    Button {
                        anchors.centerIn: parent
                        darkBackground: true
                        text: "Go to tab 3"
                        onClicked: {
                            model.refreshRating()
                        }
                    }
                }
            }

            Tab {
                id: currentRating
                title: "Your location"

               Rectangle {

                 /*   onVisibleChanged: {
                        if (!this.activeFocus){
        
                            if (positionSource.supportedPositioningMethods ===
                                    PositionSource.NoPositioningMethods) {
                                positionSource.nmeaSource = "nmealog.txt";
                                sourceText.text = "(filesource): " + printableMethod(positionSource.supportedPositioningMethods);
                            }
                            positionSource.update();
                            var latitude = positionSource.position.coordinate.latitude
                            var longitude = positionSource.position.coordinate.longitude
                            console.log(latitude,longitude)
                        }
                    }*/
                    CurrentRatingBigCard {

                    }

               }

            }

            Tab {
                title: "Settings"

                Rectangle { color: Palette.colors.white["200"] }
            }



        }


    }

}
