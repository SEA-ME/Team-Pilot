import QtQuick 2.7
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtWayland.Compositor 1.0
import QtQuick.Window 2.3
import QtQuick.Layouts 1.2

WaylandOutput {

    id: prnd

//    property alias surfaceArea: headbackground
//    property alias text: t.text
    property alias screen: winHead.screen
    property int colorIndex: 4
    sizeFollowsWindow: true

    property bool windowed: false


    window: Window {
        id: winHead
        x: Screen.virtualX
        y: Screen.virtualY
        visibility: Window.FullScreen
        visible: true


        Background {

        }


        Rectangle {
            id : root
            width: parent.width
            height: parent.height*0.7

            color:"black"


//            StackView {
//                id: stack
//                initialItem: mapPage
//                anchors.fill: parent

//                pushEnter: Transition {
//                    PropertyAnimation {
//                        property: "opacity"
//                        from: 0
//                        to: 1
//                        duration: 200
//                    }
//                }
//                pushExit: Transition {
//                        PropertyAnimation {
//                            property: "opacity"
//                            from: 1
//                            to:0
//                            duration: 200
//                        }
//                    }
//                popEnter: Transition {
//                    PropertyAnimation {
//                        property: "opacity"
//                        from: 0
//                        to:1
//                        duration: 200
//                    }
//                }
//                popExit: Transition {
//                    PropertyAnimation {
//                        property: "opacity"
//                        from: 1
//                        to:0
//                        duration: 200
//                    }
//                }
                TopBar {
                    id: topBar
                }
                MiddleBar {
                    id: middleBar
                }




        }

    }
}
