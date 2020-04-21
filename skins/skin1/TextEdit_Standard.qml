import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0

Flickable 
{
	id: flick

	width: 300; height: 100;
	contentWidth: edit.paintedWidth
	contentHeight: edit.paintedHeight
	clip: true
	
	property var varText: ""
	property var varCursorPosition: 0
	
	function ensureVisible(r)
	{
		if (contentX >= r.x)
			contentX = r.x;
		else if (contentX+width <= r.x+r.width)
			contentX = r.x+r.width-width;
		if (contentY >= r.y)
			contentY = r.y;
		else if (contentY+height <= r.y+r.height)
			contentY = r.y+r.height-height;
	}

	TextEdit 
	{
		id: edit
		width: flick.width
		focus: true
		wrapMode: TextEdit.Wrap
		text: varText
		cursorPosition: varCursorPosition
		
		onCursorRectangleChanged: {	
			flick.ensureVisible(cursorRectangle);
			
			console.log("onCursorRectangleChanged");
		}
		
		onEditingFinished:
		{
			console.log("TextEdit::onEditingFinished:");
		}
	}
	
	function insert( position,str )
	{
		edit.insert( position,str );
	}
}