import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: item1
    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        Button {
            id: btnP
            text: qsTr("P")
            style: ButtonStyle{
                label: Text{
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                    text: control.text
                }
            }
            onClicked: prndSignal(text)
        }
        Button {
            id: btnR
            text: qsTr("R")
            style: ButtonStyle{
                label: Text{
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                    text: control.text
                }
            }
            onClicked: prndSignal(text)
        }
        Button {
            id: btnN
            text: qsTr("N")
            style: ButtonStyle{
                label: Text{
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                    text: control.text
                }
            }
            onClicked: prndSignal(text)
        }
        Button {
            id: btnD
            text: qsTr("D")
            style: ButtonStyle{
                label: Text{
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                    text: control.text
                }
            }
            onClicked: prndSignal(text)
        }
    }
}
