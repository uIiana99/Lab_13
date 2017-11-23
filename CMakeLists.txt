cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/SimonRussia/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "ef53eaa092c18d1ae26299daa4ea84d0f1d979ef"
)

project(json)


hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

add_executable(pack ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)
target_link_libraries(pack nlohmann_json Boost::system Boost::filesystem)

add_executable(unpack ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack.cpp)
target_link_libraries(unpack nlohmann_json Boost::system Boost::filesystem)