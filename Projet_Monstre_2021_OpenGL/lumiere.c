#include "lumiere.h"

void lumiere() {

    // LUMIÈRE AMBIANTE
	GLfloat lumiere_ambiante[4] = {0.2, 0.2, 0.2, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lumiere_ambiante);

    GLfloat mcolor[4] = {0.0f, 0.1f, 0.1f, 1.0f};

     // MATÉRIAUX ET BRILLANCE
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mcolor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mcolor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);

    // LUMIÈRE POSITIONNELLE
    GLfloat LightColorP[] = { 0.9f, 0.9f, 0.9f, LUMIERE_POSITIONNELLE};
    GLfloat LightPositionP[] = { 0.0f, 6.0f, 0.0f, LUMIERE_POSITIONNELLE};
  
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightColorP);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightColorP);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPositionP);

    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0);
    GLfloat dir[3] = {0.0f, 0.0f, -1.0f};
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
    glEnable(GL_LIGHT0);

    // LUMIÈRE DIRECTIONNELLE
    GLfloat LightColorD[] = { 0.9f, 0.9f, 0.9f, LUMIERE_DIRECTIONNELLE};
    GLfloat LightPositionD[] = { 0.0f, 7.0f, 0.0f, LUMIERE_DIRECTIONNELLE};

    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightColorD);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightColorD);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPositionD);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.7);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1.8);
    glEnable(GL_LIGHT1);
}
