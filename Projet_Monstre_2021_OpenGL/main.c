// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "monstre.h"
#include "obstacle.h"
#include "mouvements.h"
#include "animation.h"
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
GLfloat rotation_monstre_x = 0.0f;
GLfloat rotation_monstre_y = 0.0f;
GLfloat rotation_monstre_z = 0.0f;

// BRAS
GLfloat angle_bras_1 = 0.0f;
GLfloat angle_bras_2 = 0.0f;
GLfloat angle_bras_3 = 0.0f;
GLfloat angle_bras_4 = 0.0f;
GLfloat angle_bras_5 = 0.0f;

extern int bras_leve_1;
extern int bras_leve_2;
extern int bras_leve_3;
extern int bras_leve_4;
extern int bras_leve_5;

// BORDURES
GLfloat rayon_univers = 30.0f;

// MOUVEMENT
int automatique = 0;
int tourner = 0;
int culling = 0;

GLvoid sol()
{
    glPushMatrix();
    {
      glColor3f(0, 255, 255);
      glTranslatef(0.0, -0.1, 0.0);
      glScalef(rayon_univers, 0.1, rayon_univers);
      glutSolidCube(1);
    }
    glPopMatrix();
}

GLvoid monstre() {

  glPushMatrix();
    creerLampadaire(5, 5);
  glPopMatrix();
  glColor3f(1, 0, 0);
  // CREATION DU MONSTRE
  glPushMatrix();
  {
    glTranslatef(mouvement_monstre_x, mouvement_monstre_y, mouvement_monstre_z); // Déplacements
    
    glRotatef(75, 0, -1, 0);

    glPushMatrix();
    {
      // PATTE ARRIERE DROIT
        glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(300, 0, 1, 0);
      pieds(angle_pattes_ARD, angle_pattes_ARD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE ARRIERE GAUCHE
        glRotatef(rotation_monstre_y, 0, 1, 0);

      glRotatef(210, 0, 1, 0);
      pieds(angle_pattes_ARG, -angle_pattes_ARG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE GAUCHE
        glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(160, 0, 1, 0);
      pieds(angle_pattes_CG, -angle_pattes_CG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE DROITE
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(-10, 0, 1, 0);
      pieds(angle_pattes_CD, angle_pattes_CD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT GAUCHE
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(120, 0, 1, 0);
      pieds(angle_pattes_AG, -angle_pattes_AG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT DROITE (Vue de derrière)
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(30, 0, 1, 0);
      pieds(angle_pattes_AD, angle_pattes_AD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
    glRotatef(rotation_monstre_y, 0, 1, 0);
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
    glTranslatef(mouvement_monstre_x, mouvement_monstre_y, mouvement_monstre_z); // Déplacements
    corps(angle_tete, 0, 0);
  }
  glPopMatrix();
}



GLvoid Modelisation()
{
  VM_init();

  sol();

  if (automatique) avancer_auto();

  glPushMatrix();
  {
    glRotatef(30, 0, -1, 0);
    glTranslatef(-6.0f, 1.35f, 10.0f);
    for (size_t i = 0; i < 2; i++)
    {
      glTranslatef(1.5f, 0.0, 0.0f);
      afficher_cube(creer_cube(1));
    }
    
  }
  glPopMatrix();

  glPushMatrix();
  {
    glRotatef(30, 0, -1, 0);
    glTranslatef(-6.0f, 0.35f, 10.0f);
    for (size_t i = 0; i < 4; i++)
    {
      glTranslatef(1.2f, 0.0, 0.0f);
      afficher_cube(creer_cube(1));
    }
    
  }
  glPopMatrix();

  glPushMatrix();
  { 
    monstre();
  }
  glPopMatrix();


  //showFrame();
 
  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
