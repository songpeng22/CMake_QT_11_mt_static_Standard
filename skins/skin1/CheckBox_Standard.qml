import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

CheckBox {
	Config
	{
		id: config
	}

	property var varText: ""
	
	width: 20
	height: config.varLineHeight - 2
	indicator.width: 20
	indicator.height: config.varLineHeight - 2
	text: varText
	font.family: "Helvetica"
	font.pointSize: config.varFontSize
}