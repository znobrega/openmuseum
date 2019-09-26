#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

#include "SOIL.h"

#include <vector>
#include "object.h"
#include "object.cpp"
#include "model.h"
#include "model.cpp"

#define GORILLA "assets/gorilla.obj"
#define SKELETON "assets/skeleton.obj"
#define REX "assets/skeleton.obj"

std::vector<Object*> objects;
Object *myGorilla = new Object(GORILLA);
Object *mySkeleton = new Object(SKELETON);
Object *myRex = new Object(REX);
Object *mySkeletonGreen = new Object(SKELETON);
Object *myGorillaRotated = new Object(GORILLA);


unsigned char* img;
int img_width; 
int img_height;
int img_channels;

unsigned char* vanGogh_img;
int vanGogh_img_width; 
int vanGogh_img_height;
int vanGogh_img_channels;

GLuint ground_tex;
GLuint background_tex;
GLuint monalisa_tex;
GLuint vanGogh_tex;

GLfloat rotate = 90.f;

GLfloat aspect = 1.0f;
GLfloat window_width = 512;
GLfloat window_height = 512;

GLfloat rotate_x = 0.0f;
GLfloat rotate_y = 0.0f;

GLuint Buttons[3] = {0,0,0};
GLint LastX = 0;
GLint LastY = 0;

GLfloat dx = 0.0f;
GLfloat dz = 0.0f;

GLfloat moveSkeleton = 0.0f;
bool rightOrLeft = true;

GLfloat tex_ss = 1.0f;
GLfloat tex_st = 1.0f;

GLuint render_object = 0;

//---------------------------------------------------------------
void free_mem(void)
{
	std::clog << "Exiting...\n";
}

void gorilla() {
	glPushMatrix();
		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D,  background_tex);
		glColor3f(0.0f, 1.0f, 1.0f);
		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		glStencilMask(0xFF);

		glRotatef(275.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.f, 0.f, 0.f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glScalef(1.f, 1.f, 1.f);
		objects[0]->objeto->renderTheModel();
	glPopMatrix();
}

void skeleton() {
	glPushMatrix();

		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, monalisa_tex );
			glColor3f(1.0f, 1.0f, 1.0f);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			
			if (rightOrLeft == true) {
				moveSkeleton -= 0.01f;
			} else {
				moveSkeleton += 0.01f;
			}
			if (moveSkeleton > 5){
				rightOrLeft = true;
				printf("Move skelt");
			}

			if (moveSkeleton < 0) {
				rightOrLeft = false;
			}

			glTranslatef(moveSkeleton, 1.f, -1.f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(1.f, 1.f, -1.f);
			objects[1]->objeto->renderTheModel();
	glPopMatrix();
}

void rex() {
	glPushMatrix();
		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, monalisa_tex );

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, monalisa_tex);
			glColor3f(1.0f, 1.0f, 1.0f);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			
			if (rightOrLeft == true) {
				moveSkeleton -= 0.01f;
			} else {
				moveSkeleton += 0.01f;
			}
			if (moveSkeleton > 5){
				rightOrLeft = true;
				printf("Move skelt");
			}

			if (moveSkeleton < 0) {
				rightOrLeft = false;
			}

			glTranslatef(moveSkeleton, 0.f, 4.f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(4.f, 4.f, 4.f);
			objects[2]->objeto->renderTheModel();
		glPopMatrix();	
}

void skeletonGreen() {
	glPushMatrix();

		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, background_tex );
			glColor3f(1.0f, 1.0f, 1.0f);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			
			if (rightOrLeft == true) {
				moveSkeleton -= 0.01f;
			} else {
				moveSkeleton += 0.01f;
			}
			if (moveSkeleton > 5){
				rightOrLeft = true;
				printf("Move skelt");
			}

			if (moveSkeleton < 0) {
				rightOrLeft = false;
			}

			glTranslatef(moveSkeleton, 1.f, 2.f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(1.f, 1.f, 1.f);
			objects[3]->objeto->renderTheModel();
	glPopMatrix();
}



