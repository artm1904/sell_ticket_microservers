cmake_minimum_required(VERSION 3.20)
project(ticket_sell_microservice VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/contrib)

include(cmake/cpm.cmake)

CPMAddPackage(
    NAME GOOGLETEST
    GITHUB_REPOSITORY google/googletest
    VERSION 1.16.0
    SOURCE_DIR ${LIB_DIR}/googletest
    OPTIONS
    "INSTALL_GTEST OFF"
    "gtest_force_shared_crt ON"
)
enable_testing()



CPMAddPackage(
    NAME oatpp
    GIT_REPOSITORY https://github.com/oatpp/oatpp.git
    GIT_TAG master
    SOURCE_DIR ${LIB_DIR}/oatpp
)
set(OATPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)



add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)
set_property(TARGET project_options PROPERTY CXX_EXTENSIONS OFF)

target_compile_options(project_options INTERFACE

    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-pedantic>
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:Debug>:-O0;-g>
)



# --- Subdirectories ---
add_subdirectory(shared)
add_subdirectory(gateway_service)
add_subdirectory(auth_service)
add_subdirectory(ticket_service)
