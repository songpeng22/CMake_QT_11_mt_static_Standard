#include "main.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

//For static link
#ifdef QT_STATIC
    //Qt
    #include <QtCore/QtPlugin>
    //QWindowsIntegrationPlugin "platforms/qwindows.dll" //Qt5Gui_QWindowsIntegrationPlugin.cmake
    Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
    //Install Qml plugins
#include <QtQml/QQmlExtensionPlugin>
    //${QQMLDIR}QtQuick.2/qtquick2plugind.lib
    Q_IMPORT_PLUGIN(QtQuick2Plugin)
    //${QQMLDIR}QtQuick/Window.2/windowplugind.lib
    Q_IMPORT_PLUGIN(QtQuick2WindowPlugin)
    //${QQMLDIR}QtQuick/Controls.2/qtquickcontrols2plugind.lib
    //${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugind.lib
    //${QLIBDIR}Qt5QuickTemplates2d.lib
    Q_IMPORT_PLUGIN(QtQuickControls2Plugin)
    //${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugind.lib
    //${QLIBDIR}Qt5QuickTemplates2d.lib
    Q_IMPORT_PLUGIN(QtQuickTemplates2Plugin)
    //${QQMLDIR}QtQuick/Layouts/qquicklayoutsplugind.lib
    Q_IMPORT_PLUGIN(QtQuickLayoutsPlugin)
    //${QQMLDIR}QtQuick/Controls.2/Fusion/qtquickcontrols2fusionstyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Imagine/qtquickcontrols2imaginestyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Material/qtquickcontrols2materialstyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Universal/qtquickcontrols2universalstyleplugin.lib
    Q_IMPORT_PLUGIN(QtQuickControls2FusionStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2ImagineStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2MaterialStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2UniversalStylePlugin)
    //${QQMLDIR}QtQuick/Dialogs/dialogplugind.lib
    //QtQuick/Dialogs/Private/dialogsprivateplugind.lib
    Q_IMPORT_PLUGIN(QtQuick2DialogsPlugin)
    Q_IMPORT_PLUGIN(QtQuick2DialogsPrivatePlugin)
    //${QQMLDIR}Qt/labs/folderlistmodel/qmlfolderlistmodelplugind.lib
    Q_IMPORT_PLUGIN(QmlFolderListModelPlugin)
    //${QQMLDIR}Qt/labs/settings/qmlsettingsplugin.lib
    Q_IMPORT_PLUGIN(QmlSettingsPlugin)
    //${QQMLDIR}QtGraphicalEffects/qtgraphicaleffectsplugin.lib
    Q_IMPORT_PLUGIN(QtGraphicalEffectsPlugin)
    //${QQMLDIR}QtGraphicalEffects/private/qtgraphicaleffectsprivate.lib
    Q_IMPORT_PLUGIN(QtGraphicalEffectsPrivatePlugin)
    //${QQMLDIR}QtQml/Models.2/modelsplugin.lib
    Q_IMPORT_PLUGIN(QtQmlModelsPlugin)
    //${QQMLDIR}QtQuick/Extras/qtquickextrasplugin.lib
    Q_IMPORT_PLUGIN(QtQuickExtrasPlugin)
    //${QQMLDIR}QtQuick/PrivateWidgets/widgetsplugin.lib
    Q_IMPORT_PLUGIN(QtQuick2PrivateWidgetsPlugin)
    //QtQuick\Controls/qtquickcontrolsplugind.lib
    Q_IMPORT_PLUGIN(QtQuickControls1Plugin)

#endif

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


