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
	SCENARIO("������ ����� �Է¿� ���� �������� �Ѵ�", "CPlane") {
		GIVEN("ȭ����� 30, 30 ��ġ�� ����� ��ü�� ������� �ִ�.") {
			CMockPlane1 plane(sf::Vector2f(30, 30));
			THEN("������� ��ġ�� Ȯ�ν� 30, 30 �̾�� �Ѵ�") {
				sf::Vector2f pos = plane.getPosition();
				REQUIRE(pos.x == 30.f);
				REQUIRE(pos.y == 30.f);
			}
			THEN("������� �����̴� �ӵ��� 0���� ���ƾ� �Ѵ�") {
				sf::Vector2f spd = plane.getSpeed();
				REQUIRE(spd.x > 0.f);
				REQUIRE(spd.y > 0.f);
			}
			WHEN("����ڰ� <- ����Ű�� �����ٸ�") {
				THEN("������ 30, 30 ��ġ���� �������� �̵��� �־�� �Ѵ�") {

				}
			}
		}
	}
}
#endif
