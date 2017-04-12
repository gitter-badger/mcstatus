cmake_minimum_required (VERSION 3.1)
project (mcstatus)

set(PROJECT_SOURCE_DIR "./src")
set(PROJECT_INCLUDE_DIR "./include")

set (SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/packet.cpp"
    "${PROJECT_SOURCE_DIR}/mcstatus.cpp"
)

set(CMAKE_CXX_STANDARD 11)

# Boost
find_package(Boost 1.55 COMPONENTS system thread REQUIRED)
if(${Boost_FOUND})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIR})
endif()

include_directories(${PROJECT_INCLUDE_DIR})

add_library(mcstatus SHARED ${SOURCE_FILES})

# linking boost
target_link_libraries(mcstatus ${Boost_LIBRARIES})

# Install
install (TARGETS mcstatus LIBRARY DESTINATION lib)
install (FILES "${PROJECT_INCLUDE_DIR}/mcstatus/mcstatus.hpp" "${PROJECT_INCLUDE_DIR}/mcstatus/packet.hpp" DESTINATION include/mcstatus)
