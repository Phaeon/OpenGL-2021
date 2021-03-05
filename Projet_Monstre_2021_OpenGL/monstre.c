#include "monstre.h"

extern int bras_leve;

/*
* Axe de référence : z (+)
* Articulations : Augmenter rotation faire avancer la patte
* Augmenter angle patte, translation, réduire angle patte
*/
GLvoid pieds(GLfloat angle, GLfloat angle_2) {
    

    // ROTATION : avancée du monstre
    glRotatef(angle_2/2, 0, 1, 0);

    // ROTATION : augmentation angle moins amplifiée
    glRotatef(angle/2, -1, 0, 0);

    glRotatef(10, 1, 0, 0);
    glTranslatef(0.0, 1.7, 2.5);
    glPushMatrix();
    {

        glScalef(0.35, 0.35, 0.8);
        glutSolidCube(1);
    }
    glPopMatrix();

    // ROTATION : augmentation angle 
    glRotatef(angle, -1, 0, 0);

    glRotatef(20, 1, 0, 0);
    glTranslatef(0.0, 0.15, 0.7);
    glPushMatrix();
    {
        glScalef(0.35, 0.35, 0.8);
        glutSolidCube(1);
    }
    glPopMatrix();

    // ROTATION : augmentation angle 
    glRotatef(angle, -1, 0, 0);

    glRotatef(45, 1, 0, 0);
    glTranslatef(0.0, 0.2, 0.6);
    glPushMatrix();

        glPushMatrix();
        {
            glScalef(0.35, 0.35, 0.8);
            glutSolidCube(1);
        }
        glPopMatrix();
        glTranslatef(0.0, 0.0, 0.35);
    
        glPushMatrix();
        {
        
            glutSolidCone(0.2, 0.35, 20, 20);
        }
        glPopMatrix();
    glPopMatrix();
}


GLvoid corps(GLfloat angle, GLfloat longueur, GLfloat hauteur) {
    glPushMatrix();
    {
        // ROTATION de la tête
        glRotatef(angle, 0, 1, 0);
        oreilles();
        oeil();
    }
    glPopMatrix();
    glTranslatef(0.0, 0.35, 0.0);
    glPushMatrix();
    {
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 3, 2.5, 1.5, 15, 15);
    }
    glPopMatrix();
    glTranslatef(0.0, 1.55, 0.0);
    glPushMatrix();
    {
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 2.0, 1.7, 1.8, 15, 15);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(0.0, 1.8, 0.0);
        glScalef(1.0, 0.1, 1.0);
        glutSolidSphere(1.7, 15, 15);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glScalef(1.0, 0.2, 1.0);
        glutSolidTorus(2.6, 0, 20, 20);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef(angle, 0, 1, 0);
        glTranslatef(0.0, 2.0, 0.0);
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 1.4, 1.35, 1.6, 17, 17);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glScalef(0.7, 1.0, 1.0);
        glTranslatef(0.0, 3.6, 0.0);
        glRotatef(90, -1, 0, 0);
        glutSolidCone(0.3, 0.55, 10, 10);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0.0, 3.6, 0.0);
        glScalef(1.0, 0.1, 1.0);
        glutSolidSphere(1.35, 15, 15);
    }
    glPopMatrix();

}

GLvoid bras(GLfloat angle, GLfloat angle_2) {

    glRotatef(-angle, 0, 0, -1);
    glRotatef(100, 0, 0,1);

    for (size_t i = 0; i < 5; i++)
    {
        if (bras_leve == 0) glRotatef(20 - angle, 0, 0, 1);

        glTranslatef(0.0, -0.45, 0.0);
        glPushMatrix();
        {    
            glTranslatef(0.0, 0.45, 0.0);
        
            glPushMatrix();
            {
                glRotatef(90, 1, 0, 0);
                GLUquadricObj* quadObj = gluNewQuadric();
                gluCylinder(quadObj, 0.5, 0.4, 0.5, 6, 6);
            }
            glPopMatrix();
        
        }
        glPopMatrix();
    }


    for (size_t i = 0; i < 15; i++)
    {
        glRotatef(10 - angle, 0, 0, -1);
        glTranslatef(0.0, -0.45, 0.0);
        glPushMatrix();
        {    
            glTranslatef(0.0, 0.45, 0.0);
        
            glPushMatrix();
            {
                glRotatef(90, 1, 0, 0);
                GLUquadricObj* quadObj = gluNewQuadric();
                gluCylinder(quadObj, 0.5, 0.4, 0.5, 6, 6);
            }
            glPopMatrix();
        
        }
        glPopMatrix();
    }
    
    glTranslatef(0.0, -0.5, 0.0);

    glPushMatrix();
    {
        glRotatef(180, 1, 0, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 0.7, 0.5, 0.5, 6, 6);
    }
    glPopMatrix();

}

GLvoid oeil() {

    glPushMatrix();
    {
        glTranslatef(0.0, 4.7, 1.4);
        glutSolidTorus(0.21, 0.22, 10, 10);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0.0, 4.7, 1.4);
        glutSolidSphere(0.3, 10, 10);
    }
    glPopMatrix();

}


GLvoid oreilles() {

    glPushMatrix();
    {
        glRotatef(90, 0, -1, 0);

        glPushMatrix();
        {
            glTranslatef(-1.2, 5.7, 0.0);
            glRotatef(35, 0, 0, -1);
            glScalef(1.5, 1.0, 1.0);
            glutSolidTorus(0.21, 0.22, 10, 10);
        }
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(-1.2, 5.7, 0.0);
        glRotatef(35, 0, 0, -1);
        glScalef(1.5, 1.0, 1.0);
        glutSolidTorus(0.21, 0.22, 10, 10);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(1.2, 5.7, 0.0);
        glRotatef(35, 0 ,0 ,1);
        glScalef(1.5, 1.0, 1.0);
        glutSolidTorus(0.21, 0.22, 10, 10);
    }
    glPopMatrix();

}
