import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

Content {
    title: qsTr("My meal")

    function getDate(pluss)
    {
        var today = new Date();
        today.setHours(today.getHours()+24*pluss);
        return Qt.formatDate(today, "dd.MM dddd");
    }

    ColumnLayout{
        anchors.fill: parent;
        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: 30
            RowLayout
            {
                width: parent.width;
                Text{
                    text: getDate(0);
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Button{
                    text: "Add"
                }
            }
        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: 30
            RowLayout
            {
                width: parent.width;

                Text{
                    text:getDate(1)+"  Vepřové pepřenky";
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Button{
                    text: "Change"
                    objectName: "change_thur"
                }
                Button{
                    text: "Remove"
                }
                Button{
                    text: "Info"
                }
            }
        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: 30
            RowLayout
            {
                width: parent.width;

                Text{
                    text: getDate(2)+"  Buchtičky se šodo";
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Button{
                    text: "Change"
                    objectName: "change_thur"
                }
                Button{
                    text: "Remove"
                }
                Button{
                    text: "Info"
                }
            }
        }
        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: 30
            RowLayout
            {
                width: parent.width;

                Text{
                    text: getDate(3)+"  Steak z lososa Mascarpone, bramborová kaše ";
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Button{
                    text: "Change"
                    objectName: "change_thur"
                }
                Button{
                    text: "Remove"
                }
                Button{
                    text: "Info"
                }
            }
        }
        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: 30
            RowLayout
            {
                width: parent.width;

                Text{
                    text: getDate(4)+"  Kuře pečené na česneku, bramborový knedlík, špenát dušený";
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Button{
                    text: "Change"
                    objectName: "change_fri"
                }
                Button{
                    text: "Remove"
                }
                Button{
                    text: "Info"
                }
            }
        }



        Item{
            Layout.fillHeight: true;
        }
        Rectangle{
            id: popup
            visible: false;
            anchors.centerIn: parent;
            width: parent.width/3+100;
            height: 150;
            color: "orange"
            ColumnLayout
            {
                anchors.fill: parent;
                spacing: 2;
                Text{
                    Layout.fillWidth: true;
                    wrapMode: Text.WordWrap;
                    text: "You should have to include more protains!"
                }
                Item{
                    Layout.fillHeight: true;
                }

                MenuButton{
                    anchors.leftMargin: 10;
                    text: "Close";
                    onClicked: {
                        popup.visible=false;
                    }
                }
            }
        }

        RowLayout{
            width: parent.width
            MenuButton{
                text: "Show recomendations"
                onClicked: {
                    popup.visible=!popup.visible;
                }
            }
            Item{
                Layout.fillWidth: true;
            }

            MenuButton{
                text: "Send to email"
            }
        }
    }
}
