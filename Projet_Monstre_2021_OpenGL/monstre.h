#ifndef MONSTRE_H
#define MONSTRE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


GLvoid pieds(GLfloat angle, GLfloat angle_2);
GLvoid corps(GLfloat largeur, GLfloat longueur, GLfloat hauteur);
GLvoid bras(GLfloat angle, int bras);
GLvoid oeil();
GLvoid oreilles();

#endif // MONSTRE_H
