#include "init.h"
#include "ppm.h"
#include "string.h"
#include "obstacle.h"
#include "sol.h"
#include "lumiere.h"
 
int window;
 
GLuint blend = 0;
GLuint light = 0;

extern GLfloat z;

GLuint texture[45];

extern s_cube2 * cube;
extern s_sol * s;


GLvoid Redimensionne(GLsizei Width, GLsizei Height) {
	glViewport(0, 0, Width, Height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, (GLdouble)Width/(GLdouble)Height, 1.0f, 100.0f);
	
}


int notre_init(int argc, char** argv, void (*Modelisation)()) {
glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	
	// Taille de la fenêtre lors de l'exécution du programme
	glutInitWindowSize(1280, 960);
	// Fixe automatiquement la position de la fenêtre
	glutInitWindowPosition(0, 0);
	
	
	window = glutCreateWindow("Synthese d'image - CC 2021 - Jack Hogg");
	
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	
	glutReshapeFunc(&Redimensionne);
	
	glutKeyboardFunc(&touche_pressee);
	glutSpecialFunc(&touche_special);
	
	// Couleur du fond d'écran
	glClearColor(0.9, 0.9, 0.9, 0);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	 

	// GESTION DE LA LUMIÈRE
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	lumiere();

	// GESTION DES TEXTURES
	glGenTextures(45, texture);
	
	for (int i = 0; i < 45; i++)
	{

		char* fichier;
		if (i == 0) {
			fichier = "crate.ppm";
		} else if (i > 0 && i < 44) {
			char s[255];
			sprintf(s, "anims/Guybrush%.2i", i-1);
			fichier = s;
			strcat(fichier, ".ppm");
		} else {
			fichier = "granite.ppm";
		}

		// TEXTURE OBSTACLE
		TEXTURE_STRUCT * texture_corps = readPpm (fichier);
		glBindTexture(GL_TEXTURE_2D, texture[i]);
		glTexParameteri(
        	GL_TEXTURE_2D,
        	GL_TEXTURE_WRAP_S,
        	GL_MIRRORED_REPEAT
    	);
    	glTexParameteri(
        	GL_TEXTURE_2D,
        	GL_TEXTURE_WRAP_T,
        	GL_MIRRORED_REPEAT
    	);
    	glTexParameteri(
        	GL_TEXTURE_2D,
        	GL_TEXTURE_MAG_FILTER,
        	GL_LINEAR
    	);
    	glTexParameteri(
        	GL_TEXTURE_2D,
        	GL_TEXTURE_MIN_FILTER,
        	GL_LINEAR
    	);
		if (i > 0 && i < 44) {
			texture_corps->data = rgb2rgba(texture_corps);
			
			glTexImage2D(GL_TEXTURE_2D,
        	0,GL_RGBA,
        	texture_corps->width,texture_corps->height,
        	0,GL_RGBA,GL_UNSIGNED_BYTE, 
        	texture_corps->data);
		} else {
			glTexImage2D(GL_TEXTURE_2D,
        	0,GL_RGB,
        	texture_corps->width,texture_corps->height,
        	0,GL_RGB,GL_UNSIGNED_BYTE, 
        	texture_corps->data);
		}

	}


	cube = creer_cube2(1);
	s = creer_sol();
	
	glutMainLoop();
	
	return 1;
}
