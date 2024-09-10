
include_directories(".")

message(STATUS "Include directories: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Building sources: ${SOURCES}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(main ${SOURCES})

target_compile_options(main PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-g>
)