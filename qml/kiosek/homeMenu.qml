import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0


LeftMenu {

    ColumnLayout
    {
        anchors.fill: parent;
        MenuButton{
            text: qsTr("Today's Menu");
            objectName: "meal_button";
        }
        MenuButton{
            text:qsTr("Canteen map");
            objectName: "map_button";
        }
        MenuButton{
            text: qsTr("My diet")
            objectName:  "diet_button"
            visible: root.logged;
        }
        MenuButton{
            text: qsTr("Diet history");
            objectName: "history_button";
            visible: root.logged;
        }
        MenuButton{
            text: qsTr("Info");
            objectName: "info_button";
        }
        MenuButton{
            text: qsTr("Login")
            objectName: "login_button";
            visible: !root.logged
        }
        Item{
            Layout.fillHeight: true;
        }
    }
}
