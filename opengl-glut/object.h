#pragma once
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <functional>
#include "model.h"

class Object {
public:
	Object(const std::string fileName);
	GLfloat local[16];	//local coordinate system transformation matrix
	Model *objeto;
	GLfloat camHorizontalAngle;
	GLfloat camVerticalAngle;
	GLfloat moveSpeed;
	GLfloat carRotate;

	//Functions
	void init();
	void draw();
	~Object() = default;
private:
	//update constant animation for tail wiggle and legs movement
};