void gorillaRotated() {
	glPushMatrix();
		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, background_tex);
		glColor3f(0.0f, 1.0f, 1.0f);
		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		glStencilMask(0xFF);

		glRotatef(275.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(1.f, 0.f, 0.f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glScalef(1.f, 1.f, 1.f);
		objects[4]->objeto->renderTheModel();
	glPopMatrix();
}

void monalisa(){
	glPushMatrix();
			
		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, background_tex );
			glColor3f(1.0f, 1.0f, 1.0f);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(-1.0f, -1.0f, -1.0f);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(-1.0f, -1.0f,  1.0f);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(-1.0f, 1.0f,  1.0f);

					glTexCoord2d(0.0,1.0);
					glVertex3f(-1.0f, 1.0f, -1.0f);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void vanGogh(){
	glPushMatrix();
		glEnable( GL_TEXTURE_2D );
		glEnable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, vanGogh_tex);
			glColor3f(1.0f, 1.0f, 1.0f);
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(-5.0f, -5.0f, -5.0f);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(-5.0f, -5.0f,  5.0f);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(-5.0f, 5.0f,  5.0f);

					glTexCoord2d(0.0,1.0);
					glVertex3f(-5.0f, 5.0f, -5.0f);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void initModels() {
	if (!myGorilla->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	if (!mySkeleton->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	if (!myRex->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	if (!mySkeletonGreen->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	if (!myGorillaRotated->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	objects.push_back(myGorilla);
	objects.push_back(mySkeleton);
	objects.push_back(myRex);
	objects.push_back(mySkeletonGreen);
	objects.push_back(myGorillaRotated);

}

void display(void) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, window_width, window_height);

	glColor3f(1.0, 1.0, 1.0); 

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, aspect, 0.01f, 10.0f);

	// scales texture coordinates
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();	
	glScalef(tex_ss, tex_st, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(	0.0f+dx, 0.0f, 1.0f+dz, 
				0.0f+dx, 0.0f, 0.0f+dz, 
				0.0f, 1.0f, 0.0f);

	glRotatef(rotate_x, 1, 0, 0);
	glRotatef(rotate_y, 0, 1, 0);

	//rotate += 0.1f;

	skeletonGreen();
	skeleton();
	rex();
	gorilla();
	monalisa();
	gorillaRotated();
	vanGogh();


	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void loadVanGogh() {
	glPushMatrix();
		vanGogh_img = SOIL_load_image(
				"assets/van_gogh.jpg",
				&vanGogh_img_width,
				&vanGogh_img_height,
				&vanGogh_img_channels,
				SOIL_LOAD_AUTO
		);

		glGenTextures( 1, &vanGogh_tex );
		glBindTexture( GL_TEXTURE_2D, vanGogh_tex );
		gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, img_width, img_height, GL_RGBA, GL_UNSIGNED_BYTE, img);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glPopMatrix();

}

void reshape(int w, int h) {
	window_width = w;
	window_height = h;

	if (window_height == 0)
		window_height = 1;

	aspect = 1.0f * window_width / window_height;

	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, aspect, 0.01f, 10.0f);
}

void mouse(int b, int s, int x, int y) {
	LastX = x;
	LastY = y;

	switch (b)
	{
	case GLUT_LEFT_BUTTON:
		Buttons[0] = ((GLUT_DOWN == s) ? 1 : 0);
		break;

	case GLUT_MIDDLE_BUTTON:
		Buttons[1] = ((GLUT_DOWN == s) ? 1 : 0);
		break;

	case GLUT_RIGHT_BUTTON:
		Buttons[2] = ((GLUT_DOWN == s) ? 1 : 0);
		break;

	default:
		break;
	}
}	

void motion(int x, int y) {
	int diffx = x - LastX;
	int diffy = y - LastY;

	LastX = x;
	LastY = y;

	if (Buttons[0]==1)
	{
		rotate_y += (float) 0.5f * diffx;
		rotate_x += (float) 0.5f * diffy;
	}				
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'D':
		case 'd':
			dx += 0.1f;
			break;
		case 'a':
		case 'A':
			dx -= 0.1f;
			break;
		case 'w':
		case 'W':
			dz -= 0.1f;
			break;
		case 's':
		case 'S':
			dz += 0.1f;
			break;
	}
}

int main(int argc, char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("openMUSEUM");

	glEnable(GL_DEPTH_TEST);
		
	glEnable(GL_LIGHTING);
	
	GLfloat light_ambient[]  = {   0.3f,   0.3f,   0.3f, 1.0f};
	GLfloat light_diffuse[]  = {   1.0f,   1.0f,   1.0f, 1.0f};
	GLfloat light_specular[] = {   1.0f,   1.0f,   1.0f, 1.0f};
	GLfloat light_position[] = {-100.0f, 100.0f, 100.0f, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT0);

	GLfloat material_ambient[]   = { 0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat material_diffuse[]   = { 1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat material_specular[]  = { 1.0f, 1.0f, 1.0f, 1.0f};

	glMaterialfv(GL_FRONT, GL_AMBIENT,  material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,  material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0f); 
	
	glShadeModel(GL_SMOOTH);

	initModels();


	background_tex = SOIL_load_OGL_texture(
        "assets/museum.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
	);

	ground_tex = SOIL_load_OGL_texture(
        "assets/ground.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
	);

	vanGogh_tex = SOIL_load_OGL_texture(
        "assets/van_gogh.jpeg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
	);

	img = SOIL_load_image(
			"assets/white.png",
			&img_width,
			&img_height,
			&img_channels,
			SOIL_LOAD_AUTO
	);


	glGenTextures( 1, &monalisa_tex );
	glBindTexture( GL_TEXTURE_2D, monalisa_tex );
	gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, img_width, img_height, GL_RGBA, GL_UNSIGNED_BYTE, img);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);

	glutDisplayFunc(display);	
	//glutReshapeFunc(reshape);	
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	atexit(free_mem);
	
	glutMainLoop();

	return 0;
}


