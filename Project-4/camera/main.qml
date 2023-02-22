import QtQuick 2.7
import QtQuick.Window 2.2
import QtMultimedia 5.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Rectangle {
        id: cameraUI
        width: parent.width / 2
        height: parent.height / 2
        color: "black"
        state: "visible"

        states: [
            State {
                name: "visible"
                StateChangeScript {
                    script: {
                        camera.start()
                    }
                }
            },
            State {
                name: "invisible"
                StateChangeScript {
                    script: {
                        camera.stop()
                    }
                }
            }
        ]

        Camera {
            id: camera
        }

        VideoOutput {
            id: viewfinder
            visible: cameraUI.state == "visible"
            x: 0
            y: 0
            width: parent.width
            height: parent.height
            autoOrientation: true
        }
    }
}
