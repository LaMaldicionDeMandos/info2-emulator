import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    signal tempChanged(int value)
    Slider {
        id: thermometer_slider
        width: 22
        height: 224
        stepSize: 10
        to: 5000
        value: 0
        orientation: Qt.Vertical
        onValueChanged: tempChanged(thermometer_slider.value)
    }

    Text {
        id: thermometer_title
        x: 28
        y: 8
        text: qsTr("Termometro")
        font.pixelSize: 16
    }

    Text {
        id: thermometer_value
        x: 28
        y: 197
        text: qsTr((thermometer_slider.value/10 - 273) + "º")
        font.pixelSize: 16
    }
}
