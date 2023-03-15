cmake_minimum_required(VERSION 3.23)
project(ClinicMate_backend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB INCLUDES include/*.h)
file(GLOB SRCS src/*.cpp)

find_package(websocketpp REQUIRED)

add_executable(ClinicMate_backend ${INCLUDES} ${SRCS})

target_link_libraries(${PROJECT_NAME} PRIVATE websocketpp::websocketpp)
