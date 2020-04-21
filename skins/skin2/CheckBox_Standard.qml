import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

CheckBox {
	Config
	{
		id: config
	}
	
	Material.background: config.background
	Material.accent: config.accent

	implicitWidth: config.varLineHeight - 2
	implicitHeight: config.varLineHeight - 2
	indicator.width: config.varLineHeight - 2
	indicator.height: config.varLineHeight - 2
/*	
	font.family: "Helvetica"
	font.pointSize: config.varFontSize
*/	
}