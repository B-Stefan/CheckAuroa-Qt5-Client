import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3
import QtQuick.Layouts 1.1
Controls.ScrollView {
    id: overviewView

    property var lat: 60
    property var lng: 25

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
                      lat: overviewView.lat
                      lng:overviewView.lng
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
    }
}


