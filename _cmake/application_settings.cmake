
include(${CMAKE_CURRENT_SOURCE_DIR}/../_cmake/common.cmake)
include(${ROOT_PROJECT_DIR}/_cmake/version.cmake)

configure_file(${ROOT_PROJECT_DIR}/_cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)
