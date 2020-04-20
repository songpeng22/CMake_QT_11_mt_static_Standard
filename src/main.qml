import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
//import QtQuick.Controls.Universal 2.0
import QtQuick.Dialogs 1.1

Window {
    id:root
	objectName: "objWindow1"
    visible: true
    width: 600
    height: 400
    title: qsTr("Hello World")

	//Rectangle for TabBar
    Rectangle{
        id:idRect1
        objectName : "objRect1"
        color: "teal"
        height:parent.height * 1 / 3
        anchors.left : parent.left
        anchors.right : parent.right

		//TabBar usage
		TabBar {
			id: idTab
			width: parent.width
//			height:parent.height
			TabButton {
				text: qsTr("Home")
			}
			TabButton {
				text: qsTr("Discover")
			}
			TabButton {
				text: qsTr("Activity")
			}
		}

		StackLayout {
			anchors.top:idTab.bottom
			width: parent.width
			implicitHeight: 200
			currentIndex: idTab.currentIndex
			Item {
				id: homeTab
				anchors.fill: parent
				Rectangle{ anchors.fill: parent; color: "magenta" }
				Component.onCompleted: console.log("homeTab height:",height);
			}
			Item {
				id: discoverTab
				anchors.fill: parent
				Rectangle{ anchors.fill: parent; color: "tan" }
				Component.onCompleted: console.log("discoverTab height:",height);
			}
			Item {
				id: activityTab
				anchors.fill: parent
				Rectangle{ anchors.fill: parent; color: "lime" }
				Component.onCompleted: console.log("activityTab height:",height);
			}
		}
        
    }

	
	 Rectangle{
        id:idRect2
        objectName : "objRect2"
        color: "teal"
        height:parent.height * 1 / 3
        anchors.left : parent.left
        anchors.right : parent.right
        anchors.top:idRect1.bottom
		
    }


    Rectangle{
        id:idRect3
        objectName : "objRect2"
        color: "violet"
        height:parent.height * 1 / 3
        anchors.left : parent.left
        anchors.right : parent.right
        anchors.top:idRect2.bottom
		Button {
            id: idButton1
            objectName: "objButton1"
            x: 0
            y: 0
            width: 173
            height: 88
            text: qsTr("txtButton1")
        }
    }
}
