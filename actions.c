#include "actions.h"
#include <stdio.h>
#include <GL/glut.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat x;
extern GLfloat y;
extern GLfloat z;
extern GLuint blend;
extern GLuint light;

extern GLuint camera;



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
      
    case TOUCHE_MIN_A: 
      z--;
      break;
      
    case TOUCHE_MAJ_A: 
      z++;
      break;

    case CAMERA:
        camera = (camera == 1) ? 0 : 1;
      break;
    }	
}

