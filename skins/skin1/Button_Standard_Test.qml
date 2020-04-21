import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

Item
{
	Button_Standard
	{
		id: idButton1
		objectName: "objButton1"
		anchors.left : parent.left
		anchors.right : parent.right
		height: parent.height
		text: "Exit"
		enabled: true
		varHorizontalAlignment: Text.AlignHLeft
		
		onPressed:
		{
			console.log("idButton1:onPressed:");
		}
		
		onReleased:
		{
			console.log("idButton1:onReleased:");
		}
		
		onClicked:{
			console.log("idButton1:clicked.");
		}
		
		onDoubleClicked:
		{
			console.log("idButton1:onDoubleClicked:");
		}

		onPressAndHold:
		{
			console.log("idButton1:onPressAndHold:");
		}

		ToolTip.visible: hovered//pressed//hovered//down
		//ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
		ToolTip.text: qsTr("test the active project")
	}
}