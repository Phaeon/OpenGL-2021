#include "VM_init.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 

extern GLfloat xrot;
extern GLfloat yrot;
extern GLfloat x;
extern GLfloat y;
extern GLfloat z;



void VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(x, y, z);
	
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}
