cmake_minimum_required(VERSION 3.16)

project(SQLBackupToFTPServer)

set(PROJECT_SOURCES "Main.cc")

add_executable(SQLBackupToFTPServer_exec ${PROJECT_SOURCES})
target_include_directories(SQLBackupToFTPServer_exec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SQLBackupToFTPServer_exec PUBLIC Application Mapper)
