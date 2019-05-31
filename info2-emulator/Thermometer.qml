import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    Slider {
        id: thermometer_slider
        width: 22
        height: 224
        stepSize: 10
        to: 1000
        value: 490
        orientation: Qt.Vertical
        /*
        background: Rectangle {
            x: thermometer_slider.leftPadding + thermometer_slider.availableWidth / 2 - width / 2
            y: thermometer_slider.topPadding
            implicitWidth: 200
            implicitHeight: 4
            width: thermometer_slider.implicitWidth
            height: implicitHeight
            radius: 2
            color: "#bdbebf"

            Rectangle {
                width: thermometer_slider.visualPosition * parent.width
                height: parent.height
                color: "#21be2b"
                radius: 2
            }
        }

        handle: Rectangle {
            x: thermometer_slider.leftPadding + thermometer_slider.visualPosition * (thermometer_slider.availableWidth - width)
            y: thermometer_slider.topPadding + thermometer_slider.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: thermometer_slider.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }*/
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
        text: qsTr("0º")
        font.pixelSize: 16
    }
}
