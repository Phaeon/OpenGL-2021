#include "init.h"
#include "ppm.h"
#include "string.h"
#include "dirent.h"

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

extern int culling;

GLuint texture[45];


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
	glClearColor(1, 1, 1, 0);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	//glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
	 
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat lum[] = {0.2, 0.2, 0.2, 1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lum);

	GLfloat LightDiff[4] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat LightSpec[4] = {0.13, 0.05, 0, 1.0f};
	GLfloat LightPos[4] = {0, 3, 20, 1};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	glEnable(GL_LIGHT0);

	// GESTION DES TEXTURES
	glGenTextures(1, texture);

	for (int i = 0; i < 10; i++)
	{

	char* fichier;
	if (i == 0) {
		fichier = "crate.ppm";
	} else {
		char s[255];
		sprintf(s, "anims/Guybrush0%i", i-1);
		fichier = s;
		strcat(fichier, ".ppm");
		printf("%s\n", s);
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
    	glTexImage2D(GL_TEXTURE_2D,
        	0,GL_RGB,
        	texture_corps->width,texture_corps->height,
        	0,GL_RGB,GL_UNSIGNED_BYTE, 
        	texture_corps->data);
	
		//texture_corps->data = rgb2rgba(texture_corps);
	}

	glEnable(GL_TEXTURE_2D);

	
	glutMainLoop();
	
	return 1;
}
