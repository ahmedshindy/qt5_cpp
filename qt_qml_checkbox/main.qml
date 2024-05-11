import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
//    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }




    CheckBox
    {
        id: myCheckBox
        checked: true
        anchors.centerIn: parent
        width: 400
        height: 100

        Text
        {
            id: myCheckBoxText
            text: "Check Me"
            font.pointSize: 15
            font.bold: true
            color: "#38ada9"
            x: ((myCheckBoxindicator.x + myCheckBoxindicator.width) + 10)
            y: ((myCheckBox.height - myCheckBoxText.height)/2)
        }

        onCheckedChanged:
        {
            console.log("CheckBox Status: " + checked)
        }
        background: Rectangle
        {
            border.width: 5
            border.color: "#fa983a"
        }


        indicator: Rectangle
        {
            id: myCheckBoxindicator
            implicitWidth: 50
            implicitHeight: 50
            radius: 10
            border.color: "#1e3799"
            border.width: 3
            x: 10
            y: ((myCheckBox.height - myCheckBoxindicator.height) / 2)

            Rectangle
            {
                visible: myCheckBox.checked
                color: "#eb2f06"
                border.color: "#eb2f06"
                radius: 5
                anchors.margins: 10
                anchors.fill: parent
            }
        }

    }
}
