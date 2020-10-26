cmake_minimum_required(VERSION 3.10)

project(click4ever VERSION 1.0.3)

add_executable(click4ever src/click4ever.c)

target_link_libraries(click4ever PRIVATE xdo)

include(CheckSymbolExists)

find_file("stdlib header" "stdlib.h")

find_file("inttypes header" "inttypes.h")

find_file("time header" "time.h")

find_file("xdo header" "xdo.h")
find_library("xdo library" xdo REQUIRED)

find_file("unistd header" "unistd.h")
check_symbol_exists(usleep "unistd.h" HAVE_USLEEP)
if(NOT HAVE_USLEEP)
  message(FATAL_ERROR "The usleep function is required.")
endif()

install(TARGETS click4ever)
