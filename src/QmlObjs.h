#pragma once

#include "main.h"
#include <vector>
using namespace std;

//main.qml
#define OBJ_TEXT1               "objText1"
#define OBJ_TEXT2               "objText2"
#define OBJ_TEXT3               "objText3"
#define OBJ_TAB_WES             "objTabWES"
#define OBJ_TAB_ADJUSTMENT      "objTabAdjustment"
#define OBJ_TAB_ADCPARAMETER    "objTabADCParameters"
#define OBJ_TIMER               "objTimerGetValue"
#define OBJ_TEXT_RESULT         "objTextResult"
#define OBJ_BUSY_INDICATOR      "objBusyIndicator"

//WES
#define OBJ_SERVER_START        "objButtonWESStart"
#define OBJ_SERVER_END          "objButtonWESEND"

//Ajustment.qml
#define OBJ_TEXT_GFACTOR        "objTextEditGFactor"
#define OBJ_BUTTON_SET_GFACTOR  "objButtonSetGFactor"
#define OBJ_COMBO_COUNTRY       "objComboCountry"
#define OBJ_COMBO_LOAD          "objComboLoadCapacity"
#define OBJ_TEXT_WSID           "objTextEditWSID"
#define OBJ_COMBO_SCALE_TYPE    "objComboScaleType"
#define OBJ_CHECK_LINEAR        "objCheckLinearAdjustment"
#define OBJ_CHECK_FILTER        "objCheckHighFilter"
#define OBJ_COMBO_FILTER        "objComboFilter"
#define OBJ_CHECK_EXPERT_MODE   "objCheckExpertMode"
#define OBJ_BUTTON_START        "objButtonStart"
#define OBJ_TEXT_STEP           "objTextStep"
#define OBJ_TEXT_STEP_DESP      "objTextStepDescription"
#define OBJ_PROGRESS            "objProgress"

//ADCParameters.qml
#define OBJ_TEXT_GFACTOR        "objTextEditGFactor"
#define OBJ_BUTTON_SET_GFACTOR  "objButtonSetGFactor"
#define OBJ_CHECK_TILT_COMP     "objCheckTiltComp"
#define OBJ_CHECK_UPDATE_ALLOW  "objCheckUpdateAllow"
#define OBJ_BUTTON_SEAL         "objButtonSeal"


class FlyWeight : public QObject
{
public:
    FlyWeight(){}
};

class CQmlObjFly : public FlyWeight{
public:
    CQmlObjFly(){}
public:
    QString objName;
    QObject* object;
};

class CQmlObjs : public QObject
{
    Q_OBJECT
public:
    CQmlObjs();
    ~CQmlObjs(){
        Cleanup();
    }
public:
    QObject * GetObj(char * objName);
    void SetRootObject(QObject *object){
        m_rootObject = object;
    }
    QObject * FindSubObject(QString qstr) {
        QObject * objParent = m_rootObject;
        if (!objParent) return nullptr;

        QList<QObject *> objSubs = objParent->findChildren<QObject *>();
        if (!objSubs.empty()){
	        for (int i = 0; i < objSubs.size(); ++i) {
                if ( !objSubs.at(i)->objectName().isEmpty() )
#if defined( WX_2_QT_DEBUG_OFF )
                    qDebug() << "Find Sub:" << objSubs.at(i)->objectName();
#endif
                if (objSubs.at(i)->objectName() == qstr){
                    qDebug() <<"Found objectName:" << objSubs.at(i)->objectName();
                    return objSubs.at(i);
                }
            }    
        }
        return nullptr;
    }
    void Cleanup()
    {
        vector<CQmlObjFly*>::iterator it;
        for (it = _fly.begin(); it != _fly.end(); it++){
            CQmlObjFly * pCQmlObjFly = (*it);
            if (pCQmlObjFly){
                delete pCQmlObjFly;
                pCQmlObjFly = nullptr;
            }
        }
    }
public:
    //Property
//    QVariant property(QString object, QString name){
//        if (OBJ_TEXT_RESULT == object)
//            return textOfLog();
//    }
//    void setProperty(QString object, QString name, QVariant value){
//        if (OBJ_TEXT_WSID == object)
//            setTextOfWSID(value.toString());
//        if (OBJ_TIMER == object)
//            setTimerOfRefresh(value.toBool());
//        if (OBJ_TEXT_RESULT == object)
//            setTextOfLog(value.toString());
//    }
/**/
    QVariant propertyEx(QString objectName, QString name){
        if (m_rootObject == nullptr){
            qDebug() << "propertyEx()::invalid m_rootObject";
            return QVariant("");
        }
        QVariant returnedValue;
        QMetaObject::invokeMethod(m_rootObject, "property",
            Qt::DirectConnection,
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, objectName),
            Q_ARG(QVariant, name));
//	    qDebug() << "propertyEx returned:" << returnedValue.toString();

        if (returnedValue.isNull()){
            Q_ASSERT(0);
        }

