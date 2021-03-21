#include "animation.h"

extern GLuint texture[];

GLuint animation = 0;

void showFrame(){
    static int nbFrame = 0;
    static unsigned long temps = 0;

    if (glutGet(GLUT_ELAPSED_TIME) - temps > 100.0f && animation < 45)
    {
        glPushMatrix();
        {
            glBegin(GL_QUADS);
                glBindTexture(GL_TEXTURE_2D, texture[animation]);
                glTexCoord2f(0.0f, 0.0f);
			    glVertex3f(1.0f, 1.0f, 0.0f);

                glTexCoord2f(1.0f, 0.0f);
			    glVertex3f(-1.0f, 1.0f, 0.0f);

                glTexCoord2f(1.0f, 1.0f);
			    glVertex3f(-1.0f, -1.0f, 0.0f);

                glTexCoord2f(0.0f, 1.0f);
			    glVertex3f(1.0f, -1.0f, 0.0f);
		    glEnd();
        }
        glPopMatrix();

        animation = animation + 1;
        temps = glutGet(GLUT_ELAPSED_TIME);
    }
}