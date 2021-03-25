#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Structure d'un cube sans les normales
typedef struct {
	GLfloat sommets[8][3];
	int faces[6][4];
	GLfloat couleurs[6][4];
} s_cube;

// Structure d'un cube avec les normales
typedef struct
{
	s_cube * cube1;
	GLfloat normales_faces[6][3];
} s_cube2;


s_cube * creer_cube (GLfloat Taille);
s_cube2 * creer_cube2(GLfloat Taille);
void afficher_cube2(s_cube2 * cube);

GLvoid creerLampadaire(GLfloat posX, GLfloat posZ);

#endif
