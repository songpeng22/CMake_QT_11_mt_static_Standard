import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

TabBar
{
	Config
	{
		id: config
	}
	implicitWidth: 600
	implicitHeight: 40//config.varLineHeight

//	Material.theme: config.theme
//	Material.background: config.background
//	Material.foreground: config.foreground
//	Material.accent: Material.Green
//    Material.elevation: 0
	


	background: Rectangle {
        color: "#D8ECF5"
    }
/*	
	background: Rectangle {
		implicitWidth: 100
		implicitHeight: 40
		color: parent.enabled ? "#D8ECF5" : "red"
//		color: parent.enabled ? ( parent.down ? config.btnColorDown : config.btnColorNormal ) : config.btnColorDisable
//		border.color: parent.down ? "red" : "black"
//		border.color: parent.down ? config.btnColorBorderDown : config.btnColorBorderNormal
		radius: 2
	}
*/	
	function select()
	{
		console.log("currentIndex:",currentIndex);
		console.log("count:",count);
		if( count > 1 )
		{
			var i = 0;
			for(i=0;i<count;i++)
			{
				itemAt(i).bSelected = false;
			}
			currentItem.bSelected = true;	
		}		
	}
	
	Component.onCompleted: select();
}