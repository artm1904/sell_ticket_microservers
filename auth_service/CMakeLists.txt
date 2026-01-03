add_executable(auth_service src/main.cpp)

target_link_libraries(auth_service PRIVATE shared)
target_link_libraries(auth_service PRIVATE project_options)
