import QtQuick 2.0
import QtQuick.Controls 2.1
Dial {
    width: 40
    height: 40
    to: relay_max_value
    from: 0
    spacing: -7
    stepSize: 1
    wheelEnabled: true
    font.family: "Tahoma"
    enabled: false
    inputMode: Dial.Circular
}
