#include <iostream>
#include "plane.hpp"

#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#endif

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}