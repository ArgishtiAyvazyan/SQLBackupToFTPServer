cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)


set(PROJECT_SOURCES
        "DataBase.h"
        "DataBase.cc")

add_library(SQLiteDB STATIC ${PROJECT_SOURCES})
target_include_directories(SQLiteDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SQLiteDB PUBLIC sqlite3)

#if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#    # using GCC
#    target_link_libraries(SQLiteDB PRIVATE pthread tbb)
#endif()
