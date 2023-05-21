import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    title: qsTr("Hello World")
    width: 840
    height: 680
    visible: true
    font.family: "Helvetica"
    font.pointSize: 15

    MainPage{
        id:mainPage
        anchors.fill: parent
    }
}