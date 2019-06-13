import QtQuick.Controls 2.1
import QtQuick 2.0

Rectangle {
    property int value
    width: 44
    height: 60
    color: "#000000"
    FontLoader { id: fixedFont; name: "Digital-7" }
    Text {
        id: digit
        x: 0
        y: 0
        width: 36
        height: 44

        color: "#c93e24"
        text: parent.value
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignLeft
        clip: false
        styleColor: "#000000"
        font.capitalization: Font.Capitalize
        font.bold: false
        lineHeight: 0.2
        font.pointSize: 64
        font.family: fixedFont.name
    }
}
