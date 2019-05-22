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
            x: 596
            y: 436
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
            x: 554
            y: 436
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
            x: 512
            y: 436
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
            x: 470
            y: 436
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
            x: 428
            y: 436
            width: 36
            height: 36
            text: qsTr("B4")
            onPressedChanged: app.changeButtonState(4, pressed)
            background: Rectangle {
                radius: 15
            }
        }

        Switch {
            id: input0
            x: 0
            y: 432
            text: "IN_0"
            onCheckedChanged: app.changeIn(0, checked)
            indicator: Rectangle {
                implicitWidth: 48
                    implicitHeight: 26
                    x: input0.leftPadding
                    y: parent.height / 2 - height / 2
                    color: input0.checked ? "#cdffbe" : "#aaaaaa"
                    radius: 13
                    border.color: "#777777"

                    Rectangle {
                        x: input0.checked ? parent.width - width : 0
                        width: 26
                        height: 26
                        radius: 13
                        color: input0.down ? "#cccccc" : "#ffffff"
                        border.color: input0.checked ? (input0.down ? "#17a81a" : "#21be2b") : "#999999"
                    }
                }
            contentItem: Text {
                color: "#d5d5f8"
                text: input0.text
                font.bold: true
                renderType: Text.NativeRendering
                horizontalAlignment: Text.AlignLeft
                //font: input0.font
                opacity: enabled ? 1.0 : 0.3
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: input0.indicator.width + input0.spacing
                }
        }

        Switch {
            id: input1
            x: 0
            y: 394
            text: "IN_1"
            onCheckedChanged: app.changeIn(1, checked)
            indicator: Rectangle {
                implicitWidth: 48
                    implicitHeight: 26
                    x: input1.leftPadding
                    y: parent.height / 2 - height / 2
                    color: input1.checked ? "#cdffbe" : "#aaaaaa"
                    radius: 13
                    border.color: "#777777"

                    Rectangle {
                        x: input1.checked ? parent.width - width : 0
                        width: 26
                        height: 26
                        radius: 13
                        color: input1.down ? "#cccccc" : "#ffffff"
                        border.color: input1.checked ? (input1.down ? "#17a81a" : "#21be2b") : "#999999"
                    }
                }
            contentItem: Text {
                color: "#d5d5f8"
                text: input1.text
                font.bold: true
                renderType: Text.NativeRendering
                horizontalAlignment: Text.AlignLeft
                //font: input1.font
                opacity: enabled ? 1.0 : 0.3
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: input1.indicator.width + input1.spacing
                }
        }

        Switch {
            id: input2
            x: 0
            y: 356
            text: "IN_2"
            onCheckedChanged: app.changeIn(2, checked)
            indicator: Rectangle {
                implicitWidth: 48
                    implicitHeight: 26
                    x: input2.leftPadding
                    y: parent.height / 2 - height / 2
                    color: input2.checked ? "#cdffbe" : "#aaaaaa"
                    radius: 13
                    border.color: "#777777"

                    Rectangle {
                        x: input2.checked ? parent.width - width : 0
                        width: 26
                        height: 26
                        radius: 13
                        color: input2.down ? "#cccccc" : "#ffffff"
                        border.color: input2.checked ? (input2.down ? "#17a81a" : "#21be2b") : "#999999"
                    }
                }
            contentItem: Text {
                color: "#d5d5f8"
                text: input2.text
                font.bold: true
                renderType: Text.NativeRendering
                horizontalAlignment: Text.AlignLeft
                //font: input2.font
                opacity: enabled ? 1.0 : 0.3
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: input2.indicator.width + input2.spacing
            }
        }

        Dial {
            id: relay0
            x: 14
            y: 30
            width: 40
            height: 40
            stepSize: 0.1
            wheelEnabled: true
            font.family: "Tahoma"
            enabled: false
            inputMode: Dial.Circular
            value: app.relayState
        }

    }

}
