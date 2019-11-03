project(demo)
cmake_minimum_required(VERSION 2.8)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)
#configure_file (
#  "${PROJECT_SOURCE_DIR}/common/config.h.in"
#  "${PROJECT_BINARY_DIR}/common/config.h"
#  )
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
else()
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++2a -fno-strict-aliasing -Wno-register")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++2a -fno-strict-aliasing -Wno-register")
set(CMAKE_BUILD_TYPE "Release")

include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/include")

execute_process(COMMAND protoc 
    -I=${PROJECT_SOURCE_DIR}/demo/proto 
    --cpp_out=${PROJECT_SOURCE_DIR}/demo  
    ${PROJECT_SOURCE_DIR}/demo/proto/demo.proto)
execute_process(COMMAND protoc 
    -I=${PROJECT_SOURCE_DIR}/demo/proto 
    --cpp_out=${PROJECT_SOURCE_DIR}/demo
    ${PROJECT_SOURCE_DIR}/demo/proto/ovlexp.proto)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(ghead ${PROJECT_BINARY_DIR}/ghead)
add_subdirectory(gpendingpool ${PROJECT_BINARY_DIR}/gpendingpool)
include_directories("${PROJECT_SOURCE_DIR}/gpendingpool/include")
include_directories("${PROJECT_SOURCE_DIR}/ghead/include")
link_directories(${PROJECT_BINARY_DIR}/ghead)
link_directories(${PROJECT_BINARY_DIR}/gpendingpool)

add_executable(demo 
"${PROJECT_SOURCE_DIR}/demo/demo.cpp" 
"${PROJECT_SOURCE_DIR}/demo/demo.pb.cc" 
"${PROJECT_SOURCE_DIR}/demo/ovlexp.pb.cc" 
)

target_link_libraries(demo gpendingpool ghead ${Protobuf_LIBRARIES})