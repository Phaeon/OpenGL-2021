#include "sol.h"
#include "normale.h"
#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"

extern GLuint texture[];
extern GLfloat rayon_univers;

s_sol * creer_sol() {
    s_sol * sol = malloc(sizeof(s_sol));

    sol->sommets[0][0] = 15;
    sol->sommets[0][1] = 0;
    sol->sommets[0][2] = 15;

    sol->sommets[1][0] = -15;
    sol->sommets[1][1] = 0;
    sol->sommets[1][2] = 15;

    sol->sommets[2][0] = -15;
    sol->sommets[2][1] = 0;
    sol->sommets[2][2] = -15;

    sol->sommets[3][0] = 15;
    sol->sommets[3][1] = 0;
    sol->sommets[3][2] = -15;

    return sol;

}

void afficher_sol(s_sol * sol) {
        glNormal3f(0.0f, 1.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, texture[44]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);
		    glVertex3fv(sol->sommets[0]); // s0

            glTexCoord2f(1.0f, 0.0f);
		    glVertex3fv(sol->sommets[1]); // s1

            glTexCoord2f(1.0f, 1.0f);
		    glVertex3fv(sol->sommets[2]); // s2

            glTexCoord2f(0.0f, 1.0f);
		    glVertex3fv(sol->sommets[3]); // s3
	    glEnd();
}