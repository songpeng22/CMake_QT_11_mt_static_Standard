import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Universal 2.0

Rectangle
{
	id: idItemKeyBoard
	width: 600
	height: 400
	color: "white"
	
	Pane_Standard {
		width: 150
		height: 150
		anchors.centerIn: parent

		Label {
			color: "white"
			text: qsTr("pane in skin2")
			anchors.centerIn: parent
		}
	}
}