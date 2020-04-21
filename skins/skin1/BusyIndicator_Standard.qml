import QtQuick 2.9
import QtQuick.Controls 2.3

Item
{
	id: idIndicator
	anchors.fill: parent
	z: running ? 0 : -1
	
	property var running : true;
	property var opacityEx : 0.1;
	
	BusyIndicator_Style
	{
		id:idBusyIndicator
		z: running ? 1 : -1
		anchors.centerIn: parent
		running: idIndicator.running
	}
	
	MouseArea {
		id: idMouseArea
		anchors.fill: parent
		z: running ? 0 : -1
		acceptedButtons: Qt.LeftButton | Qt.RightButton
		
		Rectangle
		{
			anchors.fill: parent
			color:"black"
			opacity: opacityEx
		}
		
		onClicked: {
			console.log("idMouseArea z:.",z);
			console.log("idBusyIndicator z:.",idBusyIndicator.z);
		}
	}
}
