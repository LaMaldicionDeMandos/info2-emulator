import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    Slider {
        id: thermometer_slider
        width: 22
        height: 224
        stepSize: 10
        from: -1000
        to: 2000
        orientation: Qt.Vertical
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
        text: qsTr((thermometer_slider.value/10) + "º")
        font.pixelSize: 16
    }
}
