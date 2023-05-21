import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item{

    Rectangle {
        anchors.fill: parent
        color: "gray"

        ColumnLayout {
            anchors.fill: parent
            Text {
                id: name
                width:parent.width
                text: qsTr("这是一个Excel读写操作实例")
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
}
