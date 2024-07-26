# Variables for generating the version. Used in the application (config.h file)
#
# BUILD_DATE - date in format 'yyyy-mm-dd'
# BUILD_NUM - number of build (days of year)
# PROJECT_VERSION_PATCH - in format 'yyyy'
#
# Application version format: 'MAJOR.MINOR.yy.mmdd'

string(TIMESTAMP BUILD_DATE "%Y-%m-%d %H:%M")

string(TIMESTAMP BUILD_NUM "%j")

math(EXPR BUILD_NUM ${BUILD_NUM})

string(SUBSTRING ${BUILD_DATE} 0 4 YEAR_STR)

set(PROJECT_VERSION_PATCH ${YEAR_STR})

set(ORIGINAL_FILE_NAME ${RUNTIME_OUTPUT_NAME})
