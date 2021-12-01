import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 400
    height: 200
    visible: true
    Component.onCompleted: console.log('initiate')
    title: qsTr("Update Tool")
    Rectangle {
        anchors.fill: parent
        color: 'grey'
        Text {
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: 'Updating  Scalmis...\nPlease Wait.'
            font.pixelSize: 35
            font.family: 'consolas'
            font.weight: Font.Bold
        }
    }
}
