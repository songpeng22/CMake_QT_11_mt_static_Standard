import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

TabButton
{
	property var bSelected: false
	height: parent.height
	
	Config
	{
		id: config
	}

	contentItem: Text {
		text: parent.text
		font: parent.font
		//opacity: enabled ? 1.0 : 0.3
		color: bSelected ? "black" : "white"
//		color: parent.enabled ? config.btnColorTextDown : config.btnColorTextNormal
		horizontalAlignment: Text.AlignHCenter
		verticalAlignment: Text.AlignVCenter
	}

	background: Rectangle {
		implicitWidth: 100
		implicitHeight: 40
		color: bSelected? config.bkColor:"black"
//		color: parent.enabled ? ( parent.down ? config.btnColorDown : config.btnColorNormal ) : config.btnColorDisable
//		border.color: parent.down ? "red" : "black"
//		border.color: parent.down ? config.btnColorBorderDown : config.btnColorBorderNormal
	}

	onPressed:
	{
		console.log("TabButton_Standard:onPressed:");
	}
	
	onReleased:
	{
		console.log("TabButton_Standard:onReleased:");
	}
	
	onClicked:{
		console.log("TabButton_Standard:clicked.");		
	}
	
	onDoubleClicked:
	{
		console.log("TabButton_Standard:onDoubleClicked:");
	}

	onPressAndHold:
	{
		console.log("TabButton_Standard:onPressAndHold:");
	}
}