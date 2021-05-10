#include "obstacle.h"
#include "normale.h"
#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>

extern GLuint texture[];

static int faces_cube[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 5, 4}, {1, 7, 6, 2}, {0, 4, 7, 1}, {3, 2, 6, 5}};

s_cube * creer_cube (GLfloat Taille) {
	s_cube * cube = malloc(sizeof(s_cube));
	
	cube->sommets[0][0] = Taille * 0.5;
	cube->sommets[0][1] = Taille * 0.5;
	cube->sommets[0][2] = Taille * 0.5;
	
	cube->sommets[1][0] = Taille * -0.5;
	cube->sommets[1][1] = Taille * 0.5;
	cube->sommets[1][2] = Taille * 0.5;
	
	cube->sommets[2][0] = Taille * -0.5;
	cube->sommets[2][1] = Taille * -0.5;
	cube->sommets[2][2] = Taille * 0.5;
	
	cube->sommets[3][0] = Taille * 0.5;
	cube->sommets[3][1] = Taille * -0.5;
	cube->sommets[3][2] = Taille * 0.5;

	cube->sommets[4][0] = Taille * 0.5;
	cube->sommets[4][1] = Taille * 0.5;
	cube->sommets[4][2] = Taille * -0.5;
	
	cube->sommets[5][0] = Taille * 0.5;
	cube->sommets[5][1] = Taille * -0.5;
	cube->sommets[5][2] = Taille * -0.5;
	
	cube->sommets[6][0] = Taille * -0.5;
	cube->sommets[6][1] = Taille * -0.5;
	cube->sommets[6][2] = Taille * -0.5;
	
	cube->sommets[7][0] = Taille * -0.5;
	cube->sommets[7][1] = Taille * 0.5;
	cube->sommets[7][2] = Taille * -0.5;
	
	cube->faces[0][0] = faces_cube[0][0];
	cube->faces[0][1] = faces_cube[0][1];
	cube->faces[0][2] = faces_cube[0][2];
	cube->faces[0][3] = faces_cube[0][3];
	
	cube->faces[1][0] = faces_cube[1][0];
	cube->faces[1][1] = faces_cube[1][1];
	cube->faces[1][2] = faces_cube[1][2];
	cube->faces[1][3] = faces_cube[1][3];
	
	cube->faces[2][0] = faces_cube[2][0];
	cube->faces[2][1] = faces_cube[2][1];
	cube->faces[2][2] = faces_cube[2][2];
	cube->faces[2][3] = faces_cube[2][3];
	
	cube->faces[3][0] = faces_cube[3][0];
	cube->faces[3][1] = faces_cube[3][1];
	cube->faces[3][2] = faces_cube[3][2];
	cube->faces[3][3] = faces_cube[3][3];
	
	cube->faces[4][0] = faces_cube[4][0];
	cube->faces[4][1] = faces_cube[4][1];
	cube->faces[4][2] = faces_cube[4][2];
	cube->faces[4][3] = faces_cube[4][3];
	
	cube->faces[5][0] = faces_cube[5][0];
	cube->faces[5][1] = faces_cube[5][1];
	cube->faces[5][2] = faces_cube[5][2];
	cube->faces[5][3] = faces_cube[5][3];
	
	cube->couleurs[0][0] = Taille*1;
	cube->couleurs[0][1] = 0; 
	cube->couleurs[0][2] = 0; 
	
	cube->couleurs[1][0] = 0;
	cube->couleurs[1][1] = Taille*1; 
	cube->couleurs[1][2] = 0; 
	
	cube->couleurs[2][0] = 0;
	cube->couleurs[2][1] = 0; 
	cube->couleurs[2][2] = Taille*1; 
	
	cube->couleurs[3][0] = Taille*1;
	cube->couleurs[3][1] = 0; 
	cube->couleurs[3][2] = Taille*1;
	
	cube->couleurs[4][0] = Taille*1;
	cube->couleurs[4][1] = Taille*1; 
	cube->couleurs[4][2] = 0; 
	
	cube->couleurs[5][0] = Taille*1;
	cube->couleurs[5][1] = Taille*1; 
	cube->couleurs[5][2] = Taille*1; 
	
	return cube;
}

