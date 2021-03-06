import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles.Desktop 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3


Window {
    id: window
    visible: true
    width: 640
    height: 680
    color: "#3c3f41"

    title: qsTr("Info 2 Emulator")

    readonly property string led_on: "#ff0000"
    readonly property string led_off: "#442222"
    readonly property int relay_max_value: 60

    Label {
        id: in_tx_title
        color: "#ffffff"
        text: "Transmición Entrante"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter

    }

    Label {
        id: in_tx_bin_label
        width: 315
        text: "Binario"
        color: "#ffffff"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        anchors.top: in_tx_title.bottom
        anchors.topMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
    }

    TextArea {
        id: textArea
        width: 316
        anchors.top: in_tx_bin_label.bottom
        anchors.topMargin: 2
        anchors.bottom: rectangle.top
        anchors.bottomMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
    }

    Label {
        id: in_tx_text_label
        width: 315
        text: "Assci"
        color: "#ffffff"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 2
        anchors.top: in_tx_title.bottom
        anchors.topMargin: 2
    }

    TextArea {
        id: textArea1
        width: 316
        anchors.top: in_tx_text_label.bottom
        anchors.topMargin: 2
        anchors.bottom: rectangle.top
        anchors.bottomMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 200
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

        Thermometer {
            id: thermometer
            x: 8
            y: 128
            width: 0
            height: 224
            onTempChanged: app.thermometer = value
        }

        Potentiometer {
            id: potentiometer
            x: 456
            y: 8
            onVoltChanged: app.potentiometer = value
        }

        AdcExtern {
            id: adc_extern
            x: 147
            y: 8
            onCountChanged: app.adc_extern = value
        }

        Seg7Group {
            id: segGroup0
            x: 500
            y: 256
            value: app.dsp0
        }

        Seg7Group {
            id: segGroup1
            x: 367
            y: 256
            value: app.dsp1
        }

        Display {
            id: display
            x: 387
            y: 128
            dsp_0: app.lcd0
            dsp_1: app.lcd1
        }
    }
}













































/*##^## Designer {
    D{i:4;anchors_width:315}
}
 ##^##*/
