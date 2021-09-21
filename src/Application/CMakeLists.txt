cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)


set(PROJECT_SOURCES
        "IClient.h"
        "IDataBase.h"
        "UserData.h"
        "ILoginInfoAssessor.h"
        "IUserDataAccessor.h"
        "MainApplication.h"
        "MainApplication.cc")

add_library(Application STATIC ${PROJECT_SOURCES})
target_include_directories(Application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})