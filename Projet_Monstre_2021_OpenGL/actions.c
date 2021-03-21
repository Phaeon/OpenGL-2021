#include "actions.h"
#include "mouvements.h"
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
extern GLfloat angle_bras_1;
extern GLfloat angle_bras_2;
extern GLfloat angle_bras_3;
extern GLfloat angle_bras_4;
extern GLfloat angle_bras_5;

int bras_leve_1 = 0;
int bras_leve_2 = 0;
int bras_leve_3 = 0;
int bras_leve_4 = 0;
int bras_leve_5 = 0;

// PARAMETRES PATTES
extern GLfloat angle_pattes_AD;
extern GLfloat angle_pattes_AD_y;
extern GLfloat angle_pattes_AG;
extern GLfloat angle_pattes_AG_y;
extern GLfloat angle_pattes_CD;
extern GLfloat angle_pattes_CD_y;
extern GLfloat angle_pattes_CG;
extern GLfloat angle_pattes_CG_y;
extern GLfloat angle_pattes_ARD;
extern GLfloat angle_pattes_ARD_y;
extern GLfloat angle_pattes_ARG;
extern GLfloat angle_pattes_ARG_y;

int sommet_ava = 0;
int sommet_lat = 0;
int sommet_arr = 0;

int avancer_ava = 0;
int avancer_lat = 0;
int avancer_arr = 0;

// PARAMETRES TETE
extern GLfloat angle_tete;
int right_end = 0;

extern int automatique;


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
      
    case TOUCHE_MIN_A: // ROTATION DES PATTES ET DE LA TETE
      rotation_pattes_avant();
      break;

    case TOUCHE_MIN_Z:
      rotation_pattes_lat();
      break;

    case TOUCHE_MIN_E:
      rotation_pattes_arriere();
      break;

    case TOUCHE_MIN_R: // VALIDE SEULEMENT APRES L'AVANCEMENT DES PATTES
      avancer_monstre();
      break;

    case TOUCHE_MIN_T:
      tourner_a_gauche();
      break;

    case TOUCHE_MIN_Y:
      tourner_a_droite();
      break;

    case TOUCHE_MIN_Q:
      lever_bras1();
      break;

    case TOUCHE_MAJ_Q:
      baisser_bras1();
      break;

    case TOUCHE_MIN_S:
      lever_bras2();
      break;

    case TOUCHE_MAJ_S:
      baisser_bras2();
      break;

    case TOUCHE_MIN_D:
      lever_bras3();
      break;

    case TOUCHE_MAJ_D:
      baisser_bras3();
      break;


    case TOUCHE_MIN_F:
      lever_bras4();
      break;

    case TOUCHE_MAJ_F:
      baisser_bras4();
      break;

    case TOUCHE_MIN_G:
      lever_bras5();
      break;

    case TOUCHE_MAJ_G:
      baisser_bras5();
      break;

    case TOUCHE_MIN_P:
    case TOUCHE_MAJ_P:
      automatique = (automatique == 1) ? 0 : 1;
      mouvements_aleatoires();
      break;
    

    case CAMERA:
        camera = (camera == 1) ? 0 : 1;
      break;
    }	
}

