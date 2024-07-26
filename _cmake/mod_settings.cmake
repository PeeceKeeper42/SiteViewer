
include(${CMAKE_CURRENT_SOURCE_DIR}/../../../_cmake/common.cmake)
include(${ROOT_PROJECT_DIR}/_cmake/version.cmake)

# Variables for libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MOD_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MOD_DIRECTORY})
set(RUNTIME_OUTPUT_NAME lib${PROJECT_NAME}.so)

configure_file(${ROOT_PROJECT_DIR}/_cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

