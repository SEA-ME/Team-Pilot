// Copyright (C) 2021 The Qt Company Ltd.
// Copyright (C) 2019 Luxoft Sweden AB
// Copyright (C) 2018 Pelagicore AG
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0

Item {
    id: root
    width: 0.37 * 1920
    height: 0.12 * 720

    property real temperature: 0
    property real humidity: 0

    Image {
        id: background
        width: parent.width
        height: parent.height
        source: Qt.resolvedUrl("images/top_bar.png")
    }

    Label {
        id: timeText
        anchors.verticalCenter: background.verticalCenter
        anchors.left: background.left
        anchors.leftMargin: 0.4 * background.width

        font.pixelSize: 0.42 * background.height
        font.bold: true

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


    Label {
        id: temperatureText
        anchors.verticalCenter: background.verticalCenter
        anchors.left: background.left
        anchors.leftMargin: 0.23 * background.width
        font.pixelSize: 0.42 * background.height
        font.bold: true

        text: root.temperature + "°C"
    }
    Label {
        id: humidityText
        anchors.verticalCenter: background.verticalCenter
        anchors.left: background.left
        anchors.leftMargin: 0.65 * background.width
        font.pixelSize: 0.42 * background.height
        font.bold: true

        text: root.humidity + "%"
    }
}
