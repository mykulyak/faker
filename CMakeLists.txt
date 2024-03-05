cmake_minimum_required(VERSION 3.16)

project(faker VERSION 0.0.1)

option(USE_CXX20 "Use C++20 functionality" OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (USE_CXX20)
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/ClangFormat.cmake)
include(cmake/SafetyFeatures.cmake)

# 3rd party dependencies

find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

enable_testing()

add_library(faker STATIC)
target_include_directories(faker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(faker PRIVATE fmt::fmt)

if (USE_CXX20)
    target_compile_definitions(faker PUBLIC -DFAKER_USE_STD_SPAN)
endif()

turn_on_warnings(faker)

add_subdirectory(src)
add_subdirectory(tests)