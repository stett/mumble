cmake_minimum_required (VERSION 3.0.1)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")


project(Mumble)


if (UNIX)
    add_definitions(-std=c++0x -pthread -Wall -Wextra)
elseif(WIN32)
    add_definitions(-std=c++0x -pthread -Wall)
endif()


include_directories(${Mumble_SOURCE_DIR}/include,
                    ${Mumble_SOURCE_DIR}/extern/include)


#find_package(SFML 2 REQUIRED system audio) #window graphics network audio
link_directories(${Mumble_SOURCE_DIR}/extern/lib)

add_executable(Mumble main.cpp)


target_link_libraries(Mumble sfml-system sfml-audio)