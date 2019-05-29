import QtQuick 2.0
import QtQuick.Controls 2.1
Rectangle {
    readonly property string on_0: "#ffff44"
    readonly property string off_0: "#777777"
    readonly property string on_1: "#777700"
    readonly property string off_1: "#222222"
    property bool state
    property string label

    width: 18
    height: 18
    color: "#fbfbfb"
    radius: 1
    gradient: Gradient {
        GradientStop {
            position: 0
            color: state ? on_0 : off_0
        }

        GradientStop {
            position: 1
            color: state ? on_1 : off_1
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
