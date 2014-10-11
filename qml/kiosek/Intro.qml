import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

Rectangle {
    anchors.fill: parent;
    color: "#FFAA00"

    ColumnLayout
    {
        anchors.fill: parent;
        spacing: 6;


        Text{
           font.bold: true;
           font.pointSize: 28;
           horizontalAlignment: Text.AlignHCenter;
           Layout.fillWidth: true;
           color: "black";
           text: qsTr("Are you hungry?");
        }/*
        Rectangle
        {
            color:"black";
            width: 100;
            height: 150;
            Layout.alignment: Qt.AlignHCenter;

        }*/
        Image {
            id: name
            Layout.alignment: Qt.AlignHCenter;
            fillMode: Image.PreserveAspectFit
            Layout.minimumHeight: 300;
            Layout.minimumWidth: 300;
            source: "./img/head.png"
        }

        RowLayout
        {/*
            Rectangle
            {
                color:"green"
                anchors.fill: parent;
                //Layout.fillWidth: true;
            }
            width: 400
            Layout.alignment: Qt.AlignHCenter;
*/
            Item{
                Layout.fillWidth: true;
            }
            MenuButton {
                Layout.fillWidth: true;
                text: qsTr("Enter");
                objectName: "enter";
                size:40;
            }
            Item{
                Layout.fillWidth: true;
            }

            MenuButton {
                text: qsTr("Log in");
                Layout.fillWidth: true;
                objectName: "login";
                size: 40;
            }
            Item{
                Layout.fillWidth: true;
            }
/*
            MenuButton{
                text:qsTr("Kill sound");
                Layout.fillWidth: true;
                objectName: "soundSwitch";
            }*/
        }
    }
}
