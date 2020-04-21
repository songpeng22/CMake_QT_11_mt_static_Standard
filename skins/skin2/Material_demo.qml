import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

Rectangle
{
	id: idItemKeyBoard
	width: 600
	height: 400
	color: "black"
	
	Material.theme: Material.Dark
	Material.primary: Material.BlueGrey
    Material.accent: Material.Purple
	Material.foreground: Material.Pink
	Material.background: Material.Teal
	
	Column
	{
		anchors.centerIn: parent
		
		Button
		{
			text:"Click here"
			Material.background: Material.Teal
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