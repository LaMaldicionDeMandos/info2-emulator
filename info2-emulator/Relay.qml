import QtQuick 2.0
import QtQuick.Controls 2.1
Rectangle {
    readonly property string on: "#f7ec44"
    readonly property string off: "#442222"
    property bool state
    property string label

    width: 18
    height: 18
    color: "#fbfbfb"
    radius: 1
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#fbfbfb"
        }

        GradientStop {
            position: 1
            color: state ? on : off
        }
    }
    border.color: "#212121"
    border.width: 1

    Text {
        id: relay_text
        x: 23
        y: -2
        text: parent.label
        font.pixelSize: 18
    }
}
