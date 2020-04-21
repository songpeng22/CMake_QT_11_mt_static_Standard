#ifndef _QUICKVIEW_RELOADER_H__
#define _QUICKVIEW_RELOADER_H__

//Common
#include <QObject>
#include <QDebug>
#include <QString>
#include <QUrl>
//View
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
//Style
#include <QQuickStyle>

class QuickViewReloader : public QObject
{
    Q_OBJECT

public:
    QuickViewReloader(QObject *parent = 0);

    void load(QUrl &source);
    QObject * rootObject() {
        if (m_view){
            Q_ASSERT(m_view->rootObject());
            return (QObject *)m_view->rootObject();
        }
        return nullptr;
    }

private:
    virtual bool initSkin(){ return false; }
    virtual QString readConf() { return ""; }
    virtual void beforeLoad();
    virtual void afterLoad();
public slots:
    void reloadStyle(const QString &style);

private slots:
    void reload();
protected:
    QUrl m_source;
    QString m_style;
    QQuickView * m_view;
    QQmlContext * m_qmlContext;
};


#endif//_QUICKVIEW_RELOADER_H__
