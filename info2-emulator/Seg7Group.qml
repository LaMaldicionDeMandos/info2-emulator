import QtQuick 2.0

Rectangle {
    property int value

    width: 132
    height: 60
    Seg7 {
        id: seg2
        x: 0
        y: 0
        value: (parent.value % 1000) / 100
    }

    Seg7 {
        id: seg1
        x: 44
        y: 0
        value: (parent.value % 100) / 10
    }

    Seg7 {
        id: seg0
        x: 88
        y: 0
        value: parent.value % 10
    }
}
