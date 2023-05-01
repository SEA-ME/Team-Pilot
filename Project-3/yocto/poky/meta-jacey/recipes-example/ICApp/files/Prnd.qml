import QtQuick 2.0

Item {
    id:root
    width:0.37*1920
    height:0.5*720

    Row {
        id: prndRow
        x: 239
        y: 289
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

