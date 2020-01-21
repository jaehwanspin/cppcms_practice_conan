find_library(LIB_BOOSTER booster)
find_library(LIB_CPPCMS cppcms)
#find_library(LIB_CPPDB cppdb)
find_path(INC_BOOSTER booster/config.h)
find_path(INC_CPPCMS cppcms/config.h)

include_directories(${INC_BOOSTER})
include_directories(${INC_CPPCMS})
#include_directories(${INC_CPPDB})

set(SOURCES main.cc)

add_executable(webserver ${SOURCES})
#target_link_libraries(webserver)
target_link_libraries(webserver ${LIB_CPPCMS})
target_link_libraries(webserver ${CONAN_LIBS})