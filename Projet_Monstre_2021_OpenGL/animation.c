#include "animation.h"

extern GLuint texture[];

GLuint animation = 1;

void showFrame(){
    static int nbFrame = 0;
    static unsigned long temps = 0;

    if (glutGet(GLUT_ELAPSED_TIME) - temps > 10.0f && animation < 45)
    {
        glBindTexture(GL_TEXTURE_2D, texture[animation]);

        animation = animation + 1;
        temps = glutGet(GLUT_ELAPSED_TIME);
    }

    glTranslatef(0.0f, 1.0f, 7.0f);
    glBegin(GL_QUADS);
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