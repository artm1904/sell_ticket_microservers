add_library(shared INTERFACE)

target_include_directories(shared INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Connect Oat++ to shared, so everyone using shared gets Oat++
target_link_libraries(shared INTERFACE oatpp)
target_link_libraries(shared INTERFACE project_options)