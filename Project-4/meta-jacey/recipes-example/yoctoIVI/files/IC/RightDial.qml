// Copyright (C) 2021 The Qt Company Ltd.
// Copyright (C) 2019 Luxoft Sweden AB
// Copyright (C) 2018 Pelagicore AG
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0

Item {
    id: root

    width: 0.8 * 720
    height: 720


    property int value : 0
    property alias fuelLevel: fuelMeter.value


    Image {
        id: overlay

        width: 0.91 * root.width
        height: 0.99 * width

        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        source: Qt.resolvedUrl("images/right_dial.png")

        Image {
            id: circle

            width: root.width/2
            height: width
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: -6
            anchors.verticalCenterOffset: 0
            source: Qt.resolvedUrl("images/middle-bkg.png")

            Image {
                id: circle_overlay

                width: parent.width
                height: parent.height
                anchors.centerIn: parent
                source: Qt.resolvedUrl("images/middle-circle.png")
            }
        }
    }

    Fuel {
        id: fuelMeter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0.05 * root.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -20
        value: datacontroller.battery/100
    }

    Text {
        id: rpmText

        anchors.verticalCenter: overlay.verticalCenter
        anchors.horizontalCenter: overlay.horizontalCenter
        anchors.verticalCenterOffset: -7
        anchors.horizontalCenterOffset: 5
        font.family: "Source Sans Pro"
        font.pixelSize: 60
        font.letterSpacing: 4
        color: "white"
        text: root.value
    }

    Rectangle {
        width: 60
        height: 1
        opacity: 0.4
        anchors.top: rpmText.bottom
        anchors.topMargin: -8
        anchors.horizontalCenter: overlay.horizontalCenter
        anchors.horizontalCenterOffset: 2
    }

    Text {
        id: mph
        anchors.top: rpmText.bottom
        anchors.topMargin: -5
        anchors.horizontalCenter: overlay.horizontalCenter
        anchors.horizontalCenterOffset: 2
        font.family: "Source Sans Pro"
        font.pixelSize: 24
        color: "white"
        text: "RPM x 100"
    }
    Dial {
        id: dial

        width: 0.69 * root.height
        height: width
        anchors.centerIn: overlay
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: -5
        fillImage: "images/dial_fill_color.png"
        circleRadius: "0.29"
        dialCursor: "images/dial_cursor_right.png"
        value: root.value/80
    }
}
