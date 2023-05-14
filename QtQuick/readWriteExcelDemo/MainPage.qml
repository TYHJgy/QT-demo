import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    TabBar {
        id: bar
        x:0
        y:0
        width: parent.width
        TabButton {
            text: qsTr("首页")
        }
        TabButton {
            text: qsTr("读Excel")
        }
        TabButton {
            text: qsTr("写Excel")
        }
    }

    StackLayout {
        x:0
        y:bar.height
        height : parent.height-bar.height
        width: parent.width
        currentIndex: bar.currentIndex
        HomePage {
            id: homeTab
        }
        ReadExcel {
            id: readExcelTab
        }
        WriteExcel {
            id: writeExcelTab
        }
    }
}
