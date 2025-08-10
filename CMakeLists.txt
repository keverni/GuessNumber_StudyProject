cmake_minimum_required(VERSION 3.10)

# variables

set(PROJECT_NAME guess_number)
set(TEST_NAME unittest)
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH ${CMAKE_SOURCE_DIR}/test)

# project

project(${PROJECT_NAME} VERSION 1.0)

# build

file(GLOB_RECURSE SRC_SOURCES "${SRC_PATH}/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_SOURCES})

add_executable(${TEST_NAME} "${TEST_PATH}/test.cpp" "${SRC_PATH}/Game.cpp")

set_target_properties(${PROJECT_NAME} 
	PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

# libs

find_package(GTest CONFIG REQUIRED)

target_include_directories(${TEST_NAME} PRIVATE ${GTEST_INCLUDE_DIRS} ${SRC_PATH})

target_link_libraries(${TEST_NAME} PRIVATE ${GTEST_BOOTH_LIBRARIES}  GTest::gtest GTest::gtest_main)

if (MSVC)

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")

	add_compile_options("/std:c++latest")
	
	target_compile_options(${PROJECT_NAME} PRIVATE
		/W4
	)

	target_compile_options(${TEST_NAME} PRIVATE
		/W4
	)
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)

	target_compile_options(${TEST_NAME} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)
endif (MSVC)


enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})