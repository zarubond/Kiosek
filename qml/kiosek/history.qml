import QtQuick 2.0
import QtQuick.Layouts 1.0

Content {
    title: "Diet history";

    function getDate(pluss)
    {
        var today = new Date();
        today.setHours(today.getHours()-24*pluss-24);
        return Qt.formatDate(today, "dd.MM dddd");
    }

    ColumnLayout{
        anchors.fill: parent;

        Rectangle
        {
            height: 30;
            Layout.fillWidth: true;
            RowLayout
            {
                width: parent.width;
                Text{
                    text: getDate(0)
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Text{
                    text:"Kuřecí Kung - pao , rýže dušená ";
                }
            }
        }

        Rectangle
        {
            Layout.fillWidth: true;
            height: 30;
            RowLayout
            {
                width: parent.width;
                Text{
                    text: getDate(1)
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Text{
                    text:"Pečená kachna, bramborový knedlík, červené zelí ";
                }
            }
        }
        Rectangle
        {
            Layout.fillWidth: true;
            height: 30;
            RowLayout
            {
                width: parent.width;
                Text{
                    text: getDate(2)
                }

                Rectangle{
                    color: "black";
                    height: 2
                    Layout.fillWidth: true;
                }
                Text{
                    text:"Maďarský hovězí guláš, těstoviny vařené ";
                }
            }
        }

        Item{
            Layout.fillHeight: true;
            Layout.fillWidth: true;
        }
    }


}
