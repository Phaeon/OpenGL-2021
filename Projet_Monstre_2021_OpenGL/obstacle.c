#include "obstacle.h"
#include "ppm.h"

extern GLuint texture[];

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
	
	cube->faces[0][0] = faces[0][0];
	cube->faces[0][1] = faces[0][1];
	cube->faces[0][2] = faces[0][2];
	cube->faces[0][3] = faces[0][3];
	
	cube->faces[1][0] = faces[1][0];
	cube->faces[1][1] = faces[1][1];
	cube->faces[1][2] = faces[1][2];
	cube->faces[1][3] = faces[1][3];
	
	cube->faces[2][0] = faces[2][0];
	cube->faces[2][1] = faces[2][1];
	cube->faces[2][2] = faces[2][2];
	cube->faces[2][3] = faces[2][3];
	
	cube->faces[3][0] = faces[3][0];
	cube->faces[3][1] = faces[3][1];
	cube->faces[3][2] = faces[3][2];
	cube->faces[3][3] = faces[3][3];
	
	cube->faces[4][0] = faces[4][0];
	cube->faces[4][1] = faces[4][1];
	cube->faces[4][2] = faces[4][2];
	cube->faces[4][3] = faces[4][3];
	
	cube->faces[5][0] = faces[5][0];
	cube->faces[5][1] = faces[5][1];
	cube->faces[5][2] = faces[5][2];
	cube->faces[5][3] = faces[5][3];

    return cube;

}


void afficher_cube(s_cube * cube) {
		int i;
		for (i = 0; i < 6; i++) {
            glColor3f(255, 255, 255);
			glBegin(GL_QUADS);
                glBindTexture(GL_TEXTURE_2D, texture[0]);
                glTexCoord2f(0.0f, 0.0f);
				glVertex3fv(cube->sommets[cube->faces[i][0]]);

                glTexCoord2f(2.0f, 0.0f);
				glVertex3fv(cube->sommets[cube->faces[i][1]]);

                glTexCoord2f(2.0f, 2.0f);
				glVertex3fv(cube->sommets[cube->faces[i][2]]);

                glTexCoord2f(0.0f, 2.0f);
				glVertex3fv(cube->sommets[cube->faces[i][3]]);
			glEnd();
		}
}