
#include "object.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "model.h"

	Object::Object(const std::string fileName) {
		objeto = new Model(fileName);
		carRotate = 90.f;

	}


	void Object::init() {
		GLfloat viewModelMatrix[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, viewModelMatrix);
		glLoadIdentity();

		glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0, 1.2, -5.f);

		glGetFloatv(GL_MODELVIEW_MATRIX, local);
		glLoadMatrixf(viewModelMatrix);
	}

	void Object::draw() {

		glPushMatrix();

		GLfloat carSpecular[] = { 1.f, 1.f, 1.f };
		GLfloat carShininess = 1.f;

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, carSpecular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, carShininess);
		glMaterialf(GL_FRONT_AND_BACK, GL_EMISSION, 1);

		glColorMaterial(GL_FRONT, GL_SHININESS);
		glEnable(GL_COLOR_MATERIAL);


		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		glStencilMask(0xFF);

		glTranslatef(10, 0, 0.0);
		glScalef(54.f, 50.f, 50.f);
		//glRotatef(this->carRotate, 0.f, 1.f, 0.f);
		objeto->renderTheModel();
		glPopMatrix();

	}
