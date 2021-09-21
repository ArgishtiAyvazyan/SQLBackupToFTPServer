cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)


set(PROJECT_SOURCES
        "DataBaseMapper.h"
        "DataBaseMapper.cc"
        "LoginInfoAssessorMapper.h"
        "LoginInfoAssessorMapper.cc"
        "UserDataGenerator.h"
        "UserDataGenerator.cc"
        "UserDataAccessorMapper.h"
        "UserDataAccessorMapper.cc"
        "ClientMapper.h"
        "ClientMapper.cc"
        )

add_library(Mapper STATIC ${PROJECT_SOURCES})
target_include_directories(Mapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Mapper PUBLIC Application SQLiteDB FTPClient)