s_cube2 * creer_cube2(GLfloat Taille) {
	s_cube2 * cube = malloc(sizeof(s_cube2));
	s_cube * cube1 = creer_cube(Taille);
	cube->cube1 = cube1;


	/* Faces avant et arrière */
	normale * n = calcul_normale(
		cube->cube1->sommets[0][0], cube->cube1->sommets[0][1], cube->cube1->sommets[0][2], 
		cube->cube1->sommets[1][0], cube->cube1->sommets[1][1], cube->cube1->sommets[1][2],
		cube->cube1->sommets[2][0], cube->cube1->sommets[2][1], cube->cube1->sommets[2][2]
	);

	cube->normales_faces[0][0] = n->x;
	cube->normales_faces[0][1] = n->y;
	cube->normales_faces[0][2] = n->z;


	cube->normales_faces[1][0] = -1*cube->normales_faces[0][0];
	cube->normales_faces[1][1] = -1*cube->normales_faces[0][1];
	cube->normales_faces[1][2] = -1*cube->normales_faces[0][2];


	/* Gauche et droite  */
	normale * n2 = calcul_normale(
		cube->cube1->sommets[3][0], cube->cube1->sommets[3][1], cube->cube1->sommets[3][2], 
		cube->cube1->sommets[0][0], cube->cube1->sommets[1][1], cube->cube1->sommets[0][2],
		cube->cube1->sommets[5][0], cube->cube1->sommets[5][1], cube->cube1->sommets[5][2]
	);

	cube->normales_faces[2][0] = n2->x;
	cube->normales_faces[2][1] = n2->y;
	cube->normales_faces[2][2] = n2->z;

	cube->normales_faces[3][0] = -1*cube->normales_faces[2][0];
	cube->normales_faces[3][1] = -1*cube->normales_faces[2][1];
	cube->normales_faces[3][2] = -1*cube->normales_faces[2][2];


	/* Haut et bas  */
	normale * n3 = calcul_normale(
		cube->cube1->sommets[4][0], cube->cube1->sommets[4][1], cube->cube1->sommets[4][2], 
		cube->cube1->sommets[0][0], cube->cube1->sommets[1][1], cube->cube1->sommets[0][2],
		cube->cube1->sommets[7][0], cube->cube1->sommets[7][1], cube->cube1->sommets[7][2]
	);

	cube->normales_faces[4][0] = n3->x;
	cube->normales_faces[4][1] = n3->y;
	cube->normales_faces[4][2] = n3->z;

	cube->normales_faces[5][0] = -1*cube->normales_faces[4][0];
	cube->normales_faces[5][1] = -1*cube->normales_faces[4][1];
	cube->normales_faces[5][2] = -1*cube->normales_faces[4][2];


	return cube;
}


void afficher_cube2(s_cube2 * cube) {
		glEnable(GL_TEXTURE_2D);

		int i;
		for (i = 0; i < 6; i++) {

			glNormal3fv(cube->normales_faces[i]);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
			glBegin(GL_QUADS);
				glColor3f(255, 255, 255);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3fv(cube->cube1->sommets[cube->cube1->faces[i][0]]);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3fv(cube->cube1->sommets[cube->cube1->faces[i][1]]);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3fv(cube->cube1->sommets[cube->cube1->faces[i][2]]);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3fv(cube->cube1->sommets[cube->cube1->faces[i][3]]);
			glEnd();
		}

		glDisable(GL_TEXTURE_2D);
}






GLvoid creerLampadaire(GLfloat posX, GLfloat posZ) {
	glTranslatef(posX, 0.0, posZ);
	glColor3f(1, 0, 0);
	glPushMatrix();
	{
		glTranslatef(0.0, -0.1, 0.0);
		glPushMatrix();
		{
			glColor3f(1, 0, 0);
			glRotatef(90, -1, 0, 0);
        	GLUquadricObj* quadObj = gluNewQuadric();
        	gluCylinder(quadObj, 0.9, 0.4, 0.7, 6, 6);
		}
		glPopMatrix();
		glTranslatef(0.0, 0.7, 0.0);
		glPushMatrix();
		{
			glColor3f(1, 0, 0);
			glRotatef(90, -1, 0, 0);
        	GLUquadricObj* quadObj = gluNewQuadric();
        	gluCylinder(quadObj, 0.4, 0.4, 6.0, 6, 6);
		}
		glPopMatrix();
		glTranslatef(0.0, 6.0, 0.0);
		glPushMatrix();
		{	
			glColor3f(1, 0, 0);
			glutSolidSphere(0.6, 20, 20);
		}
		glPopMatrix();
	}
	glPopMatrix();
}