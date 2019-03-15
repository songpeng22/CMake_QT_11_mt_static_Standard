set( QT_MSVC2013_64 1 )
set( QT_MSVC2015_32 2 )
set( QT_MSVC2015_64 3 )
set( QT_MSVC2017_64 4 )
set( QT_MSVC2013_32_STATIC 5 )
set( QT_MSVC2015_32_STATIC 6 )

MACRO(CHOOSE_QT_SDK SDK_VERSION)
message("SDK_VERSION: " ${SDK_VERSION})
if( ${SDK_VERSION} EQUAL QT_MSVC2013_64 )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1/5.10.1/msvc2013_64  )
elseif( ${SDK_VERSION} EQUAL QT_MSVC2015_32 )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1/5.10.1/msvc2015     )
elseif( ${SDK_VERSION} EQUAL QT_MSVC2015_64 )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1/5.10.1/msvc2015_64  )
elseif( ${SDK_VERSION} EQUAL QT_MSVC2017_64 )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1/5.10.1/msvc2017_64   )
elseif( ${SDK_VERSION} EQUAL QT_MSVC2013_32_STATIC )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1_mt_static_vs2013  )
elseif( ${SDK_VERSION} EQUAL QT_MSVC2015_32_STATIC )
    set( CMAKE_PREFIX_PATH C:/Qt/Qt5.10.1_mt_static_vs2015   )
endif( ${SDK_VERSION} EQUAL QT_MSVC2013_64 )
message("CMAKE_PREFIX_PATH from MACRO: " ${CMAKE_PREFIX_PATH})
ENDMACRO()


