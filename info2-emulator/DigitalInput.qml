import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles.Desktop 1.0
import QtQuick.Controls.Styles 1.4

Switch {

    property Switch self: this

    indicator: Rectangle {
        implicitWidth: 48
            implicitHeight: 26

            x: self.leftPadding
            y: parent.height / 2 - height / 2
            color: self.checked ? "#cdffbe" : "#aaaaaa"
            radius: 13
            border.color: "#777777"

            Rectangle {
                x: self.checked ? parent.width - width : 0
                width: 26
                height: 26
                radius: 13
                color: self.down ? "#cccccc" : "#ffffff"
                border.color: self.checked ? (self.down ? "#17a81a" : "#21be2b") : "#999999"
            }
        }
    contentItem: Text {
        color: "#d5d5f8"
        text: self.text
        font.bold: true
        renderType: Text.NativeRendering
        horizontalAlignment: Text.AlignLeft
        //font: input0.font
        opacity: enabled ? 1.0 : 0.3
        verticalAlignment: Text.AlignVCenter

        leftPadding: self.indicator.width + self.spacing
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
