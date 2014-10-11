import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

Content{
    title: qsTr("Meal today")

    Component {
        id: contactDelegate
        Rectangle {

            id: meal
            width: parent.width;
            height:childrenRect.height;
            color: "black";
            Column {
                width:parent.width
                height: childrenRect.height
                RowLayout{
                    width: parent.width;
                    height: 50
                    Text {id: caption;
                        text: name;
                        Layout.fillWidth: true;
                        font.bold: false;
                        font.pixelSize: 22;
                        color:"white";
                    }

                    Item{
                        Layout.fillWidth: true;
                    }

                    Button{text:"Select"; visible: root.logged;}
                    Button{text:"Info"; onClicked: {
                            info.visible=!info.visible;
                            if(info.visible==true)
                            info.height=100
                            else
                                info.height=0;
                        }}
                }
                ColumnLayout
                {
                    id: info
                    visible: false;
                    width: parent.width
                    height: 0;
                    RowLayout{
                        Text { text: " Energy";color:"white"}
                        Rectangle{
                            color: "white";
                            height: 1
                            Layout.fillWidth: true;
                        }
                        Text{
                            text:energy+' Kj ';
                            color:"white";
                        }
                    }
                    RowLayout{
                        Text { text: " Fat";color:"white"}
                        Rectangle{
                            color: "white";
                            height: 1
                            Layout.fillWidth: true;
                        }
                        Text{
                            text:fat+' g ';
                            color:"white"
                        }
                    }
                    RowLayout{
                        Text { text: " Protain";color:"white"}
                        Rectangle{
                            color: "white";
                            height: 1
                            Layout.fillWidth: true;
                        }
                        Text{
                            text:protain+' g ';
                            color:"white"
                        }
                    }
                }
            }/*
                MouseArea {
                    anchors.fill: parent
                    onClicked: parent.ListView.view.currentIndex = index
                }}*/

        }
    }

    ListView {
        anchors.fill: parent
        model: stud_dum
        delegate: contactDelegate
       // highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
        objectName: "list_view"
    }

    ListModel {
        id: stud_dum;
        objectName: "dum_model"
        ListElement {
            name: " Hovezi pecene prirodni"
            energy: "836"
            fat: "15"
            protain: "16"
        }
        ListElement {
            name: " Cocka na kyselo"
            energy: "396"
            fat: "2"
            protain: "7"
        }
        ListElement {
            name: " Salat talir s tunakem"
            energy: "510"
            fat: "-"
            protain: "1"
        }
        ListElement {
            name: " Tlacenkovy talir"
            energy: "666"
            fat: "13"
            protain: "7"
        }
    }

    ListModel {
        id: strahov;
        objectName: "strahov_model"
        ListElement {
            name: " Hovězí pečeně znojemská, knedlíky houskové,"
            energy: "915"
            fat: "16"
            protain: "16"
        }
        ListElement {
            name: " Dálmácké čufty, těstoviny věřené"
            energy: "690"
            fat: "9"
            protain: "7"
        }
        ListElement {
            name: " Makedonský salát"
            energy: "450"
            fat: "-"
            protain: "-"
        }
        ListElement {
            name: " Věpřová krkovice marinovaná"
            energy: "1039"
            fat: "25"
            protain: "17"
        }
    }

    ListModel {
        id: masaryk;
        objectName: "masarik_model"
        ListElement {
            name: "Boršč"
            energy: "678"
            fat: "3"
            protain: "5"
        }
        ListElement {
            name: " Špagety s vepřovým masem a rajčaty"
            energy: "336"
            fat: "8"
            protain: "9"
        }
        ListElement {
            name: " Jemná rýžová kaše s jahodami"
            energy: "257"
            fat: "1"
            protain: "-"
        }
    }
}
