cmake_minimum_required (VERSION 2.8)
project (mcstatus)

set (SOURCE_FILES
    "./src/main.cpp"
    "./src/packet.cpp"
    "./src/mcstatus.cpp"
)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.55 COMPONENTS system thread REQUIRED)
if(${Boost_FOUND})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIR})
endif()

add_executable (mcstatus ${SOURCE_FILES})

# Boost
target_link_libraries(mcstatus ${Boost_LIBRARIES})
