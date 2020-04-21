import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

Item
{
	width: 800
	height: 600
	
	TabBar_Standard
	{
		id: idTabView21
		objectName : "objTabView21"
		x: 100
		y: 100
//		width: parent.width
//		height: 30
		
		TabButton_Standard {
			id: idTabWES
			objectName : "objTabWES"
			visible: true
			text: qsTr("WES")
			anchors.verticalCenter:parent.verticalCenter
//				height: 25
			onClicked: idTabView21.select();
		}
		TabButton_Standard {
			id: idTabAdjustment
			objectName : "objTabAdjustment"
			visible: true
			text: qsTr("Adjustment")
			anchors.verticalCenter:parent.verticalCenter
//				height: 25	
			onClicked: idTabView21.select();
		}
		TabButton_Standard {
			id: idTabADCParameters
			objectName : "objTabADCParameters"
			visible: true
			text: qsTr("ADCParameters")
			anchors.verticalCenter:parent.verticalCenter
//				height: 25	
			onClicked: idTabView21.select();
		}
	
		Component.onCompleted:
		{
			console.log("idTabView21 height:",height);
			idTabWES.bSelected = true;
		}
	}
}