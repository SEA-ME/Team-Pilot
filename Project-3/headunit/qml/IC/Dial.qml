// Copyright (C) 2021 The Qt Company Ltd.
// Copyright (C) 2019 Luxoft Sweden AB
// Copyright (C) 2018 Pelagicore AG
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: root

    width: 480
    height: 480

    property real value: 0
    property int upDuration: 2000
    property int downDuration: 1000
    property string fillImage: "images/dial_fill_color_left.png"
    property string circleRadius: "0.293"
    property string dialCursor: "images/dial_cursor.png"



    Image {
        id: meter
        property real min: -83.5
        property real max: 157
        width: root.width
        height: width - 1
        rotation: min + (max - min) * root.value
        source: Qt.resolvedUrl(root.dialCursor)

    }
//    Image {
//        id: img
//        source: Qt.resolvedUrl(root.fillImage)
//        visible: false
//    }

//    Canvas {
//        id: mask
//        anchors.fill: img

//        property double angle: 45
//        onPaint: {
//            var ctx = getContext("2d");
//            var centerX = width / 2;
//            var centerY = height / 2;

//            ctx.beginPath();
//            ctx.fillStyle = "black";
//            ctx.moveTo(centerX, centerY);
//            ctx.arc(centerX, centerY, width / 4, (Math.PI) * (1 + angle / 180), 0, false);
//            ctx.lineTo(centerX, centerY);
//            ctx.fill();
//        }
//    }

//    OpacityMask {
//        anchors.fill: img
//        source: img
//        maskSource: mask
//    }

}
