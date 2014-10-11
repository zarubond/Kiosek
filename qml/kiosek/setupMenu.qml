import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

LeftMenu {
    ColumnLayout
    {
        anchors.fill: parent;
        MenuButton
        {
            text: qsTr("Diet setup");
        }
        MenuButton
        {
            text: qsTr("Where to send");
        }
        MenuButton
        {
            text: qsTr("Password change");
        }
        MenuButton
        {
            text: qsTr("Head setup");
        }
    }
}
