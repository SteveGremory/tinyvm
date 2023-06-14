cmake_minimum_required(VERSION 3.22)
project(tinyvm)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fstack-protector")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(tinyvm main.cxx vm/vm.cxx bytecodeio/bytecodeio.cxx)

target_include_directories(tinyvm PUBLIC
    ${CMAKE_SOURCE_DIR}
)
