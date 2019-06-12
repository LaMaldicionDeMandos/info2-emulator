import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    signal voltChanged(int value)

    Dial {
        id: potentiometer_dial
        x: 8
        y: 29
        width: 148
        height: 83
        stepSize: 1
        to: 33
        value: 0
        onValueChanged: voltChanged(potentiometer_dial.value)
    }

    Text {
        id: potentiometer_title
        x: 8
        y: 4
        text: qsTr("Potenciometro")
        font.pixelSize: 16
    }

    Text {
        id: potentiometer_value
        x: 120
        y: 4
        width: 36
        height: 19
        text: qsTr((potentiometer_dial.value/10) + "V")
        font.pixelSize: 16
    }
}
