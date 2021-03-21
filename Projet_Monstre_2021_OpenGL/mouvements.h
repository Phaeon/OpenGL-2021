#ifndef MOUVEMENTS_H
#define MOUVEMENTS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <unistd.h>

GLvoid rotation_pattes_avant();
GLvoid rotation_pattes_lat();
GLvoid rotation_pattes_arriere();

GLvoid avancer_monstre();
GLvoid tourner_a_gauche();
GLvoid tourner_a_droite();

GLvoid rotation_tete();

GLvoid lever_bras1();
GLvoid lever_bras2();
GLvoid lever_bras3();
GLvoid lever_bras4();
GLvoid lever_bras5();
GLvoid baisser_bras1();
GLvoid baisser_bras2();
GLvoid baisser_bras3();
GLvoid baisser_bras4();
GLvoid baisser_bras5();

GLvoid avancer_auto();
GLvoid mouvements_aleatoires();

#endif