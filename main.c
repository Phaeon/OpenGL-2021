// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "monstre.h"
#include <GL/gl.h>

GLuint camera = 1;

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;
GLfloat x = 0.0f;
GLfloat y = 0.0f;  
GLfloat z = -15.0f;

GLvoid Modelisation()
{
  VM_init();

  glPushMatrix();
  {
    glRotatef(75, 0, -1, 0);

  glPushMatrix();
  {
    glRotatef(300, 0, 1, 0);
    pieds(0, 0, 0);
  }
  glPopMatrix();

  glPushMatrix();
  {
    glRotatef(210, 0, 1, 0);
    pieds(0, 0, 0);
  }
  glPopMatrix();

  glPushMatrix();
  {
    glRotatef(160, 0, 1, 0);
    pieds(0, 0, 0);
  }
  glPopMatrix();

    glPushMatrix();
    {
      glRotatef(-10, 0, 1, 0);
      pieds(0, 0, 0);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(120, 0, 1, 0);
      pieds(0, 0, 0);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(30, 0, 1, 0);
      pieds(0, 0, 0);
    }
    glPopMatrix();

    glPushMatrix();
    {

      for (size_t i = 0; i < 5; i++)
      {
        glRotatef(55, 0, 1, 0);
        glPushMatrix();
        {
          glTranslatef(7.5, 0, 0);
          glRotatef(180, 0, 1, 0);
          patte(0, 0, 0);
        }
        glPopMatrix();
      }

    }
    glPopMatrix();

  }
  glPopMatrix();

  glPushMatrix();
  {
    corps(0, 0, 0);
  }
  glPopMatrix();
 
  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
