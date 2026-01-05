cmake_minimum_required(VERSION 3.10)
project(gateway VERSION 0.1.0)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp") # Только src!


add_executable(gateway
    ${SOURCES})

target_link_libraries(gateway PRIVATE project_options)
target_link_libraries(gateway PRIVATE shared)
target_link_libraries(gateway PRIVATE oatpp::oatpp-swagger)

target_compile_definitions(gateway PRIVATE OATPP_SWAGGER_RES_PATH="${LIB_DIR}/oatpp-swagger/res")


