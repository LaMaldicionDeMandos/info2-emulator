import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Info 2 Emulator")

    Text {
        id: label
        x: 275
        y: 57
        text: app.buttonName
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 32
    }
}
