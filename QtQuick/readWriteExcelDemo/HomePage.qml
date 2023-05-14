import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Rectangle {
    anchors.fill: parent
    color: "gray"

    ColumnLayout {
        anchors.fill: parent
        Text {
            id: name
            width:parent.width
            text: qsTr("text")
        }
        Button {
            text: "Ok"
            width:parent.width
            onClicked: model.submit()
        }
        Button {
            text: "Cancel"
            width:parent.width
            onClicked: model.revert()
        }
    }

}
