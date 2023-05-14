import QtQuick 2.0

Item {
    Image {
        id: qrcode
        sourceSize.width: parent.width
        sourceSize.height: parent.height
        source: ""

    }
    Text {
        id: tips
        x: parent.x
        y: parent.y
        text: qsTr("请扫码")
        font.pixelSize: 24
        visible: false
    }
    Connections {
        target:bussiness
        onAccountQRCodeGenerated: {
            console.log("onAccountQRCodeGenerated invoke !");
            qrcode.source = "image://qrcode/account"
        }
        onAccountScannedSuccess: {
            console.log("onAccountScannedSuccess invoke!");
            qrcode.visible = false
            tips.visible = true
        }
        onAccountLoginSuccess: {
            console.log("onAccountLoginSuccess invoke !");
            tips.text = qsTr("登录成功, 欢迎!")
        }
    }

}
