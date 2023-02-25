import QtQuick 2.7

Item {
    id: button

    signal clicked

    property string text
    property color color: "white"
    property bool isClicked

    width : parent.width *0.8
    height: parent.height *0.2
    anchors {
        top: parent.top
        topMargin:parent.height*0.02
    }

    BorderImage {
        id: buttonImage
        source: "images/toolbutton.sci"
        width: button.width; height: button.height
    }
    MouseArea {
        id: mouseRegion
        anchors.fill: buttonImage
        onClicked: { button.clicked(); }
    }
    Text {
        id: btnText
        anchors.fill: buttonImage
        anchors.margins: 5
        text: button.text
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        color: button.color
        font.bold: true
        style: Text.Raised
        styleColor: "black"
        font.pixelSize: 70
    }
}
