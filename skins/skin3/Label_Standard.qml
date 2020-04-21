import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Universal 2.0

Label {
	Config
	{
		id: config
	}
	
//	Universal.background: config.background
		
	height: config.varLineHeight
	font.family: "Helvetica"
	font.pointSize: config.varFontSize
	color: "black"
	background: Rectangle {
		implicitWidth: 100
		implicitHeight: 40
		color: "white"
	}
}