#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <functional>
#include "model.h"

class Object {
public:
	Object(const std::string fileName);
	GLfloat local[16];	
	Model *objeto;
	GLfloat camHorizontalAngle;
	GLfloat camVerticalAngle;
	GLfloat moveSpeed;
	GLfloat objectRotate;

	void init();
	void draw();
	~Object() = default;
private:
};