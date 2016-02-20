cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("Dodge")

enable_testing()

add_executable(Dodge main.cpp
	plane.hpp)

add_test(DodgeTest Dodge)


