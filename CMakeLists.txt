cmake_minimum_required(VERSION 3.5.0)
project(voxelEngine VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(SOURCES
   src/main.c
   src/app.c
   src/color.c
   src/block.c
   src/matrix.c
)

find_package(SDL2 REQUIRED COMPONENTS SDL2)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

target_include_directories(${PROJECT_NAME} PRIVATE include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
