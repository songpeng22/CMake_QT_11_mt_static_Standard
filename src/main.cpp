#include "main.h"
/*
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
*/
//For static link
#ifdef QT_STATIC
    #include <QtCore/QtPlugin>
    //QWindowsIntegrationPlugin "platforms/qwindows.dll" //Qt5Gui_QWindowsIntegrationPlugin.cmake
    Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#endif

int main(int argc, char *argv[]) {
/*
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
*/
}


