project (demo)
cmake_minimum_required(VERSION 2.8)

add_subdirectory("../" "../bin")
include_directories("../include")

set (SOURCES_LIST
    "./src/main.cpp"
)

add_executable(demo ${SOURCES_LIST})
target_link_libraries(demo mcstatus)
