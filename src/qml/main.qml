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
    title: 'Check Aurora'
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
    TabbedPage {
        actions: [
                    Action {
                        iconName: "image/color_lens"
                        name: "Colors"
                        onTriggered: colorPicker.show()
                    }
                ]
        id: main
        Component.onCompleted: entry.forceActiveFocus()

        Dialog {
            id: colorPicker
            title: "Pick color"

            positiveButtonText: "Done"

            MenuField {
                id: selection
                model: ["Primary color", "Accent color", "Background color"]
                width: Units.dp(160)
            }

            Grid {
                columns: 7
                spacing: Units.dp(8)

                Repeater {
                    model: [
                        "red", "pink", "purple", "deepPurple", "indigo",
                        "blue", "lightBlue", "cyan", "teal", "green",
                        "lightGreen", "lime", "yellow", "amber", "orange",
                        "deepOrange", "grey", "blueGrey", "brown", "black",
                        "white"
                    ]

                    Rectangle {
                        width: Units.dp(30)
                        height: Units.dp(30)
                        radius: Units.dp(2)
                        color: Palette.colors[modelData]["500"]
                        border.width: modelData === "white" ? Units.dp(2) : 0
                        border.color: Theme.alpha("#000", 0.26)

                        Ink {
                            anchors.fill: parent

                            onPressed: {
                                switch(selection.selectedIndex) {
                                    case 0:
                                        theme.primaryColor = parent.color
                                        break;
                                    case 1:
                                        theme.accentColor = parent.color
                                        break;
                                    case 2:
                                        theme.backgroundColor = parent.color
                                        break;
                                }
                            }
                        }
                    }
                }
            }

            onRejected: {
                // TODO set default colors again but we currently don't know what that is
            }
        }

        Tab {
            title: "Search by City"
            //iconName: "action/home"

            anchors.leftMargin: 5;
            anchors.rightMargin: 5;
            anchors.fill: parent

            ColumnLayout {     // <--- unique child
                spacing: 30

                anchors.fill: parent


                SearchByCity {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: Units.dp(500)
                    anchors.fill: parent
                }

            }


        }

        Tab {
            id: currentRating
            title: "Your location"
            anchors.fill: parent

            Overview {

            }

        }

        Tab {
            id: currentWeather
            title: "Weather"
            anchors.fill: parent
            Controls.ScrollView{
                anchors.fill: parent
                anchors.topMargin: Units.dp(10);

                Rectangle {
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
                    }
                }
            }
        }
    }
}
