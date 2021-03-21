#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int faces[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 5, 4}, {1, 7, 6, 2}, {0, 4, 7, 1}, {3, 2, 6, 5}};

// Structure d'un cube sans les normales
typedef struct {
	GLfloat sommets[8][3];
	int faces[6][4];
} s_cube;

s_cube * creer_cube (GLfloat Taille);
void afficher_cube(s_cube * cube);

#endif