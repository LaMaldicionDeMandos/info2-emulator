import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Info 2 Emulator")

    Text {
        id: label
        x: 185
        y: 70
        text: app.buttonName
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 32
    }

    Rectangle {
        id: rectangle
        x: 33
        y: 152
        width: 36
        height: 39
        color: "#dc2c2c"
        radius: 11
        border.color: "#900101"
        border.width: 2
    }

    Text {
        id: element1
        x: 28
        y: 197
        text: qsTr("Led 0")
        font.pixelSize: 18
    }
}
