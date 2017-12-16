#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

namespace om
{
	struct Input
	{
	public:
		Input();
		float x;
		float y;
		float scale;
		void update();
		bool mouseClicked;
		int mouseX;
		int mouseY;
	};
	
}
