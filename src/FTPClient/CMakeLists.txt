cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)


set(PROJECT_SOURCES
        "Client.h"
        "Client.cc")

add_library(FTPClient STATIC ${PROJECT_SOURCES})
target_include_directories(FTPClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})