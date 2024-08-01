# ... - From "Min" to "Max" version.
# Behavior will be adapted to installed version.
# NOTE: De facto standart is to name cmake func in lowercase.
cmake_minimum_required(VERSION 3.7...3.29)

# "..." feature was introduced in Cmake 3.12,
# so earlier versions need to use this crutch.
# NOTE: userver use "cmake_policy" thing very much.
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# classic, no need to explain.
project(siteViewer  VERSION 1.0.0
                    DESCRIPTION "Simple C++/Qt 5.15.2 bot looking for updates on certain websites"
                    LANGUAGES CXX)

# Qt related things
find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Add files that will be executable, only to run things...
# There another command to compile libs
add_executable(${PROJECT_NAME}
    main.cpp
    )

# Qt related things
target_link_libraries(${PROJECT_NAME}
    #PRIVATE _nayk_core
    #PRIVATE _settings
    PRIVATE Qt${QT_VERSION_MAJOR}::Core

)

# You can compile libs right there.
# TODO: Modificator like STATIC SHARED and INTERFACE

# Here we create target for lib
add_library(exampleLib STATIC exampleLib.hpp exampleLib.cpp)
# And there we link lib_target to executable_target (exampleLib to siteViewer)
# so now we can use exampleLib in siteViewer. Big time!
target_link_libraries(${PROJECT_NAME} PUBLIC exampleLib
)

# TODO: Things to explain later

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)






