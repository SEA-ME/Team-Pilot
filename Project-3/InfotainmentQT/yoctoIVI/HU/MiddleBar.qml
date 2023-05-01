import QtQuick 2.7
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3
import QtMultimedia 5.15
import QtQuick.Layouts 1.2
import QtPositioning 5.3
import QtLocation 5.6
import QtQml 2.0

Rectangle {
    id: middleBar
    width: 1
    height: parent.height *0.9
    color: "#151515"
    anchors {
        top: topBar.bottom
        left: parent.left
        right: parent.right
        bottomMargin: 0
    }

    RowLayout {
        anchors.fill : parent
        spacing: 0

        Rectangle {
            id : backBar
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.04
            color : "black"
            Image {
                id: barImage
                source: "images/backBar.PNG"
                anchors.verticalCenter: parent.verticalCenter
                width : parent.width*2
                height :parent.height * 0.3
            }


        }
        Rectangle {

            id: leftScreen
            Layout.alignment: Qt.AlignVCenter | Qt.Alignleft
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.16
            color: "black"

            MyButton {
                id: p
                text: "P"
                onClicked:
                {
                    stack.pop()
                    prndSignal(0)
                }
            }
            MyButton {
                id: r
                anchors.top : p.bottom
                text: "R"
                onClicked: prndSignal(1)

            }
            MyButton {
                id: n
                anchors.top : r.bottom
                text: "N"
                onClicked: prndSignal(2)
            }
            MyButton {
                id: d
                anchors.top : n.bottom
                text: "D"
                onClicked: prndSignal(3)
            }


        }
        Rectangle{
            id: blackBar
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.003
            color: "#151515"

        }
        Rectangle {
            id: rightScreen
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.preferredHeight : parent.height
            Layout.preferredWidth: parent.width *0.7997
            color: "black"

                StackView {
                    id: stack
                    initialItem: homePage
                    anchors.fill: parent

                    pushEnter: Transition {
                        PropertyAnimation {
                            property: "opacity"
                            from: 0
                            to: 1
                            duration: 200
                        }
                    }
                    pushExit: Transition {
                            PropertyAnimation {
                                property: "opacity"
                                from: 1
                                to:0
                                duration: 200
                            }
                        }
                    popEnter: Transition {
                        PropertyAnimation {
                            property: "opacity"
                            from: 0
                            to:1
                            duration: 200
                        }
                    }
                    popExit: Transition {
                        PropertyAnimation {
                            property: "opacity"
                            from: 1
                            to:0
                            duration: 200
                        }
                    }
                }

                Rectangle {
                    id: mapPage
                    //anchors.fill: parent
                    Image {

                        id: mapImage
                        source: "images/map.jpg"
                        anchors.fill: parent
                    }
                }

                RowLayout{
                    id: homePage
                    spacing:0

                    Rectangle{
                        id: mapIcon
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *1/4
                        color: "black"

                        Image {

                            id: mapIconImage
                            source: "images/homeMap.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width : parent.width *0.4
                            height: parent.width *0.4
                        }
                        Text{
                            anchors.top: mapIconImage.bottom
                            anchors.horizontalCenter: parent.horizontalCenter
                            color:"white"
                            font.pixelSize: 60
                            text:"MAP"
                        }
                        MouseArea {
                            id: mouseRegion
                            anchors.fill: mapIconImage
                            onClicked: stack.push(mapPage)
                        }
                    }
                    Rectangle{
                        id: musicIcon
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *1/4
                        color: "black"

                        Image {

                            id: musicIconImage
                            source: "images/homeMUsic.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width : parent.width *0.4
                            height: parent.width *0.4
                        }
                        Text{
                            anchors.top: musicIconImage.bottom
                            anchors.horizontalCenter: parent.horizontalCenter
                            color:"white"
                            font.pixelSize: 60
                            text:"MUSIC"
                        }
                    }
                    Rectangle{
                        id: lightIcon
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *1/4
                        color: "black"

                        Image {

                            id: lightIconImage
                            source: "images/homeLight.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width : parent.width *0.4
                            height: parent.width *0.4
                        }
                        Text{
                            anchors.top: lightIconImage.bottom
                            anchors.horizontalCenter: parent.horizontalCenter
                            color:"white"
                            font.pixelSize: 60
                            text:"LIGHT"
                        }
                    }
                    Rectangle{
                        id: settingIcon
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *1/4
                        color: "black"

                        Image {

                            id: settingIconImage
                            source: "images/homeSetting.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width : parent.width *0.4
                            height: parent.width *0.4
                        }
                        Text{
                            anchors.top: settingIconImage.bottom
                            anchors.horizontalCenter: parent.horizontalCenter
                            color:"white"
                            font.pixelSize: 60
                            text:"SETTING"
                        }
                    }


                }



        }
    }
}
