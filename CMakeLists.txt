cmake_minimum_required(VERSION 3.0)

project(md5-hash)

find_package(OpenSSL REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} src/main.c)

# Ubuntu
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL OpenSSL::Crypto)

# Raspi
# $ sudo apt install openssl libssl-dev
#target_link_libraries(uds-server uds aes OpenSSL::SSL -lcrypto)
