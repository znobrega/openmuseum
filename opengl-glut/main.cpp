#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "SOIL.h"
#include <vector>
#include "object.h"
#include "object.cpp"
#include "model.h"
#include "model.cpp"


#define GORILLA "Objects/gorilla.obj"
#define SKELETON "Objects/skeleton.obj"

GLfloat angle, fAspect, rotate;

float positionFactor1 =   0.0;
float positionFactor2 =  100.0;
float positionFactor3 = 4.0;

GLuint ground_tex;

GLuint background_tex;

std::vector<Object*> objects;
Object *myGorilla = new Object(GORILLA);
Object *mySkeleton = new Object(SKELETON);


void ground(){
	glPushMatrix();

	GLfloat orange[] = {0.0, 0.45, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, orange);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange);

	for(unsigned short int i = 0; i < 5; i++){
		for(unsigned short int j = 0; j < 5; j++){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ground_tex);

			glBegin(GL_QUADS);
					glTexCoord2d(1.0,0.0); 
					glVertex3f(positionFactor1 - i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(positionFactor1 + i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(positionFactor1 + i*10, -0.2f, -j*10);

					glTexCoord2d(0.0,1.0);
					glVertex3f(positionFactor1 - i*10, -0.2f, -j*10);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ground_tex);

			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(positionFactor2 - i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(positionFactor2 + i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(positionFactor2 + i*10, -0.2f, -j*10);

					glTexCoord2d(0.0,1.0);
					glVertex3f(positionFactor2 - i*10, -0.2f, -j*10);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ground_tex);

			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(positionFactor3 - i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(positionFactor3 + i*10, -0.2f,  j*10);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(positionFactor3 + i*10, -0.2f, -j*10);

					glTexCoord2d(0.0,1.0);
					glVertex3f(positionFactor3 - i*10, -0.2f, -j*10);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	}
	glPopMatrix();
}

void cachorro() {

	glPushMatrix();
	GLfloat color[4] = { 0.92f, 0.814f, 0.382f, 1.0f };
	glColor4fv(color);

	GLfloat dog_specular[] = { 0.1f, 0.1f, 0.1f },
			dog_shininess = 0.1f;

	glMaterialfv(GL_FRONT, GL_SPECULAR, dog_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, dog_shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

	//torso
	glPushMatrix();
	glScalef(2.0f * 0.3f, 2.0f * 0.3f, 4.0f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//legs
	glPushMatrix();
	glTranslated(-1 * 0.3, -2.5 * 0.3, -2 * 0.3);
	glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.3f, -2.5f * 0.3f, -0.6);
	glScalef(0.5f * 0.3f, 0.6f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.3f, -2.5f * 0.3f, 2.0 * 0.3f);
	glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.3f, -2.5f * 0.3f, 0.6);
	glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslated(0.0f, 0.0f, -3.8f * 0.3f);
	glScalef(0.5f * 0.3f, 0.5f * 0.3f, 1.8f * 0.3f);

	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//head rotation
	glPushMatrix();

	//head
	glPushMatrix();
	glTranslated(0.0f, 2.5f * 0.3f, 3.0f * 0.3f);
	glScalef(1.5f * 0.3f, 1.55f * 0.3f, 1.6f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//nose
	glPushMatrix();
	glTranslated(0.0f, 2.2f * 0.3f, 4.2f * 0.3f);
	glScalef(0.8f * 0.3f, 0.5f * 0.3f, 1.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//ears
	glPushMatrix();
	glTranslated(-0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
	glScalef(0.5f * 0.3f, 0.3f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
	glScalef(0.5f * 0.3f, 1.0f * 0.3f, 0.5f * 0.3f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//eyes
	GLfloat eyes_specular[] = { 0.4f, 0.4f, 0.4f },
			eyes_shininess = 1.0f;
	GLfloat black[] = { 0,0,0,1};
	glColor4fv(black);
	glMaterialfv(GL_FRONT, GL_SPECULAR, eyes_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, eyes_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, black);

	glPushMatrix();
	glTranslated(0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
	glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5f * 0.3f, 3.0f * 0.3f, 4.4f  * 0.3f);
	glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void wall() {
	glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ground_tex);

			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(0, 0, 0);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(1, 1,  0);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(0, 1, 0);

					glTexCoord2d(0.0,1.0);
					glVertex3f(1, 0, 0);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);
}

void background(){
	glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, background_tex);

			glBegin(GL_QUADS);
					glTexCoord2d(0.0,0.0); 
					glVertex3f(-100.0f, -100.0f, -60.0f);

					glTexCoord2d(1.0,0.0); 
					glVertex3f(-100.0f, -50.0f,  60.0f);

					glTexCoord2d(1.0,1.0); 
					glVertex3f(-100.0f, 70.0f,  60.0f);

					glTexCoord2d(0.0,1.0);
					glVertex3f(-100.0f, 70.0f, -60.0f);			
					
			glEnd();
			glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void fourth() {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-50.0f, -10.5f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 50.5f, -20.5f, 0.0f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f( 50.0f,  30.5f, 0.0f);
    glEnd();
}

void initModels() {
	if (!myGorilla->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	if (!mySkeleton->objeto->importModel())
		std::cout << "Import model error!" << std::endl;

	objects.push_back(myGorilla);
	objects.push_back(mySkeleton);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{

	
	glClear(GL_COLOR_BUFFER_BIT);
	// Aki o angulo pode ser decrementado
	rotate = 10.15f;
	//glRotatef(rotate,1.0f,0.0,0.0);
	//fourth();


	// glPushMatrix();
	// 	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	// 	glStencilMask(0xFF);

	// 	glTranslatef(59.f, 0.f, 0.f);
	// 	glScalef(100.f, 100.f, 100.f);
	// 	glRotatef(rotate , 1.f, 0.f, 1.f);
	// 	objects[0]->objeto->renderTheModel();
	// glPopMatrix();

	// glPushMatrix();
	// 	glColor3f(0.0f, 1.0f, 1.0f);
	// 	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	// 	glStencilMask(0xFF);

	// 	glTranslatef(59.f, 0.f, 0.f);
	// 	glColor3f(0.0f, 0.0f, 1.0f);
	// 	glScalef(100.f, 100.f, 100.f);
	// 	objects[1]->objeto->renderTheModel();
	// glPopMatrix();

		glPushMatrix();
		glMultMatrixf(objects[0]->local);
		objects[0]->draw();
		glPopMatrix();


	//ground();
	//cachorro();
	//background();
	//carros[0].draw();
	//wall();
	glColor3f(0.0f, 0.0f, 1.0f);


	// Desenha o teapot com a cor corrente (wire-frame)
	glutSolidTeapot(30.0f);

	// Executa os comandos OpenGL
	glutSwapBuffers();
 }



// Inicializa parâmetros de rendering
void Inicializa (void)
{ 

	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
    angle=45;
	rotate = 50.15f;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.1,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			//if (angle >= 10)  angle -= 1;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			//if (angle <= 130)  angle += 1;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


// Programa Principal
int main(int argc, char **argv)
{
    std::clog << "Begin...\n";

    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(512,512);
	glutCreateWindow("Visualizacao 3D");

	//initializations();
	initModels();
	ground_tex = SOIL_load_OGL_texture(
        "assets/ground.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
	);

	background_tex = SOIL_load_OGL_texture(
        "assets/museum.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
	);

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}




