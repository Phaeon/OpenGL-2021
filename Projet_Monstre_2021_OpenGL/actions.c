#include "actions.h"
#include "mouvements.h"
#include <stdio.h>
#include <GL/glut.h>

// PARAMETRES GENERAUX
extern GLfloat z;
extern GLuint blend;
extern GLuint light;

extern GLfloat xrot_objet;   
extern GLfloat yrot_objet;    
extern GLfloat zrot_objet;    

extern GLfloat xrot_scene;   
extern GLfloat yrot_scene;    
extern GLfloat zrot_scene;    

extern GLfloat xrot_camera;   
extern GLfloat yrot_camera;    
extern GLfloat zrot_camera;  

// CAMERA
extern GLuint camera;

// DEPLACEMENTS DU MONSTRE
extern GLfloat mouvement_monstre_x;
extern GLfloat mouvement_monstre_z;
int rotation = 0;

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
extern int culling;
extern int anim;


void touche_special(int touche, int t, int u) 
{
	switch (touche) {    
	case GLUT_KEY_PAGE_UP:
		if (z < -1) z++;
		break;
	case GLUT_KEY_PAGE_DOWN:
		if (z > -35) z--;
		break;
	case GLUT_KEY_UP:
		if (camera == 1) xrot_objet -=5.0f; 
    else if (camera == 2) xrot_scene -=5.0f; 
    else xrot_camera -=5.0f; 
		break;

	case GLUT_KEY_DOWN:
		if (camera == 1) xrot_objet +=5.0f; 
    else if (camera == 2) xrot_scene +=5.0f; 
    else xrot_camera +=5.0f; 
		break;

	case GLUT_KEY_LEFT:
		if (camera == 1) yrot_objet -=5.0f; 
    else if (camera == 2) yrot_scene -=5.0f; 
    else yrot_camera -=5.0f; 
		break;
	case GLUT_KEY_RIGHT:
		if (camera == 1) yrot_objet +=5.0f; 
    else if (camera == 2) yrot_scene +=5.0f; 
    else yrot_camera +=5.0f; 
		break;
	case GLUT_KEY_HOME:
		if (camera == 1) zrot_objet -=5.0f; 
    else if (camera == 2) zrot_scene -=5.0f; 
    else zrot_camera -=5.0f; 
		break;
	case GLUT_KEY_END:
		if (camera == 1) zrot_objet += 5.0f; 
    else if (camera == 2) zrot_scene += 5.0f; 
    else zrot_camera += 5.0f; 
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
      xrot_objet = 0.0;
      yrot_objet = 0.0;
      zrot_objet = 0.0;

      xrot_scene = 0.0;
      yrot_scene = 0.0;
      zrot_scene = 0.0;

      xrot_camera = 0.0;
      yrot_camera = 0.0;
      zrot_camera = 0.0;

      z = -20.0;
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;
      
    case TOUCHE_MIN_A:
      rotation_pattes_avant();
      break;

    case TOUCHE_MIN_Z:
      rotation_pattes_lat();
      break;

    case TOUCHE_MIN_E:
      rotation_pattes_arriere();
      break;

    case TOUCHE_MIN_R:
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
      anim = (anim == 1) ? 0 : 1;
      break;

    case TOUCHE_MAJ_P:
      automatique = (automatique == 1) ? 0 : 1;
      break;

    case CAMERA:
      camera = (camera == 1) ? 2 : ((camera == 2) ? 3 : 1);
      break;

    case CULLING_MIN_C:
    case CULLING_MAJ_C:
      culling = (culling == 1) ? 0 : 1;
      if (culling) {
		    glEnable(GL_CULL_FACE); // Faces cachées  
		    glFrontFace(GL_CCW); // Définir le mode d'affichage des faces visibles (Counter) ClockWise                                                              
		    glCullFace(GL_CW);// Définir le mode d'affichage des faces cachées (Counter) ClockWise               
	    } else glDisable(GL_CULL_FACE);
      break;
    }	
}

