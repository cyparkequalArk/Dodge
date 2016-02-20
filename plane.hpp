#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include <iostream>
#include <sstream>
#include <deque>
#include <SFML/Graphics.hpp>

#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#endif
#include <hippomocks.h>

#if defined(_DEBUG)||!defined(NDEBUG)
#define virtual_unit virtual
#define protected	public
#define private		public
#endif

class CPlane {
public:
	CPlane(sf::Vector2f const& position) :
		_position(position), 
		_speed(0.3f, 0.3f) 
	{

	}
protected:
	sf::Vector2f _position;
	sf::Vector2f _speed;
};

#if defined(_DEBUG)||!defined(NDEBUG)
#undef virtual_unit
#undef protected
#undef private
#endif

#endif
