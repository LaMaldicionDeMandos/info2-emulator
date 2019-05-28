import QtQuick 2.0

Rectangle {
    readonly property string led_on: "#ff0000"
    readonly property string led_off: "#442222"
    property bool state
    property string label

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
            color: state ? led_on : led_off
        }
    }
    border.color: "#212121"
    border.width: 1

    Text {
        id: led_text
        x: -5
        y: 42
        text: parent.label
        font.pixelSize: 18
    }
}
