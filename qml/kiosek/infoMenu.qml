import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0


LeftMenu {
    ColumnLayout{
        anchors.fill: parent;
        MenuButton{
            objectName: "diett_button"
            text: "Good diet"
        }

        MenuButton{
            objectName: "about_button"
            text: "About"
        }
        Item{
            Layout.fillHeight: true;
        }
    }
}
