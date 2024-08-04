# Create build system: cmake -B build
# Build command:       cmake --build build (binaries in build/output)
# Clean command:       make -C build clean

cmake_minimum_required(VERSION 3.10)

project(bit_manip)

set(SRCDIR "./source")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/output)

set(SOURCES
        ${SRCDIR}/bit_manip.c
        ${SRCDIR}/bit_manip_algorithms.c
        ${SRCDIR}/bit_manip_interface.c
        ${SRCDIR}/bit_manip_print_funcs.c)

add_executable(Bit_Manip ${SOURCES})

add_executable(Bit_Manip_Multi ${SOURCES})

target_compile_definitions(Bit_Manip_Multi
          PRIVATE   MULTI_PASS_TESTS
        )

