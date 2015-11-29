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
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3
import QtQuick.Layouts 1.1



ApplicationWindow {
    id: calculator
    visible: true
    title: 'Calculator'
    property bool bigsize: true
    property string accentchosen: "#E91E63"
    property var history: []
    property var history_pos: history.length - 1
    height: Screen.height
    minimumHeight:  Units.dp(200)
    width: Screen.width
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
                anchors.fill: parent
                Controls.ScrollView
                    {
                        anchors.fill: parent

                        ColumnLayout {     // <--- unique child
                            spacing: 30

                            width: calculator.width      // ensure correct width
                            height: children.height     // ensure correct height

                            Card {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: Units.dp(400)
                                Layout.preferredHeight: Units.dp(200)
                                ColumnLayout{
                                   spacing: Units.dp(10)
                                   anchors.centerIn: parent
                                   width: parent.width * 0.8
                                   height: parent.height * 0.8
                                   Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: 40
                                       text: "Live Aurora probability"
                                       style: "subheading"
                                   }

                                   Rectangle {
                                       Layout.alignment: Qt.AlignCenter
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: parent.height
                                       CurrentRatingBigCard {
                                          anchors.centerIn: parent
                                          Layout.alignment: Qt.AlignHCenter
                                          width: parent.width
                                      }
                                   }
                               }

                            }

                            Card {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: Units.dp(400)
                                Layout.preferredHeight: Units.dp(500)
                                ColumnLayout{
                                   spacing: Units.dp(10)
                                   anchors.centerIn: parent
                                   width: parent.width * 0.8
                                   height: parent.height * 0.8
                                   Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: 40
                                       text: "Probability next 24 hours"
                                       style: "subheading"
                                   }
                                    Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: Units.dp(100)
                                       wrapMode: Text.WordWrap
                                       text: "The chart below represents the possibilty to see the Aurora Borealis at your location in the next 24 hours. The data is provided by different forecast services to give you the most accurate prediction. Keep in mind that even though we are trying our best to be on point with our prediction, there is no guarantee."
                                   }

                                   Rectangle {
                                       Layout.alignment: Qt.AlignCenter
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: Units.dp(200)
                                       RatingsChartCard {
                                        width:parent.width
                                        height: parent.height
                                       }
                                   }
                               }

                            }

                            Card {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: Units.dp(400)
                                Layout.preferredHeight: Units.dp(500)
                                ColumnLayout{
                                   spacing: Units.dp(10)
                                   anchors.centerIn: parent
                                   width: parent.width * 0.8
                                   height: parent.height * 0.8
                                   Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: 40
                                       text: "Kp Index next 24 hours"
                                       style: "subheading"
                                   }
                                    Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: Units.dp(100)
                                       wrapMode: Text.WordWrap
                                       text: "The Kp-Index represents the overall sun-activity and therefore the intensity of solar flares. A high Kp-Number means, that the Aurora can be seen further south from the North-pole. The Kp-Index scale varies between a minimum of 0 and a maximum of 9."
                                   }

                                   Rectangle {
                                       Layout.alignment: Qt.AlignCenter
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: Units.dp(200)
                                       KpValueChart {
                                           width:parent.width
                                           height: parent.height
                                      }
                                   }
                               }

                            }


                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                width: 50
                                height: 50
                                color : "yellow"
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                width: 50
                                height: 50
                                color : "yellow"
                            }
                        }
                    }

            }

            Tab {
                id: currentWeather
                title: "Weather"
                anchors.fill: parent
                Controls.ScrollView
                    {
                        anchors.fill: parent

                        ColumnLayout {     // <--- unique child
                            spacing: 30

                            width: calculator.width      // ensure correct width
                            height: children.height     // ensure correct height

                            Card {
                                Layout.alignment: Qt.AlignHCenter
                                Layout.preferredWidth: Units.dp(400)
                                Layout.preferredHeight: Units.dp(600)
                                ColumnLayout{
                                   spacing: Units.dp(10)
                                   anchors.centerIn: parent
                                   width: parent.width * 0.8
                                   height: parent.height * 0.8
                                   Label {
                                       Layout.alignment: Qt.AlignLeft
                                       Layout.preferredWidth: 40
                                       text: "Live Weather data"
                                       style: "subheading"
                                   }

                                   Rectangle {
                                       Layout.alignment: Qt.AlignCenter
                                       Layout.preferredWidth: parent.width
                                       Layout.preferredHeight: parent.height
                                       CurrentWeatherBigCard {
                                          anchors.centerIn: parent
                                          Layout.alignment: Qt.AlignHCenter
                                          width: parent.width
                                      }
                                   }
                               }

                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                width: 50
                                height: 50
                                color : "yellow"
                            }

                            Rectangle
                            {
                                Layout.alignment: Qt.AlignHCenter
                                width: 50
                                height: 50
                                color : "yellow"
                            }
                        }
                    }

            }



        }


    }
}

