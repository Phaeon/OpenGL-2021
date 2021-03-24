#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int faces_cube[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 5, 4}, {1, 7, 6, 2}, {0, 4, 7, 1}, {3, 2, 6, 5}};
static int sommets[][3] = {{0, 3, 5}, {0, 2, 5}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {1, 3, 4}, {1, 2, 4}};

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