import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 800
    height: 400
    title: qsTr("Hello World")

    Rectangle {
        width: 400
        height: 200

        Rectangle {
            width: parent.width / 2
            height: parent.height
            color: "blue"
            Text{
                anchors.centerIn: parent
                text: "Hello, World!--1"
            }
        }

        Rectangle {
            id:test
            width: parent.width / 2
            height: parent.height
            x: parent.width / 2
            color: "green"
            Text{
                anchors.centerIn: parent
                text: "Hello, World!--2"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Click!")
                }
            }
        }

        Rectangle {
            x: parent.width / 2
            color: "red"
            width: 100
            height: calculateHeight()
            function calculateHeight() {
                return test.width / 2;
            }
        }


    }
}
