#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QSettings>
#include <QResource>

class Config : public QObject
{
    Q_OBJECT

};

class SettingsInner : public QObject
{
    Q_OBJECT
public:
    explicit SettingsInner(QObject *parent = 0)
    {
        settings = new QSettings( parent );
    }
    explicit SettingsInner(QString filePath, QObject *parent = 0)
    {
        settings = new QSettings( filePath,
                                  QSettings::IniFormat,
                                  parent);
    }
    ~SettingsInner()
    {
        qDebug() << "~Settings()";

        if( nullptr != settings ){
            delete settings;
            settings = nullptr;
        }
    }
public:
    inline void setValue(const QString &key, const QVariant &value) {
        if( settings )
            settings->setValue(key, value);
    }
    inline QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const {
        if( settings )
            return settings->value(key, defaultValue);
        else
            return QVariant(QStringLiteral("null"));
    }
    inline void setFilePath(const QString &filePath)
    {
        QFile file( filePath );
        if( !file.exists() ){
            qDebug() << "SettingsInner::file do not exist";
            return;
        }
        if(nullptr != settings){
            delete settings;
            settings = new QSettings( filePath,QSettings::IniFormat,Q_NULLPTR );
        }

    }
    inline QString filePath() const {
        if( settings )
            return settings->fileName();
        else
            return QString(QStringLiteral("null"));
    }
public:
    QSettings * settings;
};

Q_DECLARE_METATYPE(SettingsInner*)

class Resource : public Config
{
    Q_OBJECT
public:
    Resource()
    {
        settingsInner = new SettingsInner;

        QString m_iniDirPath = "";
        QString m_iniFileName = "main.ini";
        QString m_iniFilePath = "";
        QString m_skinUrl = "";
        QString m_rccFilePath = "";
        QString m_skinSource = "";

		m_bIniSet = false;
    }
    ~Resource()
    {
        qDebug() << "~Resource()";
        if( settingsInner != nullptr ){
            delete settingsInner;
            settingsInner = nullptr;
        }
    }
public slots:
	/*
	* get skinUrl from ini file
	* load and reload rcc file
	*/
	void reloadSkin()
	{
		retrieveSkinUrl();
		if (!isLoaded()) {
			qDebug() << "load skinRccFilePath direct from: " << getRccFilePath();
			loadSkin(getRccFilePath());
		}
		else {
			qDebug() << "change skin to skinRccFilePath: " << getRccFilePath();
			changeSkin(getRccFilePath());
		}
	}
	//is skin loaded already
	bool isLoaded() {
		if (m_skinSource.isEmpty()) return false;
		else
			return true;
	}

