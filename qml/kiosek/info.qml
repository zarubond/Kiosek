import QtQuick 2.0

Content {
    title: qsTr("Info");

    Item //diet
    {
        objectName: "diet_page"
        anchors.fill: parent;
        visible: true

        Text{
            wrapMode: Text.WordWrap
            anchors.fill:parent;
            text: "    A healthy diet is one that helps maintain or improve general health. A healthy diet provides the body with essential nutrition: fluid, adequate essential amino acids from protein, essential fatty acids, vitamins, minerals, and adequate calories. The requirements for a healthy diet can be met from a variety of plant-based and animal-based foods. A healthy diet supports energy needs and provides for human nutrition without exposure to toxicity or excessive weight gain from consuming excessive amounts. Where lack of calories is not an issue, a properly balanced diet (in addition to exercise) is also thought to be important for lowering health risks, such as obesity, heart disease, type 2 diabetes, hypertension and cancer.
    Various nutrition guides are published by medical and governmental institutions to educate the public on what they should be eating to promote health. Nutrition facts labels are also mandatory in some countries to allow consumers to choose between foods based on the components relevant to health."
        }
    }

    Item //aboud
    {
        objectName: "about_page";
        anchors.fill: parent;
        visible: false
        Text{
            wrapMode: Text.WordWrap
            anchors.fill:parent;
            text: "Developed by Katerina Fixova, Ondrej Zaruba, Michal Becka."
        }
    }

}
