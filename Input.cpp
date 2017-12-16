#include "stdafx.h"
#include "Input.h"

using namespace om;


Input::Input()
{
	x = 0;
	y = 0;
	scale = -1;
	mouseX = 0;
	mouseY = 0;
	mouseClicked = false;
}

void Input::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		y += 0.001;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		y -= 0.001;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		x += 0.001;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		x -= 0.001;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		scale -= 0.001;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		scale += 0.001;


}