    //set file directory ( "c:\" )
    void setIniDirPath( QString iniDirPath ){
        qDebug() << "+setIniFileDirectory::iniDirPath:" << iniDirPath;
        if( iniDirPath.at(iniDirPath.length() - 1) != "/" )
            iniDirPath.append("/");

        m_iniDirPath = iniDirPath;
		m_iniFilePath = ""; //set m_iniDirPath mean that we will reset m_iniFilePath later
        qDebug() << "-setIniDirPath::m_iniDirPath:" << m_iniDirPath;
    }
    //set file nameh ( "a.ini" )
    void setIniFileName( QString iniFileName ){
        qDebug() << "+setIniFileName::iniFileName:" << iniFileName;
        if( iniFileName.isEmpty() )
            return;

        m_iniFileName = iniFileName;
		m_iniFilePath = ""; //set m_iniFileName mean that we will reset m_iniFilePath later
        qDebug() << "-setIniFileName::m_iniFileName:" << m_iniFileName;
    }
    //set file path ( "c:\a.ini" )
    void setIniFilePath( QString iniFilePath ){
        qDebug() << "+setIniFilePath::iniFilePath:" << iniFilePath;
        if( iniFilePath.isEmpty() )
            return;

        m_iniFilePath = iniFilePath;
        qDebug() << "-setIniFilePath::m_iniFilePath:" << m_iniFilePath;
    }
    void setRccDirPath( QString rccDirPath ){
        qDebug() << "+setRccDirPath::rccDirPath:" << rccDirPath;
        if( rccDirPath.at(rccDirPath.length() - 1) != "/" )
            rccDirPath.append("/");

        m_rccDirPath = rccDirPath;
        qDebug() << "-setIniDirPath::m_rccDirPath:" << m_rccDirPath;
    }
	//is ini file already set
	bool isIniFileAlreadySet() { return m_bIniSet; }
	void setIniReady(bool bReady) { m_bIniSet = bReady; }
private:
    //retrieve skinUrl from ini file 
    void retrieveSkinUrl(){
        if( m_iniDirPath.isEmpty() )
            return;

        if( m_iniFilePath.isEmpty() ){
            qDebug() << "getSkinUrl::m_iniDirPath:" << m_iniDirPath;
            m_iniFilePath = m_iniDirPath + m_iniFileName;
            qDebug() << "getSkinUrl::m_iniFilePath:" << m_iniFilePath;
        }
        else
            qDebug() << "getSkinUrl::m_iniFilePath:" << m_iniFilePath;


        settingsInner->setFilePath( m_iniFilePath );
        QString skinUrl = settingsInner->value("skinUrl").toString();

        if (skinUrl.isEmpty()){
            m_skinUrl = "skin1.rcc";      //set default skin rcc, when skin is needed to change , set setting in posscale.ini , such as "skinUrl=skin2.rcc"
            return;
        }
        else{
            qDebug() << "getSkinUrl::skinUrl is : " << skinUrl;
            m_skinUrl = skinUrl;
        }
    }
    //get rcc 
    QString getRccFilePath(){ 
        //if bin directory is different with ini directory, use bin directory as rcc directory
        if (!m_skinUrl.isEmpty() && !m_rccDirPath.isEmpty()){
            m_rccFilePath = m_rccDirPath + m_skinUrl;
            qDebug() << "getRccFilePath::m_rccFilePath:" << m_rccFilePath;

            return m_rccFilePath;
        }
        //if bin/rcc directory not set , use ini directory as rcc directory
        else if (!m_skinUrl.isEmpty() && !m_iniDirPath.isEmpty()){
            m_rccFilePath = m_iniDirPath + m_skinUrl;
            qDebug() << "getRccFilePath::m_rccFilePath:" << m_rccFilePath;

            return m_rccFilePath;
        }
        else
            return "";
    }

    void loadSkin(QString skin){
        qDebug() << "loadSkin:::QResource::registerResource:" << skin;
        if (skin.isEmpty())
        {
#if defined( WX_2_QT_MESSAGEBOX )
            QMessageBox msgBox;
            msgBox.setText("Cannot find resource file to register");
            msgBox.setWindowTitle("Bizerba Error");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowFlag(Qt::WindowStaysOnTopHint);
            int ret = msgBox.exec();
#endif
        }
        QResource::registerResource( skin );
        m_skinSource = skin;
    }

    void changeSkin(QString newSkin){
        if( m_skinSource.isEmpty() ) return;
        if( newSkin.isEmpty() ) return;

        changeSkin(m_skinSource,newSkin);
    }

    void changeSkin(QString oldSkin,QString newSkin){
        if( oldSkin.isEmpty() ) return;
        if( newSkin.isEmpty() ) return;

        qDebug() << "changeSkin from: " << oldSkin << " to " << newSkin;
        QResource::unregisterResource( oldSkin );
        QResource::registerResource( newSkin );
        m_skinSource = newSkin;
    }
private:
	bool	m_bIniSet;
private:
    QString m_iniDirPath;
    QString m_iniFileName;
    QString m_iniFilePath;
    QString m_skinUrl;
    QString m_rccDirPath;
    QString m_rccFilePath;
    QString m_skinSource;
private:
    SettingsInner * settingsInner;
};



#endif//_RESOURCE_H_
