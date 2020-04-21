import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

Button
{
	property var varHorizontalAlignment: Text.AlignHCenter
	property var varVerticalAlignment: Text.AlignVCenter
	property var varBorderWidth: 1
	
	Config
	{
		id: config
	}
	
	contentItem: Text {
		text: parent.text
		font: parent.font
		//opacity: enabled ? 1.0 : 0.3
		//color: parent.down ? "black" : "teal"
		color: parent.enabled ? ( parent.down ? config.btnColorTextDown : config.btnColorTextNormal ) : config.btnColorTextDisable
		horizontalAlignment: varHorizontalAlignment
		verticalAlignment: varVerticalAlignment
		elide: Text.ElideRight
	}

	background: Rectangle {
		implicitWidth: 100
		implicitHeight: 40
//		color: parent.enabled ? ( parent.down ? "white" : "orange" ) : "gray"
		color: parent.enabled ? ( parent.down ? config.btnColorDown : config.btnColorNormal ) : config.btnColorDisable
//		border.color: parent.down ? "red" : "black"
		border.color: parent.down ? config.btnColorBorderDown : config.btnColorBorderNormal
		border.width: varBorderWidth
		radius: 2
	}
	
	onPressed:
	{
//		console.log("Button_Standard:onPressed:");
	}
	
	onReleased:
	{
//		console.log("Button_Standard:onReleased:");
	}
	
	onClicked:{
//		console.log("Button_Standard:clicked.");
	}
	
	onDoubleClicked:
	{
//		console.log("Button_Standard:onDoubleClicked:");
	}

	onPressAndHold:
	{
//		console.log("Button_Standard:onPressAndHold:");
	}	
}