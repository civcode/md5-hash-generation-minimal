cmake_minimum_required(VERSION 3.0)

project(md5-hash)

find_package(OpenSSL REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL OpenSSL::Crypto)