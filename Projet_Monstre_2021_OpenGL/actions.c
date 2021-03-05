#include "actions.h"
#include <stdio.h>
#include <GL/glut.h>

// PARAMETRES GENERAUX
extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat x;
extern GLfloat y;
extern GLfloat z;
extern GLuint blend;
extern GLuint light;

// CAMERA
extern GLuint camera;

// DEPLACEMENTS DU MONSTRE
extern GLfloat mouvement_monstre_x;
extern GLfloat mouvement_monstre_y;
extern GLfloat mouvement_monstre_z;

// PARAMETRES OEIL


// PARAMETRES BRAS
extern GLfloat angle_bras;
extern GLfloat angle_bras_2;
int bras_leve = 0;

// PARAMETRES PATTES
extern GLfloat angle_pattes;
extern GLfloat angle_pattes_y;
int sommet = 0;
int avancer = 0;

// PARAMETRES TETE
extern GLfloat angle_tete;
int right_end = 0;


void touche_special(int touche, int t, int u) 
{
	switch (touche) {    
	case GLUT_KEY_PAGE_UP:
		z++;
		break;
	case GLUT_KEY_PAGE_DOWN:
		z--;
		break;
	case GLUT_KEY_UP:
		if (camera == 1) y--;
    else xrot += 10;
		break;
	case GLUT_KEY_DOWN:
		if (camera == 1) y++;
    else xrot -= 10;
		break;
	case GLUT_KEY_LEFT:
		if (camera == 1) x++;
    else yrot -= 10;
		break;
	case GLUT_KEY_RIGHT:
		if (camera == 1) x--;
    else yrot += 10;
		break;
    }	
}


void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

  switch (key) {    
    case ESCAPE: 
      exit(1);                   	
      break; 

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;
      
    case TOUCHE_MIN_A: // AVANCER 
      
      // ROTATION DES PATTES
      if (sommet) {
        if (angle_pattes_y <= 5.0f) angle_pattes_y += 0.2f;
        else {
          if (angle_pattes > 0) angle_pattes -= 0.1f;
          else {
            avancer = 1;
            sommet = 0;
          }
        }
      } else {
        if (avancer) {
          if (angle_pattes_y > 0) {
            angle_pattes_y -= 0.2f;
            mouvement_monstre_z += 0.025f;
          } else {
            avancer = 0;
          }
        } else {
          if (angle_pattes <= 10.0f) angle_pattes += 0.1f;
          else sommet = 1;
        }
      }

      // ROTATION DE LA TETE
      if (right_end) {
        if (angle_tete > -15.0f) angle_tete -= 0.5f;
        else right_end = 0;
      } else {
        if (angle_tete <= 15.0f) angle_tete += 0.5f;
        else right_end = 1;
      }

      break;
      
    case TOUCHE_MAJ_A: // RECULER
      if (angle_bras <= 20) angle_bras += 0.3f;
    

      break;

    case TOUCHE_MAJ_Z: // LEVER BRAS
      if (angle_bras <= 20) angle_bras += 0.3f;
      else {
        bras_leve = 1;
      }

      break;

    case TOUCHE_MIN_Z: // RECULER
      if (angle_bras > 7) angle_bras -= 0.2f;
      else bras_leve = 0;

      break;

    case CAMERA:
        camera = (camera == 1) ? 0 : 1;
      break;
    }	
}

