import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Universal 2.0

Button
{
	Config
	{
		id: config
	}
	implicitWidth: 100
	implicitHeight: config.varLineHeight

	Universal.theme: Universal.Dark//Universal.theme: config.theme
	highlighted: true
	Universal.accent: config.accent
	Universal.background: config.background
	Universal.foreground: config.foreground
	
}