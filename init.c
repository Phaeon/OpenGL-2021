#include "init.h"

/*
 * Gestion de la fenêtre
 */
 
int window;
 
GLuint blend = 1;
GLuint light = 1;

extern GLfloat x;
extern GLfloat y;
extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;


GLvoid Redimensionne(GLsizei Width, GLsizei Height) {
	glViewport(0, 0, Width, Height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, (GLdouble)Width/(GLdouble)Height, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}


int notre_init(int argc, char** argv, void (*Modelisation)()) {
glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	
	// Taille de la fenêtre lors de l'exécution du programme
	glutInitWindowSize(640, 480);
	// Fixe automatiquement la position de la fenêtre
	glutInitWindowPosition(0, 0);
	
	
	window = glutCreateWindow("Ma fenetre");
	
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	
	glutReshapeFunc(&Redimensionne);
	
	glutKeyboardFunc(&touche_pressee);
	glutSpecialFunc(&touche_special);
	
	// Couleur du fond d'écran
	glClearColor(0, 0, 0, 0);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	 
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat lum[] = {0.2, 0.2, 0.2, 1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lum);

	GLfloat LightDiff[4] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat LightSpec[4] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat LightPos[4] = {0, 0, 0, 1};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);

	glEnable(GL_LIGHT1);
	
	
	glutMainLoop();
	
	return 1;
}
