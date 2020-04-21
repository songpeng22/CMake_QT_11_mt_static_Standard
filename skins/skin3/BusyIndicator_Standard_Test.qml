import QtQuick 2.9
import QtQuick.Controls 2.3

Rectangle
{
	id: idItemKeyBoard
	width: 600
	height: 400
	color: "teal"
	
	BusyIndicator_Standard
	{
		id: idBusyIndicator
		z: running ? 1 : -1
	}
	
	//make z order of Button bigger than MouseArea , than Button can be clicked
	Button
	{
		text:"Click"
//		x: 0
//		y: 100
		z: 1
		width: 100
		height: 40
		anchors.bottom: parent.bottom
		anchors.horizontalCenter:parent.horizontalCenter		
		onClicked: {
			
			console.log("Button clicked z:",z);
			
			idBusyIndicator.running = !idBusyIndicator.running;
			console.log("idBusyIndicator.running:",idBusyIndicator.running);
		}
	}
	
	Button
	{
		text:"button in background"
		x: 0
		y: 0
		width: 100
		height: 40
		onClicked: {	
			console.log("Button should not be clicked while busy");
		}
	}

}