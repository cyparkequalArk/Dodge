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

namespace unit_test {
	class CMockPlane1 : public CPlane {
	public:
		CMockPlane1(sf::Vector2f const& position) :
			CPlane(position) {}
	public: //utility
		sf::Vector2f& getPosition() {
			return _position;
		}
		sf::Vector2f& getSpeed() {
			return _speed;
		}
	};
	SCENARIO("비행기는 사용자 입력에 따라 움직여야 한다", "CPlane") {
		GIVEN("화면상의 30, 30 위치에 비행기 객체가 만들어져 있다.") {
			CMockPlane1 plane(sf::Vector2f(30, 30));
			THEN("비행기의 위치를 확인시 30, 30 이어야 한다") {
				sf::Vector2f pos = plane.getPosition();
				REQUIRE(pos.x == 30.f);
				REQUIRE(pos.y == 30.f);
			}
			THEN("비행기의 움직이는 속도는 0보다 높아야 한다") {
				sf::Vector2f spd = plane.getSpeed();
				REQUIRE(spd.x > 0.f);
				REQUIRE(spd.y > 0.f);
			}
			WHEN("사용자가 <- 방향키를 눌렀다면") {
				sf::Vector2f pos = plane.getPosition();
				//plane.move(UserInput::Left);
				THEN("비행기는 30, 30 위치보다 왼쪽으로 이동해 있어야 한다") {
					sf::Vector2f position = plane.getPosition();
					CHECK(position.x < pos.x);
					CHECK(position.y == pos.y);
				}
			}
		}
	}
}
#endif
