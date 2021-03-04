#ifndef MONSTRE_H
#define MONSTRE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


GLvoid pieds(GLfloat angle, GLfloat largeur, GLfloat hauteur);
GLvoid corps(GLfloat largeur, GLfloat longueur, GLfloat hauteur);
GLvoid patte(GLfloat largeur, GLfloat longueur, GLfloat hauteur);
GLvoid oeil();
GLvoid oreilles();

#endif // MONSTRE_H
