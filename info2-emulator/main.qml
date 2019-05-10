import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 280
    color: "#859d70"
    title: qsTr("Prueba 1")

    Text {
        id: label
        x: 0
        y: 43
        width: 640
        height: 38
        text: qsTr("")
        padding: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 32
    }

    Button {
        id: button
        x: 270
        y: 221
        text: qsTr("Botonazo")
        onClicked: label.text = "JOJO!!"
    }
}
