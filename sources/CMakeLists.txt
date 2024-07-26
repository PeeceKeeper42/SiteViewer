# SiteViewer

cmake_minimum_required(VERSION 3.24)

project(siteViewer
    VERSION 1.0
    DESCRIPTION "Bot looking for updates on certain sites and notifies user"
    LANGUAGES CXX)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

include(${CMAKE_CURRENT_SOURCE_DIR}/../_cmake/application_settings.cmake)

set(PROJECT_SOURCES
    main.cpp
    #mainwindow.cpp
    #mainwindow.h
    #mainwindow.ui
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ${LIB_DIRECTORY}
    PRIVATE ${MOD_DIRECTORY}
    PRIVATE ${SYS_LIB_PATH}
)

target_link_libraries(${PROJECT_NAME}
    #PRIVATE _nayk_core
    #PRIVATE _settings
    PRIVATE Qt${QT_VERSION_MAJOR}::Core

)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    #PRIVATE ${ROOT_PROJECT_DIR}/sources/lib/nayk_core
    #PRIVATE ${ROOT_PROJECT_DIR}/sources/lib/nayk_widgets
    #PRIVATE ${ROOT_PROJECT_DIR}/sources/modules/sntn
    #PRIVATE ${ROOT_PROJECT_DIR}/sources/modules/login
)
