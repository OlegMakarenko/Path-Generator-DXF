#include "stdafx.h"
#include "Figure.h"

using namespace om;

Figure::Figure()
{
	this->translation.x = 0;
	this->translation.y = 0;
	this->translation.z = 0;
	this->rotation.x = 0;
	this->rotation.y = 0;
	this->rotation.z = 0;
	this->color.x = 1.0f;
	this->color.y = 0.0f;
	this->color.z = 0.0f;
	this->scale.x = 100.0f;
	this->scale.y = 100.0f;
	this->scale.z = 100.0f;
	this->width = 2;
}

void Figure::setColor(float r, float g, float b)
{
	this->color.x = r;
	this->color.y = g;
	this->color.z = b;
}

void Figure::setWidth(int _width)
{
	this->width = _width;
}

void Figure::translate(float x, float y, float z)
{
	this->translation.x = x;
	this->translation.y = y;
	this->translation.z = z;
}
void Figure::rotate(float x, float y, float z)
{
	this->rotation.x = x;
	this->rotation.y = y;
	this->rotation.z = z;
}

void Figure::setScale(float x, float y, float z)
{
	this->scale.x = x;
	this->scale.y = y;
	this->scale.z = z;
}


void Figure::addVertex(Vector3F<float> _vertex)
{
	vertex.push_back(_vertex);
}

void Figure::draw()
{
	glScalef(scale.x, scale.y, scale.z);

	glTranslatef(translation.x, translation.y, translation.z);

	glRotatef(rotation.x, 1.0, 0.0, 0.0);
	glRotatef(rotation.y, 0.0, 1.0, 0.0);
	glRotatef(rotation.z, 0.0, 0.0, 1.0);

	

	glLineWidth(width);
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_LINE_STRIP);
	//glBegin(GL_POLYGON);
	for (int i = 0; i < vertex.size(); i++)
		glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);
	glVertex3f(vertex[0].x, vertex[0].y, vertex[0].z);
	glEnd();
	
	

	glRotatef(-rotation.x, 1.0, 0.0, 0.0);
	glRotatef(-rotation.y, 0.0, 1.0, 0.0);
	glRotatef(-rotation.z, 0.0, 0.0, 1.0);

	glTranslatef(-translation.x, -translation.y, -translation.z);

	glScalef(-scale.x, -scale.y, -scale.z);
}

void Figure::test()
{
	Vector3F<float> v;
	v(0, 0, 0);
	vertex.push_back(v);
	v(1, 0, 0);
	vertex.push_back(v);
	v(1, 1, 0);
	vertex.push_back(v);
	v(0, 1, 0);
	vertex.push_back(v);

}

float Figure::LargestVertex()
{
	float result = 0;
	for (int i = 0; i < vertex.size(); i++)
	{
		vertex[i].x > result ? result = vertex[i].x : 0;
		vertex[i].y > result ? result = vertex[i].y : 0;
		vertex[i].z > result ? result = vertex[i].z : 0;
	}
	return result;
}


Vector3F<float> Figure::LargestVertex3F()
{
	Vector3F<float> result;
	result (0,0,0);

	for (int i = 0; i < vertex.size(); i++)
	{
		vertex[i].x > result.x ? result.x = vertex[i].x : 0;
		vertex[i].y > result.y ? result.y = vertex[i].y : 0;
		vertex[i].z > result.z ? result.z = vertex[i].z : 0;
	}
	return result;
}
	
void Figure::fitToViewport()
{
	float scale = LargestVertex();
	Vector3F<float> size;
	size = (LargestVertex3F() / scale) / 2;

	for (int i = 0; i < vertex.size(); i++)
	{
		vertex[i].x = (vertex[i].x / scale) - size.x;
		vertex[i].y = (vertex[i].y / scale) - size.y;
	}
}