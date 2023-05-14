import QtQuick 2.7
import QtQuick.Window 2.2

import WorkClass 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignal1
    signal qmlSignal2(string strValue, int iValue)

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }

    Rectangle{
        id:rect1
        anchors.fill: parent
        color: "green"

    }

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if(mouse.button === Qt.LeftButton){
                console.log(' Qt.LeftButton')
                bussiness.strValue = "HelloCpp"
                bussiness.intValue = 2022
                bussiness.sendSignal()
            }else{
                console.log(' Qt.RightButton')
                root.qmlSignal1()
                root.qmlSignal2('hesy', 2000)
            }
        }
    }

    //加载子页面qrcode.qml
    //Loader {
    //    id:accountQRCode
    //    source:"qrcode.qml"
    //    x:(root.width - root.height / 3) / 2
    //    y:root.height / 3
    //    visible: true
    //}

    CBusiness{
        id: bussiness
        property int addpro: 0

        onIntValueChanged: {
            console.log('qml onIntValueChanged', "begin change addpro ", addpro)
            addpro++
            console.log('qml onIntValueChanged', addpro)
        }

        onAddproChanged: {
            console.log('qml onAddFun', addpro)
        }
    }

    Component.onCompleted: {
        bussiness.onSignal1.connect(function(){console.log('no name qml function')})
        bussiness.onSignal2.connect(qmlProcess1)
        root.qmlSignal1.connect(bussiness.slot1)
        root.qmlSignal2.connect(bussiness.slot2)
        console.log('Component.onCompleted')
    }

    function qmlProcess1(str, value){
        console.log('qmlProcess1', str, value)
    }
}
