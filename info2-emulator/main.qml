import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.6

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Info 2 Emulator")

    readonly property string led_on: "#ff0000"
    readonly property string led_off: "#442222"

    Rectangle {
        id: rectangle
        x: 33
        y: 152
        width: 35
        height: 40
        radius: 10
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#fbfbfb"
            }

            GradientStop {
                position: 1
                color: app.ledState ? led_on : led_off
            }
        }
        border.color: "#cb2121"
        border.width: 1
    }

    Text {
        id: element1
        x: 28
        y: 197
        text: qsTr("Led 0")
        font.pixelSize: 18
    }

    Button {
        id: button
        x: 283
        y: 395
        width: 57
        height: 36
        text: qsTr("Led")
        onClicked: app.changeLedState()
    }
}
