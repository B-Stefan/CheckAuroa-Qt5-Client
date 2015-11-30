import QtQuick 2.5
import Material 0.1
import Material.ListItems 0.1 as ListItem
import QtQuick.Window 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls 1.4 as Controls
import CheckAurora 1.0
import QtPositioning 5.3
import QtQuick.Layouts 1.1
Page {
    id: overviewPage
    anchors.fill: parent
    property var cityName: "Test"
    property var lat: 1.2
    property var lng: 1.2

    title:overviewPage.cityName
    Overview {
        lat: overviewPage.lat
        lng: overviewPage.lng
        anchors.fill: parent
    }
}

