cmake_minimum_required(VERSION 3.14)

project(click4ever VERSION 1.3.0)

include(CheckSymbolExists)

add_executable(click4ever)

find_file("xdo header" "xdo.h")
find_library("xdo library" xdo REQUIRED)
target_link_libraries(click4ever PRIVATE xdo)

find_file("unistd header" "unistd.h")
check_symbol_exists(usleep "unistd.h" HAVE_USLEEP)
if(NOT HAVE_USLEEP)
  message(FATAL_ERROR "The usleep function is required.")
endif()

find_package(Boost 1.36.0 REQUIRED COMPONENTS program_options)
target_link_libraries(click4ever PRIVATE Boost::program_options)

target_compile_definitions(click4ever PRIVATE -DCMAKE_PROJECT_NAME="${CMAKE_PROJECT_NAME}")
target_compile_definitions(click4ever PRIVATE -DCMAKE_PROJECT_VERSION="${CMAKE_PROJECT_VERSION}")
target_sources(click4ever PRIVATE
  src/main.cpp
  src/click.cpp
  src/time_utils.cpp)

install(TARGETS click4ever)
