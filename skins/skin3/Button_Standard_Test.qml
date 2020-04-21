import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Universal 2.0

Item
{
	width: 800
	height: 600
	
	Button_Standard
	{
		id: idButton1
		objectName: "objButton1"
		anchors.centerIn : parent
//		implicitWidth: 100
//		implicitHeight: 40
		width: 250
		height: 50
		text: "Button_Standard"
	}
	
	Button
	{
		id: idButton2
		y: 0//idButton1.y + idButton1.height + 20
		text:"normal button"
		
		Universal.background: Universal.Teal
	}
	
	Button
	{
		id: idButton3
		y: idButton2.y + idButton2.height + 20
		text:"normal button"
		contentItem: Text {
			text: parent.text
			font: parent.font
			//opacity: enabled ? 1.0 : 0.3
			color: parent.down ? "black" : "red"
			horizontalAlignment: varHorizontalAlignment
			verticalAlignment: varVerticalAlignment
			elide: Text.ElideRight
		}

		background: Rectangle {
			implicitWidth: 100
			implicitHeight: 40
			color: parent.enabled ? ( parent.down ? Universal.color(Universal.Lime) : Universal.background ) : Universal.color(Universal.Grey)
	//		border.color: parent.down ? "red" : "black"
			border.width: 1
			radius: 2
		}
	}
	
	Component.onCompleted:
	{
		console.log("Universal.background:",Universal.background);
		console.log("Universal.Teal:",Universal.Teal);
	}
}