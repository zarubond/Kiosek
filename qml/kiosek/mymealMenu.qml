import QtQuick 2.0
import QtQuick.Layouts 1.0

LeftMenu {
    ColumnLayout
    {
        anchors.fill: parent;
        Text{
            text: "Five day summary"
            wrapMode:Text.WordWrap
        }
        RowLayout{
            width: parent.width
            Text{
                text: "Energy"
            }
            Rectangle{
                color: "black";
                height: 2
                Layout.fillWidth: true;
            }
            Text{
                text: "2690 Kj "
            }
        }
        RowLayout{
            width: parent.width
            Text{
                text: "Fat"
            }
            Rectangle{
                color: "black";
                height: 2
                Layout.fillWidth: true;
            }
            Text{
                text: "50g "
            }
        }

        RowLayout{
            width: parent.width
            Text{
                text: "Protain"
            }
            Rectangle{
                color: "black";
                height: 2
                Layout.fillWidth: true;
            }
            Text{
                text: "73g "
            }
        }

        Item{
            Layout.fillHeight: true;
        }
    }

}
