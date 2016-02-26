cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("Dodge")

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
		"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") 
	set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") 
	set(warnings "/W4 /WX /EHsc")
endif()

if (NOT_CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${warnings}"
		CACHE STRING "Flags used by the compiler during all build types." 
		FORCE)
	set(CMAKE_C_FLAGS "${warnings}"
		CACHE STRING "Flags used by the compiler during all build types." 
		FORCE)
endif(NOT_CONFIGURED_ONCE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/catch/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/hippomocks/HippoMocks)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/sfml2.3.2_w64/include)

add_executable(Dodge main.cpp
	plane.hpp)

add_test(DodgeTest Dodge)

set (CONFIGURED_ONCE TRUE CACHE INTERNAL
	"A flag showing that CMake has configured at least once.")
