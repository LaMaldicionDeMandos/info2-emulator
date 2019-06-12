import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    height: 224
    signal countChanged(int value)
    Slider {
        id: adc_slider
        x: 0
        y: 29
        width: 180
        height: 22
        stepSize: 1
        to: 4095
        value: 0
        orientation: Qt.Horizontal
        onValueChanged: countChanged(adc_slider.value)
    }

    Text {
        id: adc_title
        x: 8
        y: 4
        text: qsTr("ADC Externa")
        font.pixelSize: 16
    }

    Text {
        id: adc_value
        x: 144
        y: 4
        width: 36
        height: 19
        text: qsTr(adc_slider.value.toString())
        font.pixelSize: 16
    }
}
