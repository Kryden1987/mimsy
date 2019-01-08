cmake_minimum_required(VERSION 3.0)

project(mimsy C CXX ASM)

if(NOT DEFINED MIMSY_VERSION_MAJOR)
  set(MIMSY_VERSION_MAJOR 0)
endif()

if(NOT DEFINED MIMSY_VERSION_MINOR)
  set(MIMSY_VERSION_MINOR 0)
endif()

if(NOT DEFINED MIMSY_VERSION_PATCH)
  set(MIMSY_VERSION_PATCH 0)
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -Wall")

set_source_files_properties(header.S main.cpp PROPERTIES COMPILE_FLAGS "-fpic")

set(SRC_LIST source/boot/header.S source/boot/stub.S source/mimsy/main.cpp setup.ld)

include_directories(include/)

include_directories(source/boot/)

set(OBJECTS ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.so.dir/source)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/setup.ld)

set(CMAKE_CXX_LINK_EXECUTABLE "ld -T ${LINKER_SCRIPT} ${OBJECTS}/boot/header.S.o ${OBJECTS}/boot/stub.S.o ${OBJECTS}/mimsy/main.cpp.o -o ${PROJECT_NAME}.so")

add_executable(${PROJECT_NAME}.so ${SRC_LIST})

add_custom_command(TARGET  ${PROJECT_NAME}.so COMMAND objcopy -j .header -j .text -j .init -j .data -j .rodata -j .reloc -O binary ${PROJECT_NAME}.so ${PROJECT_NAME}.efi DEPENDS ${PROJECT_NAME}.so)

add_custom_target(${PROJECT_NAME}.efi ALL DEPENDS ${PROJECT_NAME}.so)
