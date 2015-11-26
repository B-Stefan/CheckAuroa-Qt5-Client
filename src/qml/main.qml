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
//import QtQuick.Controls 1.3 as Controls
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
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
    onWidthChanged: drawer.close()
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

    PositionSource {
           id: positionSource
           onPositionChanged: { console.log("Position Changed"); }

           onUpdateTimeout: {
               activityText.fadeOut = true
           }
       }

    TabbedPage {
        id: main
        Component.onCompleted: entry.forceActiveFocus()

        Tab {
            title: "Search by City"
            iconName: "action/home"

            Rectangle {
                color: Palette.colors.white["200"]

                Button {
                    anchors.centerIn: parent
                    darkBackground: true
                    text: "Go to tab 3"
                    onClicked: main.selectedTab = 2
                }
            }
        }

        Tab {
            title: "Current KP Index"



            Rectangle { color: Palette.colors.white["200"]

                Text {
                    anchors.centerIn: parent
                    font.pointSize: 25
                    text: msg.kpIndexString
                    Component.onCompleted: {
                        msg.latitude = positionSource.position.coordinate.latitude
                        msg.longitude = positionSource.position.coordinate.longitude
                        msg.kpIndexString = "Jonah"  // invokes Message::setAuthor()
                        positionSource.position.coordinate;
                    }

                }

            }
        }

        Tab {
            title: "Settings"

            Rectangle { color: Palette.colors.white["200"]

                Button {
                        id: locateButton
                        text: "Locate & update"
                        anchors {left: parent.left; leftMargin: 5}
                        y: 3; height: 32; width: parent.width - 10
                        onClicked: {
                            if (positionSource.supportedPositioningMethods ===
                                    PositionSource.NoPositioningMethods) {
                                positionSource.nmeaSource = "nmealog.txt";
                                sourceText.text = "(filesource): " + printableMethod(positionSource.supportedPositioningMethods);
                            }
                            positionSource.update();
                            var coord = positionSource.position.coordinate;
                            console.log("Coordinate:", coord.longitude, coord.latitude);
                            msg.coords = 50
                        }

                }
            }



        }
    }
}
