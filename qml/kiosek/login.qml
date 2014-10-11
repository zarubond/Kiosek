import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Content
{
    title: qsTr("Login")
    anchors.fill: parent;

    Rectangle{

        anchors.centerIn: parent
        width: 406
        height: 120
        color: "black"

        ColumnLayout
        {
            id: columnLayout1
            Layout.maximumWidth: 200;

            RowLayout
            {
                Layout.minimumWidth: 200
                ColumnLayout
                {
                    Layout.minimumWidth: 200
                    Text
                    {
                        text:"Login"
                        font.pixelSize: 30
                        horizontalAlignment: Text.AlignHCenter
                        color: "white"
                        Layout.fillWidth: true;
                    }
                    Text
                    {
                        text:"Password"
                        font.pixelSize: 30
                        horizontalAlignment: Text.AlignHCenter
                        color: "white";
                    }
                }
                ColumnLayout
                {
                    Layout.minimumWidth: 200
                    TextField
                    {
                        text:"Pepa";
                        font.pixelSize: 26
                        Layout.fillHeight: true;
                        Layout.fillWidth: true;
                    }

                    TextField
                    {
                        text:"root";
                        echoMode: TextInput.Password;
                        font.pixelSize: 26
                        Layout.fillHeight: true;
                        Layout.fillWidth: true;

                    }
                }
            }

            MenuButton
            {
                width: 100
                objectName: "login_button";
                text: qsTr("Login");
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
