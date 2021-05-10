#include "init.h"
#include "axes.h"
#include "monstre.h"
#include "obstacle.h"
#include "sol.h"
#include "mouvements.h"
#include "normale.h"
#include "animation.h"

#include <GL/gl.h>

// CONTROLE DE LA CAMERA OU DU SUJET
GLfloat xrot_objet = 0.0;
GLfloat yrot_objet = 0.0;
GLfloat zrot_objet = 0.0;

GLfloat xrot_scene = 0.0;
GLfloat yrot_scene = 0.0;
GLfloat zrot_scene = 0.0;

GLfloat xrot_camera = 0.0;
GLfloat yrot_camera = 0.0;
GLfloat zrot_camera = 0.0;

GLuint camera = 1;
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
GLfloat mouvement_monstre_z = -10.0f;
GLfloat rotation_monstre_y = 0.0f;

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
GLfloat diametre_univers = 30.0f;

// BOOLÉENS
int automatique = 0;
int tourner = 0;
int culling = 0;
int anim = 0;

// TEXTURES
extern int texture[];

// OBJETS À STRUCTURE
s_cube2 * cube = NULL;
s_sol * s = NULL;

// GÉNÉRATION DU MONSTRE
GLvoid monstre() {

  glPushMatrix();
  {
    glTranslatef(mouvement_monstre_x, 0.0f, mouvement_monstre_z); // Déplacements
    
    glRotatef(75, 0, -1, 0);

    glPushMatrix();
    {
      // PATTE ARRIERE DROIT
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(300, 0, 1, 0);
      pieds(angle_pattes_ARD, angle_pattes_ARD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE ARRIERE GAUCHE
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(210, 0, 1, 0);
      pieds(angle_pattes_ARG, -angle_pattes_ARG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE GAUCHE
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(160, 0, 1, 0);
      pieds(angle_pattes_CG, -angle_pattes_CG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE LATERALE DROITE
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(-10, 0, 1, 0);
      pieds(angle_pattes_CD, angle_pattes_CD_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT GAUCHE
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(120, 0, 1, 0);
      pieds(angle_pattes_AG, -angle_pattes_AG_y);
    }
    glPopMatrix();

    glPushMatrix();
    {
      // PATTE AVANT DROITE (Vue de derrière)
      glColor3f(0.2, 0.2, 0.2);
      glRotatef(rotation_monstre_y, 0, 1, 0);
      glRotatef(30, 0, 1, 0);
      pieds(angle_pattes_AD, angle_pattes_AD_y);
    }
    glPopMatrix();

    // BRAS
    glPushMatrix();
    {
      glRotatef(rotation_monstre_y, 0, 1, 0);
      for (size_t i = 0; i < 5; i++)
      {
        
        glRotatef(55, 0, 1, 0);
        glPushMatrix();
        {
          glTranslatef(2.7, 1.2, 0);
          glColor3f(0.2, 0.2, 0.2);
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
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(mouvement_monstre_x, 0.0f, mouvement_monstre_z); // Déplacements
    corps(angle_tete);
  }
  glPopMatrix();
}

GLvoid Modelisation()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // ROTATION DE LA CAMÉRA
  glRotatef(xrot_camera,1.0f,0.0f,0.0f);
  glRotatef(yrot_camera,0.0f,1.0f,0.0f);
  glRotatef(zrot_camera,0.0f,0.0f,1.0f);

  // ZOOM CONTRÔLÉ
  glTranslatef(0.0,0.0, z);
  
  // ROTATION DE LA SCÈNE
  glRotatef(xrot_scene,1.0f,0.0f,0.0f);
  glRotatef(yrot_scene,0.0f,1.0f,0.0f);
  glRotatef(zrot_scene,0.0f,0.0f,1.0f);


  glPushMatrix();
  {
    // ROTATION DU SUJET
    glRotatef(xrot_objet,1.0f,0.0f,0.0f);
    glRotatef(yrot_objet,0.0f,1.0f,0.0f);
    glRotatef(zrot_objet,0.0f,0.0f,1.0f);

    // MOUVEMENTS AUTOMATIQUES EN APPUYANT SUR 'P'
    if (automatique) avancer_auto();

    // DEUX "LAMPADAIRES"
    glPushMatrix();
    {
      creerLampadaire(-10, -10);
    }
    glPopMatrix();
    glPushMatrix();
    {
      creerLampadaire(10, -10);
    }
    glPopMatrix();

    // CARTONS AU DEUXIÈME NIVEAU
    glPushMatrix();
    {
      glRotatef(30, 0, -1, 0);
      glTranslatef(-6.0f, 1.35f, 10.0f);
      for (size_t i = 0; i < 2; i++)
      {
        glColor3f(255, 255, 255);
        glTranslatef(1.5f, 0.0, 0.0f);
        afficher_cube2(cube);
      }
    
    }
    glPopMatrix();

    // CARTONS AU PREMIER NIVEAU
    glPushMatrix();
    {
      glRotatef(30, 0, -1, 0);
      glTranslatef(-6.0f, 0.35f, 10.0f);
      for (size_t i = 0; i < 4; i++)
      {
        glColor3f(255, 255, 255);
        glTranslatef(1.2f, 0.0, 0.0f);
        afficher_cube2(cube);
      }
    }
    glPopMatrix();

    // CRÉATION DU MONSTRE
    glPushMatrix();
    { 
      monstre();
    }
    glPopMatrix();

    // GÉNÉRATION DU SOL
    glPushMatrix();
    {
      glColor3f(255, 255, 255);
      glTranslatef(0.0, -0.1, 0.0); 
      afficher_sol(s);
    }
    glPopMatrix();

    // DÉCLENCHE L'ANIMATION EN APPUYANT SUR 'p'
    if (anim) showAnimation(-10, 1.0, -9.5);
  
  }
  glPopMatrix();
 
  //axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
