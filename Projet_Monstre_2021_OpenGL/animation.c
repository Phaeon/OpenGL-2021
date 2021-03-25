#include "animation.h"

extern GLuint texture[];

GLuint animation = 1;

void showAnimation(GLfloat posX, GLfloat posY, GLfloat posZ){
    unsigned long temps = 0;

    if (glutGet(GLUT_ELAPSED_TIME) - temps > 100.0f && animation < 44)
    {
        glEnable(GL_TEXTURE_2D);
        glTranslatef(posX, posY, posZ);
        glColor3f(255, 255, 255);
        glNormal3f(0.0f, 0.0f, 1.0f);
        
        glBindTexture(GL_TEXTURE_2D, texture[animation]);
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
        glDisable(GL_TEXTURE_2D);

        animation = animation + 1;
        temps = glutGet(GLUT_ELAPSED_TIME);

        if (animation == 44) animation = 1;
    }
    
}