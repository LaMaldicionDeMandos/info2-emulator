import QtQuick 2.0

 Rectangle {
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
        color: "#42aff4"
        Text {
            x: 5
            y: 5
            width: 220
            height: 25
            text: "Titulo"
            font.pointSize: 16
            font.family: fixedFont.name
        }

        Text {
            x: 5
            y: 31
            width: 220
            height: 25
            text: "Subtitulo"
            font.family: fixedFont.name
            font.pointSize: 14
        }
    }
 }







/*##^## Designer {
    D{i:3;anchors_width:284;anchors_x:6;anchors_y:6}D{i:4;anchors_width:284;anchors_x:6;anchors_y:6}
}
 ##^##*/
