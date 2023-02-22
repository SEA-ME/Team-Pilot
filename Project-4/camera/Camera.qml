import QtQuick 2.7
import QtMultimedia 5.4

Rectangle {
    id: cameraUI

    width: 100
    height: 100

    color: "black"
    state: "visible"

    states: [
        State {
            name: "visible"
            PropertyChanges { target: cameraUI; opacity: 1.0 }
            StateChangeScript {
                script: {
                    camera.start()
                }
            }
        },
        State {
            name: "invisible"
            PropertyChanges { target: cameraUI; opacity: 0 }
            StateChangeScript {
                script: {
                    camera.stop()
                }
            }
        }
    ]

    Camera {
            id: camera
            captureMode: Camera.CaptureStillImage

            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview
                    stillControls.previewAvailable = true
                    cameraUI.state = "PhotoPreview"
                }
            }

            videoRecorder {
                 resolution: "100x100"
                 frameRate: 30
            }
    }

    function toggle() {
        if (state == "visible")
            state = "invisible";
        else
            state = "visible";
    }
}
