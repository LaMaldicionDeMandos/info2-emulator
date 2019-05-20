import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles.Desktop 1.0
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 640
    height: 480
    //color: "#67b26a"

    title: qsTr("Info 2 Emulator")

    readonly property string led_on: "#ff0000"
    readonly property string led_off: "#442222"

    Rectangle {
        width: 640
        height: 480
        color: "#65b763"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#65B763"
            }

            GradientStop {
                position: 1
                color: "#1F9117"
            }
        }
        Rectangle {
            id: rectangle
            x: 294
            y: 184
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
            border.color: "#212121"
            border.width: 1
        }

        Text {
            id: element1
            x: 289
            y: 229
            text: qsTr("Led 0")
            font.pixelSize: 18
        }

        Button {
            id: button0
            x: 587
            y: 423
            width: 36
            height: 36
            text: qsTr("B0")
            onPressedChanged: app.changeButtonState(0, pressed)
            background: Rectangle {
                radius: 15
            }
        }

        Button {
            id: button1
            x: 545
            y: 423
            width: 36
            height: 36
            text: qsTr("B1")
            onPressedChanged: app.changeButtonState(1, pressed)
            background: Rectangle {
                radius: 15
            }
        }

        Button {
            id: button2
            x: 503
            y: 423
            width: 36
            height: 36
            text: qsTr("B2")
            onPressedChanged: app.changeButtonState(2, pressed)
            background: Rectangle {
                radius: 15
            }
        }

        Button {
            id: button3
            x: 461
            y: 423
            width: 36
            height: 36
            text: qsTr("B3")
            onPressedChanged: app.changeButtonState(3, pressed)
            background: Rectangle {
                radius: 15
            }
        }

        Button {
            id: button4
            x: 419
            y: 423
            width: 36
            height: 36
            text: qsTr("B4")
            onPressedChanged: app.changeButtonState(4, pressed)
            background: Rectangle {
                radius: 15
            }
        }

    }

}
