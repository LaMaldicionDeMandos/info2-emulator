import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    signal voltChanged(int value)
    Slider {
        id: potentiometer_slider
        x: 0
        y: 29
        width: 180
        height: 22
        stepSize: 1
        to: 33
        value: 0
        orientation: Qt.Horizontal
        onValueChanged: voltChanged(potentiometer_slider.value)
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
        x: 144
        y: 4
        width: 36
        height: 19
        text: qsTr((potentiometer_slider.value/10) + "V")
        font.pixelSize: 16
    }
}
