cmake_minimum_required(VERSION 3.0)

project(test_vec_mat LANGUAGES CXX)

find_package( Threads REQUIRED )

add_executable(test_image test_image.cpp)

target_include_directories(test_image PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vectorMatrix)

target_link_libraries(test_image image
    debug gtestd optimized gtest
    debug gmockd optimized gmock
    ${CMAKE_THREAD_LIBS_INIT})
