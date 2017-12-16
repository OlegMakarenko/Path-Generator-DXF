#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl\GLU.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include "Figure.h"
#include "Input.h"


void setLight()
{
	GLfloat light2_diffuse[] = { 0.4, 0.7, 0.2 };
	GLfloat light2_position[] = { 0.0, 0.0, 1.0, 1.0 };
	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.4);
}



int main(int argc, char* argv[])
{
	if (argc !=2) exit(1);

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	om::Input input;
	std::string filename;
	filename = argv[1];
	//filename = "2.dxf"; //debug

	om::Figure path;
	path.setColor(0.9, 0.9, 0.9);
	path.setWidth(2);
	if (!om::LoadFromFile::Path(filename, path)) exit(1);
	path.fitToViewport();

	sf::Clock clock;

	sf::Text text;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	text.setString("Controls: [up], [left], [down], [right], [x], [z], [MouseWheel]");
	text.setPosition(2, 10);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::White);

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode::VideoMode(600, 600, 32), "Path generator: 3D-view", sf::Style::Default, settings);
	
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearDepth(1.f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.1f, 0.1f, 0.1f, 0.f);
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);

	while (window.isOpen())
    {
		sf::Event event;
		float time = clock.getElapsedTime().asSeconds() * 100;

		while (window.pollEvent(event))
		{
			if (event.type== sf::Event::Resized)
				glViewport(0, 0, event.size.width, event.size.height);

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseWheelScrolled)
				input.scale += event.mouseWheelScroll.delta / 100;
		}
		input.update();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		path.translate(input.x / input.scale, input.y / input.scale, 0);
		path.setScale(input.scale, input.scale, input.scale);
		path.rotate(0, time, 0);

		path.draw();

		setLight();
		window.pushGLStates();
		window.draw(text);
		window.popGLStates();

		window.display();
    }
    return 0;
}



