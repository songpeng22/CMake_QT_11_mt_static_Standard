import QtQuick 2.9

QtObject {
    //Platform
    property bool isMoblie: Qt.platform.os==="android" || Qt.platform.os==="ios"
	//Geometry 
	property var varLineHeight: 20
	//Font
	property var varFontSize: 10
	//--------------------Color:Config--------------------
	property var colors : [btnColorDown, btnColorNormal, btnColorDisable,btnColorBorderDown,btnColorBorderNormal,btnColorTextDown,btnColorTextNormal,btnColorTextDisable,textColorReadOnly,textColorNormal,textColorBorderReadOnly,textColorBorderNormal ];
	property var colorsText : ["btnColorDown", "btnColorNormal", "btnColorDisable","btnColorBorderDown","btnColorBorderNormal","btnColorTextDown","btnColorTextNormal","btnColorTextDisable","textColorReadOnly","textColorNormal","textColorBorderReadOnly","textColorBorderNormal" ];	
	//Color:Background
	property var bkColor: "#D8ECF5" //from  k3
	//Color:Button
	property color btnColorDown : "white"
	property color btnColorNormal : "#FEB648"
	property color btnColorDisable : "#CCCCCC"
	property color btnColorBorderDown : "red"
	property color btnColorBorderNormal : "black"
	property color btnColorTextDown : "black"
	property color btnColorTextNormal : "teal"
	property color btnColorTextDisable : "#8C8C8C"
	//Color:Text
	property color textColorReadOnly : "#F0F0F0"
	property color textColorNormal : "white"
	property color textColorBorderReadOnly : "#D4D4D4"
	property color textColorBorderNormal : "lightblue"
	
    
}

