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

namespace unit_test {
	SCENARIO("������ ����� �Է¿� ���� �������� �Ѵ�", "CPlane") {
		GIVEN("ȭ����� 30, 30 ��ġ�� ����� ��ü�� ������� �ִ�.") {
			CPlane plane(sf::Vector2f(30, 30));
			THEN("������� ��ġ�� Ȯ�ν� 30, 30 �̾�� �Ѵ�") {
				sf::Vector2f pos = plane._position;
				REQUIRE(pos.x == 30.f);
				REQUIRE(pos.y == 30.f);
			}
			THEN("������� �����̴� �ӵ��� 0���� ���ƾ� �Ѵ�") {
				sf::Vector2f spd = plane._speed;
				REQUIRE(spd.x > 0.f);
				REQUIRE(spd.y > 0.f);
			}
			WHEN("����ڰ� <- ����Ű�� �����ٸ�") {
				sf::Vector2f pos = plane._position;
				//plane.move(UserInput::Left);
				THEN("������ 30, 30 ��ġ���� �������� �̵��� �־�� �Ѵ�") {
					sf::Vector2f position = plane._position;
					CHECK(position.x < pos.x);
					CHECK(position.y == pos.y);
				}
			}
		}
	}
}
