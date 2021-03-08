// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "monstre.h"
#include <GL/gl.h>

// CAMERA
GLuint camera = 1;
GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;
GLfloat x = 0.0f;
GLfloat y = -3.0f;  
GLfloat z = -20.0f;

// ANGLES PATTES
GLfloat angle_pattes_AD = 0.0f;
GLfloat angle_pattes_AD_y = 0.0f;
GLfloat angle_pattes_AG = 0.0f;
GLfloat angle_pattes_AG_y = 0.0f;
GLfloat angle_pattes_CD = 0.0f;
GLfloat angle_pattes_CD_y = 0.0f;
GLfloat angle_pattes_CG = 0.0f;
GLfloat angle_pattes_CG_y = 0.0f;
GLfloat angle_pattes_ARD = 0.0f;
GLfloat angle_pattes_ARD_y = 0.0f;
GLfloat angle_pattes_ARG = 0.0f;
GLfloat angle_pattes_ARG_y = 0.0f;

// TETE
GLfloat angle_tete = 0.0f;

// MONSTRE
GLfloat mouvement_monstre_x = 0.0f;
GLfloat mouvement_monstre_y = 0.0f;
GLfloat mouvement_monstre_z = 0.0f;

// BRAS
GLfloat angle_bras_1 = 0.0f;
GLfloat angle_bras_1_2 = 0.0f;
GLfloat angle_bras_2 = 0.0f;
GLfloat angle_bras_2_2 = 0.0f;
GLfloat angle_bras_3 = 0.0f;
GLfloat angle_bras_3_2 = 0.0f;
GLfloat angle_bras_4 = 0.0f;
GLfloat angle_bras_4_2 = 0.0f;
GLfloat angle_bras_5 = 0.0f;
GLfloat angle_bras_5_2 = 0.0f;

extern int bras_leve_1;
extern int bras_leve_2;
extern int bras_leve_3;
extern int bras_leve_4;
extern int bras_leve_5;

// TEXTURE
extern GLuint texture[];

GLvoid Modelisation()
{
  VM_init();
  glColor3f(1, 0, 0);
  // CREATION DU MONSTRE
  glTranslatef(mouvement_monstre_x, mouvement_monstre_y, mouvement_monstre_z); // Déplacements

  glPushMatrix();
  {
    glRotatef(75, 0, -1, 0);

    glPushMatrix();
    {
      // PATTE ARRIERE DROIT
      glRotatef(300, 0, 1, 0);
      pieds(angle_pattes_ARD, angle_pattes_ARD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE ARRIERE GAUCHE
      glRotatef(210, 0, 1, 0);
      pieds(angle_pattes_ARG, -angle_pattes_ARG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE GAUCHE
      glRotatef(160, 0, 1, 0);
      pieds(angle_pattes_CG, -angle_pattes_CG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE DROITE
      glRotatef(-10, 0, 1, 0);
      pieds(angle_pattes_CD, angle_pattes_CD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT GAUCHE
      glRotatef(120, 0, 1, 0);
      pieds(angle_pattes_AG, -angle_pattes_AG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT DROITE (Vue de derrière)
      glRotatef(30, 0, 1, 0);
      pieds(angle_pattes_AD, angle_pattes_AD_y);
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
          if (i == 0) bras(angle_bras_1, bras_leve_1);
          else if (i == 1) bras(angle_bras_2, bras_leve_2);
          else if (i == 2) bras(angle_bras_3, bras_leve_3);
          else if (i == 3) bras(angle_bras_4, bras_leve_4);
          else if (i == 4) bras(angle_bras_5, bras_leve_5);
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
