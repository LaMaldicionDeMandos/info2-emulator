import QtQuick 2.0

 Rectangle {
    property string dsp_0
    property string dsp_1
    width: 245
    height: 75
    color: "#444444"
    FontLoader { id: fixedFont; name: "Subway Ticker" }
    Rectangle {
        id: rectangle
        x: 10
        y: 10
        width: 225
        height: 55
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#5cbefe"
            }

            GradientStop {
                position: 1
                color: "#034e81"
            }
        }
        Text {
            x: 5
            y: 5
            width: 220
            height: 25
            color: "#c5d7ed"
            text: parent.parent.dsp_0
            font.pointSize: 16
            font.family: fixedFont.name
        }

        Text {
            x: 5
            y: 31
            width: 220
            height: 25
            color: "#c5d7ed"
            text: parent.parent.dsp_1
            font.family: fixedFont.name
            font.pointSize: 14
        }
    }
 }











/*##^## Designer {
    D{i:6;anchors_width:284;anchors_x:6;anchors_y:6}D{i:7;anchors_width:284;anchors_x:6;anchors_y:6}
}
 ##^##*/
