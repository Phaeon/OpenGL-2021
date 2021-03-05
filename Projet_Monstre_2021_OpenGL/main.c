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
GLfloat y = -3.0f;  
GLfloat z = -20.0f;

// ANGLES MODIFIES
GLfloat angle_pattes = 0.0f;
GLfloat angle_pattes_y = 0.0f;

GLfloat angle_tete = 0.0f;

GLfloat mouvement_monstre_x = 0.0f;
GLfloat mouvement_monstre_y = 0.0f;
GLfloat mouvement_monstre_z = 0.0f;

GLfloat angle_bras = 0.0f;
GLfloat angle_bras_2 = 0.0f;

extern GLuint texture[];

GLvoid Modelisation()
{
  VM_init();
  glColor3f(1, 0, 0);
  // CREATION DU MONSTRE
  glTranslatef(mouvement_monstre_x, mouvement_monstre_y, mouvement_monstre_z); // Déplacements
  glBindTexture(GL_TEXTURE_2D, texture[0]);

    glTexCoord2f(0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);

    glTexCoord2f(0.0f, 1.0f);

  glPushMatrix();
  {
    glRotatef(75, 0, -1, 0);

    glPushMatrix();
    {
      glRotatef(300, 0, 1, 0);
      pieds(angle_pattes, angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(210, 0, 1, 0);
      pieds(angle_pattes, -angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(160, 0, 1, 0);
      pieds(angle_pattes, -angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(-10, 0, 1, 0);
      pieds(angle_pattes, angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(120, 0, 1, 0);
      pieds(angle_pattes, -angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      glRotatef(30, 0, 1, 0);
      pieds(angle_pattes, angle_pattes_y);
    }
    glPopMatrix();

    glPushMatrix();
    {

      for (size_t i = 0; i < 5; i++)
      {
        glRotatef(55, 0, 1, 0);
        glPushMatrix();
        {
          glTranslatef(2.7, 1.2, 0);
          bras(angle_bras, angle_bras_2);
        }
        glPopMatrix();
      }

    }
    glPopMatrix();

  }
  glPopMatrix();

  glPushMatrix();
  {
    corps(angle_tete, 0, 0);
  }
  glPopMatrix();


 
  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
