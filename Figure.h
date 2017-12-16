#pragma once
#include "Vector3F.h"
#include <vector>
#include <SFML/OpenGL.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include<GL/glu.h> 

namespace om
{
	class Figure
	{
		std::vector<Vector3F<float>> vertex;
		Vector3F<float> translation;
		Vector3F<float> rotation;
		Vector3F<float> scale;
		Vector3F<float> color;
		int width;
		float LargestVertex();
		Vector3F<float> Figure::LargestVertex3F();
	public:
		void test();
		void setColor(float r, float g, float b);
		void setWidth(int _width);
		void translate(float x, float y, float z);
		void rotate(float x, float y, float z);
		void setScale(float x, float y, float z);
		void addVertex(Vector3F<float> _vertex);
		void fitToViewport();
		void draw();
		Figure();
	};

	class LoadFromFile
	{
	public:
		static bool Path(std::string &filename, Figure &path)
		{
			std::ifstream file(filename);
			Vector3F<float> vertex;
			std::string line;
			int counter = 0;

			std::cout << filename << std::endl;
			while (file.is_open())
			{
				getline(file, line); 
				std::cout << line << std::endl;
				if (line == "EOF")
					file.close();
				else if (line == "10")
				{
					getline(file, line);
					vertex.x = ::atof(line.c_str());
				}
				else if (line == "20")
				{
					getline(file, line);
					vertex.y = ::atof(line.c_str());;
				}
				else if (line == "30")
				{
					getline(file, line);;
					vertex.z = ::atof(line.c_str());
					path.addVertex(vertex);
					std::cout << vertex.x << ", " << vertex.y << ", " << vertex.z << std::endl;
				}
				counter++;
				if (file.eof()) return 0;
			}
			return 1;
		}
	};
}
