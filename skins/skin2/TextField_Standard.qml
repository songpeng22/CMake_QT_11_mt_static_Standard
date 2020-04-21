import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

TextField {
	Config
	{
		id: config
	}
	
	Material.foreground: config.foreground
	Material.background: config.background
	Material.accent: config.accent
	
/*	
	background: Rectangle {
		implicitWidth: 200
		implicitHeight: config.varLineHeight
		//color: parent.readOnly ? "transparent" : "#353637"
		color: parent.readOnly ? config.textColorReadOnly : config.textColorNormal
		//border.color: "#e0e0e0"
		border.color: parent.readOnly ? config.textColorBorderReadOnly : config.textColorBorderNormal
		border.width: 1
	}
*/	
}
