cmake_minimum_required(VERSION 3.14)
project(simple-cam)

add_compile_options(-std=c++17 -Wall -Wstrict-aliasing -Wno-unused-parameter -faligned-new -Werror -Wfatal-errors)
# -pedantic
add_definitions(-D_FILE_OFFSET_BITS=64)
if(CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-Wno-psabi)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCAMERA REQUIRED libcamera)

include_directories(${LIBCAMERA_INCLUDE_DIRS})

file(GLOB SOURCES CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(simple-cam ${SOURCES})
target_link_libraries(simple-cam stdc++fs camera camera-base event event_pthreads ${OpenCV_LIBS})
