import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

LeftMenu {

    ColumnLayout
    {
        anchors.fill: parent;
        MenuButton{
            text: "Studentsky dum";
            underline:true;
            id: stud_dum;
            objectName: "stud_dum";
        }
        MenuButton{
            text: "Strahov";
            objectName: "strahov"
        }
        MenuButton{
            text: "Masarykova kolej";
            objectName: "masarik"
        }
        MenuButton{
            text: "Technická menze";
            objectName: "technicka"
        }
        MenuButton{
            text: "Karlovo namesti";
            objectName: "karlovka"
        }
        MenuButton{
            text: "Menza Podili";
            objectName: "podoli"

        }
        Item{
            Layout.fillHeight: true;
        }
    }
}
