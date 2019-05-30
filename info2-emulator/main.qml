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

    title: qsTr("Info 2 Emulator")

    readonly property string led_on: "#ff0000"
    readonly property string led_off: "#442222"
    readonly property int relay_max_value: 60

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

        Led {
            id: led
            x: 292
            y: 175
            label: qsTr("Led 0")
            Binding {target: led; property: "state"; value: app.ledState}
        }

        InputButton {
            id: button0
            x: 596
            y: 436
            text: qsTr("B0")
            onPressedChanged: app.changeButtonState(0, pressed)
        }

        InputButton {
            id: button1
            x: 554
            y: 436
            text: qsTr("B1")
            onPressedChanged: app.changeButtonState(1, pressed)
        }

        InputButton {
            id: button2
            x: 512
            y: 436
            text: qsTr("B2")
            onPressedChanged: app.changeButtonState(2, pressed)
        }

        InputButton {
            id: button3
            x: 470
            y: 436
            text: qsTr("B3")
            onPressedChanged: app.changeButtonState(3, pressed)
        }

        InputButton {
            id: button4
            x: 428
            y: 436
            text: qsTr("B4")
            onPressedChanged: app.changeButtonState(4, pressed)
        }

        DigitalInput {
            id: input0
            x: 0
            y: 432
            text: "IN_0"
            onCheckedChanged: app.changeIn(0, checked)
        }

        DigitalInput {
            id: input1
            x: 0
            y: 394
            text: "IN_1"
            onCheckedChanged: app.changeIn(1, checked)
        }

        DigitalInput {
            id: input2
            x: 0
            y: 356
            text: "IN_2"
            onCheckedChanged: app.changeIn(2, checked)
        }

        Relay {
            id: relay0
            x: 14
            y: 30
            label: qsTr("Relay 0")
            Binding {target: relay0; property: "state"; value: app.relay0}
        }

        Relay {
            id: relay1
            x: 14
            y: 54
            label: qsTr("Relay 1")
            Binding {target: relay1; property: "state"; value: app.relay1}
        }

        Relay {
            id: relay2
            x: 14
            y: 78
            label: qsTr("Relay 2")
            Binding {target: relay2; property: "state"; value: app.relay2}
        }

        Relay {
            id: relay3
            x: 14
            y: 102
            label: qsTr("Relay 3")
            Binding {target: relay3; property: "state"; value: app.relay3}
        }

    }

}
