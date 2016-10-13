import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import Atomify 1.0
import QtQml.StateMachine 1.0 as DSM

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Atomify {
        id: atomify
        onStart: timer.start()
        onCrashed: timer.stop()
    }

    Timer {
        id: timer
        running: false
        interval: 2000
        onTriggered: {
            atomify.finished()
        }
    }

    Row {
        spacing: 20
        Column {
            width: 100
            Button {
                text: "Start"
                enabled: atomify.states.idle.active
                onClicked: atomify.start()
            }
            Button {
                text: "Reset"
                enabled: atomify.states.parsing.active || atomify.states.crashed.active || atomify.states.finished.active || atomify.states.continued.active
                onClicked: atomify.reset()
            }
            Button {
                text: "Continue"
                enabled: atomify.states.finished.active
                onClicked: atomify.continued()
            }
            Button {
                text: "Force crash"
                enabled: atomify.states.parsing.active
                onClicked: atomify.crashed()
            }
        }

        Column {
            width: 50
            anchors {
                top: parent.top
                bottom: parent.bottom
            }

            ListView {
                model: atomify.states.list
                // anchors.fill: parent
                width: 100
                height: 300
                delegate: Row {
                    Label {
                        text: model.modelData.objectName
                        color: model.modelData.active ? "green" : "red"
                    }
                }
            }
        }
    }
}
