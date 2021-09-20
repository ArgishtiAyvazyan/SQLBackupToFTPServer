cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)

set(PROJECT_SOURCES
        "sqlite3.h"
        "sqlite3.c")

add_library(sqlite3 STATIC ${PROJECT_SOURCES})
target_include_directories(SQLiteDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
