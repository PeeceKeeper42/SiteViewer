
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





find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME}
    main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    #PRIVATE _nayk_core
    #PRIVATE _settings
    PRIVATE Qt${QT_VERSION_MAJOR}::Core

)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${INCLUDE_DIRECTORY}
)


set(OPENSSL_ROOT_DIR "/usr/bin/openssl")
set(OPENSSL_INCLUDE_DIR "/usr/include/openssl/")

find_package(OpenSSL REQUIRED)
if( OpenSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    link_directories(${OPENSSL_LIBRARIES})
    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")

    message("OPENSSL_INCLUDE_DIRS = ${OPENSSL_INCLUDE_DIRS}")
    message("OPENSSL_LIBRARIES = ${OPENSSL_LIBRARIES}")
endif()

target_link_libraries(project_name /path/of/libssl.so /path/of/libcrypto.so)












