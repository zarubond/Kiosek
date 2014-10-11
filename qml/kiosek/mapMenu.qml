import QtQuick 2.0
import QtQuick.Layouts 1.0

LeftMenu {
    ColumnLayout
    {
        anchors.fill: parent;

        MenuButton{
            text: "Studentsky dum";
        }
        MenuButton{
            text: "Strahov";
        }
        MenuButton{
            text: "Masarykova kolej";
        }
        MenuButton{
            text: "Technicka menze";
        }
        MenuButton{
            text: "Karlovo namesti";
        }
        MenuButton{
            text: "Menza podili";
        }
        Item{
            Layout.fillHeight: true;
        }
    }
}
