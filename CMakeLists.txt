cmake_minimum_required(VERSION 3.22)

project(tinyvm)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(tinyvm main.cxx vm/vm.cxx bytecodeio/bytecodeio.cxx assembler/assembler.cxx)

target_include_directories(tinyvm PUBLIC
    ${CMAKE_SOURCE_DIR}
    .
    vm
    bytecodeio
    assembler
)
