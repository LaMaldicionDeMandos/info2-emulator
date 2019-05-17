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
        x: 294
        y: 37
        width: 35
        height: 40
        color: "#fbfbfb"
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
        x: 289
        y: 82
        text: qsTr("Led 0")
        font.pixelSize: 18
    }

    Button {
        id: button
        x: 17
        y: 395
        width: 605
        height: 36
        text: qsTr("BUTTON 0")
        onPressedChanged: app.changeButtonState(pressed)
     //   onClicked: app.changeLedState()
    }
}
