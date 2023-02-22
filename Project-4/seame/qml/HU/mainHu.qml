import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3
import QtMultimedia 5.15
import QtQuick.Layouts 1.2

Window {
    width: 1920
    height: 720
    visible: true
    title: qsTr("HU")

//    ColumnLayout {
//            anchors.fill: parent
//            spacing: 0
            Rectangle {
                id: topBar
                width: 1
                height: parent.height *0.1
                color: "#151515"
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    bottomMargin: 0
                }
                RowLayout {
                    anchors.fill : parent
                    spacing: 0

                    Rectangle {
                        id : topBar1
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.08
                        color: "#151515"
                        Image {
                            id: backImage
                            source: "images/back.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: parent.width *0.1
                            width: parent.height*0.5
                            height : parent.height*0.5
                        }
                        MouseArea {
                            id: mouseRegion
                            anchors.fill: topBar1
                            onClicked: Qt.quit();
                        }


                    }
                    Rectangle {
                        id : topBar2
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.08
                        color: "#151515"

                        Image {
                            id: homeImage
                            source: "images/home.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            width: parent.height*0.5
                            height : parent.height*0.5
                        }


                    }
                    Rectangle {
                        id : topBar3
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.08
                        color: "#151515"

                        Image {
                            id: menuImage
                            source: "images/menu.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            width: parent.height*0.5
                            height : parent.height*0.5
                        }


                    }
                    Rectangle {
                        id : topBar4
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.3
                        color: "#151515"

                        Label {
                            id: timeText
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: 0.05 * parent.width
                            font.pixelSize: 0.5 * parent.height
                            font.bold: true
                            color : "white"

                            text: Qt.formatTime(currentDate, "hh:mm")

                            property var currentDate: new Date();

                            Timer {
                                interval: 1000
                                repeat: true
                                running: true
                                onTriggered: {
                                    timeText.currentDate = new Date();
                                }
                            }
                        }

                    }
                    Rectangle {
                        id : topBar5
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.36
                        color: "#151515"

                        Label {
                            id: dateText
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            font.pixelSize: 0.3 * parent.height
                            font.bold: true
                            color : "white"

                            text: new Date().toLocaleDateString(Qt.locale("en"), 'ddd. MMM dd')

                        }

                    }
                    Rectangle {
                        id : test6
                        Layout.alignment: Qt.AlignLeft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.22
                        color: "#151515"

                        Image {

                            id: batteryImage
                            source: "images/battery.PNG"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left : parent.left
                            anchors.leftMargin: parent.width * 0.3
                            width: parent.height*0.7
                            height : parent.height*0.7

                        }

                        Label {
                            id: batteryText
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left : parent.left
                            anchors.leftMargin: parent.width * 0.12
                            font.pixelSize: 0.4 * parent.height
                            font.bold: true
                            color : "white"

                            text: "55 %"
                        }

                    }




//                    }
////                    MouseArea {
////                        id: mouseRegion
////                        anchors.fill: backImage
////                        onClicked: Qt.quit();
////                    }

//                    Image {
//                        id: homeImage
//                        source: "images/home.PNG"
//                        Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
////                        Layout.leftMargin: parent.width * 0.015
////                        Layout.rightMargin: parent.width * 0.015
//                        Layout.preferredWidth: parent.height*0.5
//                        Layout.preferredHeight : parent.height*0.5
//                        Rectangle {
//                            anchors.fill : parent

//                        }

//                    }

//                    Image {

//                        id: menuImage
//                        source: "images/menu.PNG"
//                        Layout.alignment: Qt.AlignVCenter
////                        anchors.left : homeImage.left
////                        anchors.leftMargin: parent.width * 0.085
//                        Layout.preferredWidth: parent.height*0.5
//                        Layout.preferredHeight : parent.height*0.5

//                    }








                }

            }
            Rectangle {
                id: middleBar
                width: 1
                height: parent.height *0.9
                color: "black"
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
                        function rBtnClicked(idx) {
                            prndSignal(idx);
                            stack.push(page2);
                        }
                        function restBtnClicked(idx) {
                            prndSignal(idx);
                            stack.pop();
                            Qt.quit();
                        }

                        id: leftScreen
                        Layout.alignment: Qt.AlignVCenter | Qt.Alignleft
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.16
                        color: "black"

                        MyButton {
                            id: p
                            text: "P"
    //                        onClicked: restBtnClicked(0)
                            onClicked: stack.push(page1)

                        }
                        MyButton {
                            id: r
                            anchors.top : p.bottom
                            text: "R"
    //                        onClicked: rBtnClicked(1)
                            onClicked: stack.push(page2)

                        }
                        MyButton {
                            id: n
                            anchors.top : r.bottom
                            text: "N"
                            onClicked: stack.push(page1)
                        }
                        MyButton {
                            id: d
                            anchors.top : n.bottom
                            text: "D"
                            onClicked: stack.push(page1)
                        }


                    }
                    Rectangle {
                        id: rightScreen
                        Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                        Layout.preferredHeight : parent.height
                        Layout.preferredWidth: parent.width *0.8
                        color: "gray"

                            StackView {
                                id: stack
                                initialItem: page1
                                anchors.fill: parent
                            }
                            Rectangle {
                                id: page1
                                //anchors.fill: parent
                                Image {

                                    id: mapImage
                                    source: "images/map.jpg"
                                    anchors.fill: parent
                                }
                            }
                            Rectangle {
                                id: page2

                                //anchors.fill: parent
                                Camera {
                                    id: camera
                                }
                                VideoOutput {
                                    id: videoOutput
                                    anchors.left: parent.left
                                    anchors.bottom: parent.bottom
                                    anchors.top: parent.top
                                    source: camera
                                    focus: visible
                                }
                            }


                    }
                }
            }

}

