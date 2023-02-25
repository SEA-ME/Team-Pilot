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
            color: (instrumentclusterLeft.msgIndex == 0) ? "blue" : "#616366"
        }
        Text {
            id: reverseText
            text: "R"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: (instrumentclusterLeft.msgIndex == 1) ? "red" : "#616366"
        }
        Text {
            id: neutralText
            text: "N"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: (instrumentclusterLeft.msgIndex == 2) ? "orange" : "#616366"
        }
        Text {
            id: driveText
            text: "D"
            font.weight: Font.Bold
            font.bold: false
            font.pointSize: 40
            color: (instrumentclusterLeft.msgIndex == 3) ? "green" : "#616366"
        }
    }


}

