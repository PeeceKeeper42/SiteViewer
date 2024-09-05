
cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(siteViewer  VERSION 1.0.0
                    DESCRIPTION "Simple C++/Qt 5.15.2 bot looking for updates on certain websites"
                    LANGUAGES CXX)

include(${CMAKE_SOURCE_DIR}/../_cmake/paths.cmake)

include(${CMAKE_DIRECTORY}/setup.cmake)
include(${CMAKE_DIRECTORY}/applyConfiguration.cmake)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(${PROJECT_NAME}
    main.cpp
    logger.h
    logger.cpp
    tgBot/tgBot.h
    tgBot/tgBot.cpp
    )

target_link_directories(${PROJECT_NAME}
    PRIVATE ${INCLUDE_DIRECTORY}
    PRIVATE ${SYS_LIB_PATH}
)

find_package(OpenSSL REQUIRED)

target_link_libraries(${PROJECT_NAME}
    #PRIVATE _core
    #PRIVATE _settings
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Network
)
















