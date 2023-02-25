import QtQuick 2.0

Item {
    id:root
    width:0.37*parent.width
    height:0.5*parent.height

    Row {
        id: prndRow
        x: parent.width/2.7
        y: parent.height/6
        spacing: 30

        Text {
            id: parkText
            text: "P"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: "blue"
        }
        Text {
            id: reverseText
            text: "R"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: "red"
        }
        Text {
            id: neutralText
            text: "N"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: "orange"
        }
        Text {
            id: driveText
            text: "D"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: "green"
        }
    }
}

