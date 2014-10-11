import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: container
    property string text: "Button"
    property bool underline: false
    property alias size: buttonLabel.font.pixelSize;
    signal clicked;
    Layout.fillWidth: true;
    height: buttonLabel.height+12
    color: "#D68F00"
    border.color: "#B67900"
    border.width: 2


    MouseArea  {
        id: mouseArea
        anchors.fill: parent
        onClicked: container.clicked();
    }

    Text  {
        id: buttonLabel
        anchors.centerIn: container
        text: container.text
        font.underline: container.underline;
        font.pixelSize: 28
        color: "white"
    }

}
