#ifndef _QUICKVIEW_RELOADER_WRAPPER_H__
#define _QUICKVIEW_RELOADER_WRAPPER_H__

#include "QuickViewReloader.h"
#include "Resource.h"
#include "Settings.h"

class QuickViewReloaderWrapper : public QuickViewReloader
{
public:
    QuickViewReloaderWrapper();
    ~QuickViewReloaderWrapper();
private:
    virtual bool initSkin();
    virtual QString readConf();
    virtual void beforeLoad();
    virtual void afterLoad();
    virtual void setContextProperies( QQmlContext * pQmlContext );
    virtual void registerToQml();
    void Clear();
protected:
    Resource *m_res;
    Settings *m_settings;
};


#endif//_QUICKVIEW_RELOADER_WRAPPER_H__
