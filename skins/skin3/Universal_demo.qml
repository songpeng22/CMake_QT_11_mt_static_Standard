import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Universal 2.0

Rectangle
{
	id: idItemKeyBoard
	width: 600
	height: 400
	color: "white"
	
	Universal.theme: Universal.Light
    Universal.accent: Universal.Orange
	Universal.foreground: Universal.Red
	Universal.background: Universal.Brown
	
	Column
	{
		anchors.centerIn: parent
		
		Button
		{
			text:"Click here"
//			Universal.background: Universal.Steel
			highlighted: true
			Universal.accent: Universal.Steel//Orange
		}
		
		CheckBox
		{
			text:"Check this"
			checked: true
		}
		
        RadioButton { text: qsTr("Small") }
        RadioButton { text: qsTr("Medium");  checked: true }
        RadioButton { text: qsTr("Large") }
		
		ComboBox {
			width: 200
			model: [ "Banana", "Apple", "Coconut" ]
		}
	}
	
}