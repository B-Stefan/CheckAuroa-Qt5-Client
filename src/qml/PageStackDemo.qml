import QtQuick 2.4
import Material 0.1
import Material.Extras 0.1

Item {

    Column {

        Button {
            text: "Push subpage"
            elevation: 1
            onClicked: pageStack.push(Qt.resolvedUrl("SubPage.qml"))
        }

        /*
        Image {
            id: image

            anchors.horizontalCenter: parent.horizontalCenter

            source: Qt.resolvedUrl("images/balloon.jpg")
            width: Units.dp(400)
            height: Units.dp(250)

            Ink {
                anchors.fill: parent

                onClicked: overlayView.open(image)
            }
        }*/

        Label {

            style: "subheading"
            color: Theme.light.subTextColor
            text: "Tap to edit picture"
            font.italic: true
            objectName: "label"

        }
    }


}
