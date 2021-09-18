cmake_minimum_required(VERSION 3.0.0)
project(Checkers VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    src/main.cpp
    src/Game.cpp
)

add_executable(Checkers ${SOURCES})

target_include_directories(Checkers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/header
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
