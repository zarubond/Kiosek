import QtQuick 2.0

Rectangle {
    width: 800
    height: 600
    id: root;
    objectName: "rootx";
    property bool logged: false;

    Loader
    {
        id: pageLoader
        objectName: "pageLoader"
        anchors.fill: parent
        function openView(url)
        {
            setSource(url);
        }
        onLoaded: done();
        signal done();
    }
    Keys.onPressed: {
        if ((event.key == Qt.Key_Escape))
            Qt.quit();
    }
}
