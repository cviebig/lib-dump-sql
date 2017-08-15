cmake_minimum_required(VERSION 3.1)
project(lib-dump-sql)


if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
     find_package( lib-dump )
     find_package( lib-sql )
endif()


# Boost
find_package( Boost 1.61.0 COMPONENTS filesystem system program_options )
include_directories( ${Boost_INCLUDE_DIR} )


# Library
add_library(dump_sql INTERFACE)
target_include_directories(dump_sql INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(dump_sql INTERFACE dump sql)
export(TARGETS dump_sql FILE dump_sqlConfig.cmake)
export(PACKAGE dump_sql)

# set_property(TARGET dump_sql PROPERTY CXX_STANDARD 14)
# set_property(TARGET dump_sql PROPERTY CXX_STANDARD_REQUIRED ON)


# SQL dumper library
add_library(dump_sql_dumper SHARED src/dump/sql/dumper.cpp)
target_link_libraries(dump_sql_dumper
                      PUBLIC
                      dump_sql
                      )
target_include_directories(dump_sql_dumper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
export(TARGETS dump_sql_dumper FILE dump_sql_dumperConfig.cmake)
export(PACKAGE dump_sql_dumper)

set_property(TARGET dump_sql_dumper PROPERTY CXX_STANDARD 14)
set_property(TARGET dump_sql_dumper PROPERTY CXX_STANDARD_REQUIRED ON)


# Catch
enable_testing(true)
set(TEST_ENABLED true)


# Tests
add_subdirectory(test)
