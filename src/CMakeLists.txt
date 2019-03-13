cmake_minimum_required(VERSION 3.1.0)
include("recursive_search.cmake")

project(Solution)

# set(<variable> <value>
#    [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE])
set( project_name QmlStandard )
message( "Project name is: " ${project_name} )

set(QT_STATIC 1)
message( "QT_STATIC is: " ${QT_STATIC} )

MACRO(configureMsvcRuntime)
MESSAGE(STATUS "configureMsvcRuntime() called. ")
    IF(WIN32)
        # Default to statically-linked runtime.
        IF("${MSVC_RUNTIME}" STREQUAL "")
            SET(MSVC_RUNTIME "static")
        ENDIF()

        # Set compiler options.
        SET(variables
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
        )
        IF(${MSVC_RUNTIME} STREQUAL "static")
            MESSAGE("MSVC -> forcing use of statically-linked runtime.")
            FOREACH(variable ${variables})
                IF(${variable} MATCHES "/MD")
                    STRING(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
                ENDIF()
                IF(${variable} MATCHES "/MDd")
                    STRING(REGEX REPLACE "/MDd" "/MTd" ${variable} "${${variable}}")
                ENDIF()
            ENDFOREACH()
        ELSE()
            MESSAGE("MSVC -> forcing use of dynamically-linked runtime.")
            FOREACH(variable ${variables})
                IF(${variable} MATCHES "/MT")
                    STRING(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
                ENDIF()
            ENDFOREACH()
            FOREACH(variable ${variables})
                IF(${variable} MATCHES "/MTd")
                    STRING(REGEX REPLACE "/MTd" "/MDd" ${variable} "${${variable}}")
                ENDIF()
            ENDFOREACH()
        ENDIF()
    ENDIF()
ENDMACRO()
# force to use mtd
IF(QT_STATIC)
    configureMsvcRuntime()
add_definitions(-DQT_STATICPLUGIN)
ENDIF(QT_STATIC)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
#handle rcc automatically( handle qrc file )
set(CMAKE_AUTORCC ON)

# Find the QtWidgets library
find_package( Qt5 REQUIRED 
# QuickWidgets means CMake would search for ".\lib\cmake\Qt5QuickWidgetsConfig.cmake"
    COMPONENTS Core Gui Widgets Qml Quick QuickControls2 #QuickWidgets
)

include_directories(
# Qt5::Core means there is ".\include\QtCore""
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickControls2
)

# set library directory
set(QSTATIC C:/Qt/Qt5.10.1_mt_static_normal/)
set(QLIBDIR ${QSTATIC}lib/)
set(QPLADIR ${QSTATIC}plugins/platforms/)
set(QPLGDIR ${QSTATIC}plugins/)
set(QQMLDIR ${QSTATIC}qml/)

# add library directory
RECURSIVE_SEARCH( ${QPLGDIR}*.lib QPLGDIR_list )
RECURSIVE_SEARCH( ${QQMLDIR}*.lib QQMLDIR_list )
link_directories(
    ${QLIBDIR}
    ${QPLGDIR_list}
    ${QQMLDIR_list}
)

# Platform libs
set(PLIBS
    Dwmapi.lib
    imm32.lib
    Mincore.lib
    Netapi32.lib
    opengl32.lib
    Winmm.lib
    ws2_32.lib
)

# Qt libs( not originally imported )
if(CMAKE_BUILD_TYPE STREQUAL Debug AND ${QT_STATIC} )
    message("CMAKE_BUILD_TYPE: Debug")
        set(QLIBS
        #lib-platform-base
        qtpcre2d.lib
        qtlibpngd.lib
        qtfreetyped.lib
        Qt5PlatformCompositorSupportd.lib
        Qt5EventDispatcherSupportd.lib
        Qt5AccessibilitySupportd.lib
        Qt5ThemeSupportd.lib
        #lib-control-qml
        Qt5FontDatabaseSupportd.lib
        qtharfbuzzd.lib
        Qt5Cored.lib
#       Qt5QuickControls2d.lib
        Qt5QuickTemplates2d.lib
        #plugin-platform
        ${QPLADIR}qwindowsd.lib
        #plugin
        #qml
        ${QQMLDIR}QtQuick.2/qtquick2plugind.lib
        #
        ${QQMLDIR}QtQuick/Window.2/windowplugind.lib
        #
        ${QQMLDIR}QtQuick/Controls.2/qtquickcontrols2plugind.lib
        ${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugind.lib
        #
        ${QQMLDIR}QtQuick/Layouts/qquicklayoutsplugind.lib
        #
        ${QQMLDIR}QtQuick/Controls.2/Fusion/qtquickcontrols2fusionstyleplugind.lib
        ${QQMLDIR}QtQuick/Controls.2/Imagine/qtquickcontrols2imaginestyleplugind.lib
        ${QQMLDIR}QtQuick/Controls.2/Material/qtquickcontrols2materialstyleplugind.lib
        ${QQMLDIR}QtQuick/Controls.2/Universal/qtquickcontrols2universalstyleplugind.lib
        #
        ${QQMLDIR}QtQuick/Dialogs/dialogplugind.lib
#[[
        ${QQMLDIR}QtQuick/Dialogs/Private/dialogsprivateplugind.lib
        ${QQMLDIR}Qt/labs/folderlistmodel/qmlfolderlistmodelplugind.lib
        ${QQMLDIR}Qt/labs/settings/qmlsettingsplugind.lib
        ${QQMLDIR}QtGraphicalEffects/qtgraphicaleffectsplugind.lib
        ${QQMLDIR}QtGraphicalEffects/private/qtgraphicaleffectsprivated.lib
        ${QQMLDIR}QtQml/Models.2/modelsplugind.lib
        ${QQMLDIR}QtQuick/Extras/qtquickextrasplugind.lib
        ${QQMLDIR}QtQuick/PrivateWidgets/widgetsplugind.lib
]]
        )
elseif(CMAKE_BUILD_TYPE STREQUAL Release AND ${QT_STATIC} )
    message("CMAKE_BUILD_TYPE: Release")
    set(QLIBS
        #lib-platform-base
        qtpcre2.lib
        qtlibpng.lib
        qtfreetype.lib
        Qt5PlatformCompositorSupport.lib
        Qt5EventDispatcherSupport.lib
        Qt5AccessibilitySupportd.lib
        Qt5ThemeSupport.lib
        #lib-control-qml
        Qt5FontDatabaseSupport.lib
        qtharfbuzz.lib
        Qt5Core.lib
#        Qt5QuickControls2.lib
        Qt5QuickTemplates2.lib
        #plugin-platform
        ${QPLADIR}qwindows.lib
        #plugin
        #qml
        ${QQMLDIR}QtQuick.2/qtquick2plugin.lib
        #
        ${QQMLDIR}QtQuick/Window.2/windowplugin.lib
        #
        ${QQMLDIR}QtQuick/Controls/qtquickcontrolsplugin.lib
        ${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugin.lib
        #
        ${QQMLDIR}QtQuick/Layouts/qquicklayoutsplugin.lib
        #
        ${QQMLDIR}QtQuick/Controls.2/Fusion/qtquickcontrols2fusionstyleplugin.lib
        ${QQMLDIR}QtQuick/Controls.2/Imagine/qtquickcontrols2imaginestyleplugin.lib
        ${QQMLDIR}QtQuick/Controls.2/Material/qtquickcontrols2materialstyleplugin.lib
        ${QQMLDIR}QtQuick/Controls.2/Universal/qtquickcontrols2universalstyleplugin.lib
        #
        ${QQMLDIR}QtQuick/Dialogs/dialogplugin.lib
#[[
        ${QQMLDIR}QtQuick/Dialogs/Private/dialogsprivateplugin.lib
        ${QQMLDIR}Qt/labs/folderlistmodel/qmlfolderlistmodelplugin.lib
        ${QQMLDIR}Qt/labs/settings/qmlsettingsplugin.lib
        ${QQMLDIR}QtGraphicalEffects/qtgraphicaleffectsplugin.lib
        ${QQMLDIR}QtGraphicalEffects/private/qtgraphicaleffectsprivate.lib
        ${QQMLDIR}QtQml/Models.2/modelsplugin.lib
        ${QQMLDIR}QtQuick/Extras/qtquickextrasplugin.lib
        ${QQMLDIR}QtQuick/PrivateWidgets/widgetsplugin.lib
]]
        )
elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
    message("CMAKE_BUILD_TYPE: Debug  && not static ")
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    message("CMAKE_BUILD_TYPE: Release  && not static ")
else(CMAKE_BUILD_TYPE STREQUAL Debug)
    message(FATAL_ERROR "please set CMAKE_BUILD_TYPE = Debug | Release")
endif(CMAKE_BUILD_TYPE STREQUAL Debug AND ${QT_STATIC})

# Populate a CMake variable with the sources
FILE(GLOB project_sources
    main.cpp
)

FILE(GLOB project_headers
    *.h
)

SET( project_resources 
    main.qrc
    main.qml
)

# Tell CMake to create the project executable
add_executable( ${project_name} WIN32 ${project_sources} ${project_headers} ${project_resources})

set_target_properties( ${project_name}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)

# Must After add_executable
target_link_libraries( ${project_name}
    ${PLIBS}
    ${QLIBS}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Qml_LIBRARIES}
    ${Qt5Quick_LIBRARIES}
    ${Qt5QuickControls2_LIBRARIES}
)

#Message Test
MESSAGE(STATUS "This is test: " ${Qt5Gui_LIBRARIES})

