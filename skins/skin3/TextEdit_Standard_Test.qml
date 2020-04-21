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
	color: "teal"
	
	property var index: 0
	
	TextEdit_Standard
	{
		id: idTextEdit
		varText: "hello world \n1...\n2...\n3...\n4...\n5...\n6...\n7...\n8...\n9..."
		
		Component.onCompleted:{
			varCursorPosition = idTextEdit.varText.length;
		}
	}

	Button{
		y: idTextEdit.y + idTextEdit.height
		text: "insert"
		onClicked:
		{
			var str = "";
			index = index + 1;
			str = str + "\n" + index;
			//*** bug in insert , the position is not right
			idTextEdit.insert(idTextEdit.varText.length,str);
			idTextEdit.varCursorPosition = idTextEdit.varText.length;
			
		}
	}

}