        return returnedValue;
    }

    /*
    ******************************************************************************
    * setPropertyEx     sets property of QML object
    *                     
    * @param		objectName and property of QML object and its value
    *               
    *                               
    * @return       
    * @remarks		this is the data interface of C++ and QML object
    ******************************************************************************
    */
    void setPropertyEx(QString objectName, QString name, QVariant value){
        if (m_rootObject == nullptr){
            qDebug() << "setPropertyEx()::invalid m_rootObject";
            return;
        }
        QVariant returnedValue;
        QMetaObject::invokeMethod(m_rootObject, "setProperty",
			Qt::DirectConnection,
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, objectName),
			Q_ARG(QVariant, name),
			Q_ARG(QVariant, value));
//	    qDebug() << "setProperty returned:" << returnedValue;

        if (returnedValue.isNull()){
            Q_ASSERT(0);
        }
    }
    //WSID
    //Q_PROPERTY(QString textOfWSID READ textOfWSID WRITE setTextOfWSID NOTIFY textOfWSIDChanged )
    //QString m_textOfWSID;
    //QString textOfWSID(){ return m_textOfWSID; }
    //void setTextOfWSID(QString textOfWSID){
    //    qDebug() << "setTextOfWSID:" << textOfWSID;
    //    m_textOfWSID = textOfWSID;
    //    emit this->textOfWSIDChanged(m_textOfWSID);
    //}
    //GFactor
//    Q_PROPERTY(QString textOfGFactor READ textOfGFactor WRITE setTextOfGFactor NOTIFY textOfGFactorChanged )
//    QString m_textOfGFactor;
//    QString textOfGFactor(){ return m_textOfGFactor; }
//    void setTextOfGFactor(QString textOfGFactor){
//        qDebug() << "setTextOfGFactor:" << textOfGFactor;
//        m_textOfGFactor = textOfGFactor;
//        emit this->textOfGFactorChanged(m_textOfGFactor);
//    }
    //Step
//    Q_PROPERTY(QString textOfStep READ textOfStep WRITE setTextOfStep NOTIFY textOfStepChanged )
//    QString m_textOfStep;
//    QString textOfStep(){ return m_textOfStep; }
//    void setTextOfStep(QString textOfStep){
//        m_textOfStep = textOfStep;
//        emit this->textOfStepChanged(m_textOfStep);
//    }
    //Step Description
//    Q_PROPERTY(QString textOfStepDesp READ textOfStepDesp WRITE setTextOfStepDesp NOTIFY textOfStepDespChanged )
//    QString m_textOfStepDesp;
//    QString textOfStepDesp(){ return m_textOfStepDesp; }
//    void setTextOfStepDesp(QString textOfStepDesp){
//        m_textOfStepDesp = textOfStepDesp;
//        emit this->textOfStepDespChanged(m_textOfStepDesp);
//    }
    //Progress
//    Q_PROPERTY(float valueOfProgress READ valueOfProgress WRITE setValueOfProgress NOTIFY valueOfProgressChanged )
//    float m_valueOfProgress;
//    float valueOfProgress(){ return m_valueOfProgress; }
//    void setValueOfProgress(float valueOfProgress){
//        m_valueOfProgress = valueOfProgress;
//        emit this->valueOfProgressChanged(m_valueOfProgress);
//    }
    //ButtonStart
    //Q_PROPERTY(QString textOfButtonStart READ textOfButtonStart WRITE setTextOfButtonStart NOTIFY textOfButtonStartChanged )
    //QString m_textOfButtonStart;
    //QString textOfButtonStart(){ return m_textOfButtonStart; }
    //void setTextOfButtonStart(QString textOfButtonStart){
    //    m_textOfButtonStart = textOfButtonStart;
    //    emit this->textOfButtonStartChanged(m_textOfButtonStart);
    //}
    //TextResult
    //Q_PROPERTY(QString textOfLog READ textOfLog WRITE setTextOfLog NOTIFY textOfLogChanged )
    //QString m_textOfLog;
    //QString textOfLog(){ return m_textOfLog; }
    //void setTextOfLog(QString textOfLog){
    //    m_textOfLog = textOfLog;
    //    emit this->textOfLogChanged(m_textOfLog);
    //}
    //Timer
//    Q_PROPERTY(bool timerOfRefresh READ timerOfRefresh WRITE setTimerOfRefresh NOTIFY timerOfRefreshChanged )
//    bool m_timerOfRefresh;
//    bool timerOfRefresh(){ return m_timerOfRefresh; }
//    void setTimerOfRefresh(bool timerOfRefresh){
//        m_timerOfRefresh = timerOfRefresh;
//        emit this->timerOfRefreshChanged(m_timerOfRefresh);
//    }
    
signals:
//    void textOfWSIDChanged(QString);
//    void textOfGFactorChanged(QString);
//    void textOfStepChanged(QString);
//    void valueOfProgressChanged(float);
//    void textOfStepDespChanged(QString);
//    void textOfButtonStartChanged(QString);
//    void textOfLogChanged(QString);
//    void timerOfRefreshChanged(bool);
public:
    static CQmlObjs* Instance(){
        static CQmlObjs _instance;
        return &_instance;
    }
protected:
    QObject* m_rootObject; 
private:
	vector<CQmlObjFly*> _fly;
};