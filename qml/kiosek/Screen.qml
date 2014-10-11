import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

Item {
    anchors.fill: parent;
    width:600
    height: 600

    ColumnLayout
    {
        anchors.fill: parent
        Layout.fillHeight: true;
        Layout.fillWidth: true
        spacing:0;

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.minimumHeight: root.height/12
            color: "#242539"
            z:7;
            Text{
                id: title
                font.pixelSize: root.height/15
                text: "Unknown"
                color: "white";
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        RowLayout {
            spacing:0
            Layout.fillHeight: true;

            ColumnLayout {
                Layout.maximumWidth: 300;
                Layout.minimumWidth: 300;
                spacing: 0

                Rectangle{
                    Layout.fillHeight: true;
                    Layout.fillWidth: true;
                    Loader{
                        objectName: "menuLoader"
                        anchors.fill: parent
                        function openView(url)
                        {
                            setSource(url);
                        }
                        property LeftMenu menu:item;
                    }
                }

                Rectangle
                {
                    Image {
                        id: name
                        Layout.alignment: Qt.AlignHCenter;
                        fillMode: Image.PreserveAspectFit
                        height: parent.height;
                        source: "./img/head.png"
                    }
                    objectName: "head_rect";
                    color:"black";
                    Layout.fillWidth: true;
                    Layout.fillHeight: true;
                    Layout.maximumHeight: parent.height/3;
                    Layout.minimumHeight: parent.height/3;
                }
            }

            ColumnLayout {
                width: parent.width;
                spacing: 0;
                Item{

                    Layout.fillHeight: true;
                    Layout.fillWidth: true;
                    Loader{
                        id: load
                        objectName: "contentLoader"
                        anchors.fill: parent
                        function openView(url)
                        {
                            setSource(url);
                        }
                        property Content content:item;
                        onLoaded: {
                            title.text=content.title;
                        }
                    }
                }

                Rectangle
                {/*
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "green" }
                        GradientStop { position: 0.33; color: "yellow" }
                        GradientStop { position: 1.0; color: "green" }
                    }*/
                    color: "black";

                    Layout.fillWidth: true;
                    Layout.maximumHeight: root.height/12
                    Layout.minimumHeight: root.height/12
                    RowLayout
                    {
                        width: parent.width;
                        height: parent.height;
                        Rectangle
                        {
                            Layout.fillHeight: true;
                            Layout.minimumWidth: parent.height;
                            color: "#D68F00"
                            border.color: "#C1563C"
                            border.width: 2
                            Image{
                                objectName: "back_button"
                                source: "./img/previous.png"
                                anchors.fill: parent;

                                fillMode: Image.PreserveAspectFit
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: { parent.clicked(); }
                                }
                                signal clicked();
                            }
                        }
                        Item
                        {
                            Layout.fillWidth: true;
                        }
                        Rectangle
                        {
                            Layout.fillHeight: true;
                            Layout.minimumWidth: parent.height;
                            color: "#D68F00"
                            border.color: "#C1563C"
                            border.width: 2

                            Image{
                                objectName: "home_button"
                                source: "./img/home.png"
                                anchors.fill: parent;

                                fillMode: Image.PreserveAspectFit
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: { parent.clicked(); }
                                }
                                signal clicked();
                            }
                        }
                        Item
                        {
                            Layout.fillWidth: true;
                        }
                        Rectangle
                        {
                            Layout.fillHeight: true;
                            Layout.minimumWidth: parent.height
                            color: "#D68F00"
                            border.color: "#C1563C"
                            border.width: 2

                            Image{

                                objectName: "sound_button";
                                source: "./img/audio-on.png"
                                anchors.fill: parent;

                                function switchSound(status)
                                {
                                    if(status)
                                        source="./img/audio-on.png";
                                    else
                                        source="./img/audio-off.png";
                                }

                                fillMode: Image.PreserveAspectFit
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: { parent.clicked(); }
                                }
                                signal clicked();
                            }
                        }

                        Rectangle
                        {
                            Layout.fillHeight: true;
                            Layout.minimumWidth: parent.height+70;
                            color: "#D68F00"
                            border.color: "#C1563C"
                            border.width: 2

                            objectName: "lock_button";
                            MouseArea {
                                anchors.fill: parent
                                onClicked: { parent.clicked();}
                            }
                            signal clicked();

                            RowLayout
                            {
                                anchors.fill: parent;
                                Text{
                                    id: login_name
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    text:"Login:"
                                    font.pixelSize: 26
                                    Layout.minimumWidth: 70
                                    verticalAlignment: Text.AlignVCenter
                                }
                                Image{
                                    Layout.fillWidth: true
                                    id:lock_button;
                                    objectName: "lock_button";
                                    source: "./img/unlock.png"
                                    Layout.fillHeight: true

                                    fillMode: Image.PreserveAspectFit



                                    states:[
                                        State {
                                        name: "lock_change"; when: root.logged
                                        PropertyChanges { target: lock_button; source: "./img/unlock.png"}
                                        PropertyChanges { target: login_name; text: "Login:"}
                                        PropertyChanges { target: lock_button; source: "./img/lock.png"}
                                        PropertyChanges { target: login_name; text: "Pepa"}
                                    }
                                    ]

                                }
                                Item{
                                    Layout.fillWidth: true;
                                }

                            }
                        }

                        Text{
                            Layout.fillHeight: true;
                            color: "white"
                            text: Qt.formatDateTime(new Date(), "hh:mm")
                            font.pixelSize: parent.height*0.5
                            verticalAlignment: Text.AlignVCenter;
                        }

                    }
                }
            }
        }
    }
}
