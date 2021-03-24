#ifndef SOL_H
#define SOL_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct {
    GLfloat sommets[4][3];
} s_sol;

s_sol * creer_sol();
void afficher_sol(s_sol * sol);


#endif