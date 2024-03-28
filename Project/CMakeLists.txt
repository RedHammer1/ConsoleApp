cmake_minimum_required(VERSION 3.12)

set(EDITOR_PROJECT_NAME "Project")

file(GLOB_RECURSE src src/*.cpp src/*.c include/*.hpp include/*.h )
set(ENGINE_PRIVATE_SOURCES ${src})

add_executable(${EDITOR_PROJECT_NAME} ${src})

target_link_libraries(${EDITOR_PROJECT_NAME} -static gcc stdc++ winpthread -dynamic -Wnarrowing)

target_compile_features(${EDITOR_PROJECT_NAME} PUBLIC cxx_std_17 )

set_target_properties(${EDITOR_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/Project/assets
        ${PROJECT_BINARY_DIR}/bin/assets
        COMMENT "Copying resources into binary directory")
