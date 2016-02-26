#include <iostream>
#include "plane.hpp"

#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#endif

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);;;;;
}

namespace unit_test {
	SCENARIO("비행기는 사용자 입력에 따라 움직여야 한다", "CPlane") {
		GIVEN("화면상의 30, 30 위치에 비행기 객체가 만들어져 있다.") {
			CPlane plane(sf::Vector2f(30, 30));
			THEN("비행기의 위치를 확인시 30, 30 이어야 한다") {
				sf::Vector2f pos = plane._position;
				REQUIRE(pos.x == 30.f);
				REQUIRE(pos.y == 30.f);
			}
			THEN("비행기의 움직이는 속도는 0보다 높아야 한다") {
				sf::Vector2f spd = plane._speed;
				REQUIRE(spd.x > 0.f);
				REQUIRE(spd.y > 0.f);
			}
			WHEN("사용자가 <- 방향키를 눌렀다면") {
				sf::Vector2f pos = plane._position;
				//plane.move(UserInput::Left);
				THEN("비행기는 30, 30 위치보다 왼쪽으로 이동해 있어야 한다") {
					sf::Vector2f position = plane._position;
					CHECK(position.x < pos.x);
					CHECK(position.y == pos.y);
				}
			}
		}
	}
}
