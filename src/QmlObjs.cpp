#include "QmlObjs.h"

#include <vector>
using namespace std;

CQmlObjs::CQmlObjs()
{
}

QObject* CQmlObjs::GetObj(char * objName){
    qDebug() << "Get:" << objName;
    QObject * obj = nullptr;

    vector<CQmlObjFly*>::iterator it = _fly.begin();
	for (; it != _fly.end();it++) 
	{ 
		if ((*it)->objName == objName)
		{ 
            Q_ASSERT(*it);
			qDebug() <<"already created by users:" << (*it)->objName;
            
			return *it; 
		}
	}

    obj = FindSubObject(objName);
    CQmlObjFly * pCQmlObjFly = new CQmlObjFly;
    if (pCQmlObjFly){
        pCQmlObjFly->objName = objName;
        pCQmlObjFly->object = obj;
        _fly.push_back(pCQmlObjFly);
    }
    Q_ASSERT(pCQmlObjFly);
    qDebug() <<"create a new one:" << objName;

    return obj;
}