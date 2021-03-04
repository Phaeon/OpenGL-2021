#include "monstre.h"


GLvoid pieds(GLfloat angle, GLfloat largeur, GLfloat hauteur) {
    glColor3f(255, 255, 0);
    glRotatef(10, 1, 0, 0);
    glTranslatef(0.0, 1.7, 2.5);
    glPushMatrix();
    {
        glScalef(0.35, 0.35, 0.8);
        glutSolidCube(1);
    }
    glPopMatrix();
    glRotatef(20, 1, 0, 0);
    glTranslatef(0.0, 0.15, 0.7);
    glPushMatrix();
    {
        glScalef(0.35, 0.35, 0.8);
        glutSolidCube(1);
    }
    glPopMatrix();

    glRotatef(45, 1, 0, 0);
    glTranslatef(0.0, 0.2, 0.6);
    glPushMatrix();
    {
        glScalef(0.35, 0.35, 0.8);
        glutSolidCube(1);
    }
    glPopMatrix();

    glTranslatef(0.0, 0.0, 0.35);
    glPushMatrix();
    {
        //glRotatef(180);
        glutSolidCone(0.2, 0.35, 20, 20);
    }
    glPopMatrix();
}


GLvoid corps(GLfloat largeur, GLfloat longueur, GLfloat hauteur) {
    glPushMatrix();
    {
        oreilles();
        oeil();
    }
    glPopMatrix();
    glTranslatef(0.0, 0.35, 0.0);
    glPushMatrix();
    {
        glColor3f(255, 0, 0);
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 3, 2.5, 1.5, 15, 15);
    }
    glPopMatrix();
    glTranslatef(0.0, 1.55, 0.0);
    glPushMatrix();
    {
        glColor3f(255, 0, 255);
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 2.0, 1.7, 1.8, 15, 15);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(0.0, 1.8, 0.0);
        glColor3f(255, 0, 255);
        glScalef(1.0, 0.1, 1.0);
        glutSolidSphere(1.7, 15, 15);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glColor3f(0, 0, 255);
        glScalef(1.0, 0.2, 1.0);
        glutSolidTorus(2.6, 0, 20, 20);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(255, 0, 255);
        glTranslatef(0.0, 2.0, 0.0);
        glRotatef(90, -1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 1.4, 1.35, 1.6, 17, 17);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(255, 0, 0);
        glScalef(0.7, 1.0, 1.0);
        glTranslatef(0.0, 3.6, 0.0);
        glRotatef(90, -1, 0, 0);
        glutSolidCone(0.3, 0.55, 10, 10);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0.0, 3.6, 0.0);
        glColor3f(255, 0, 255);
        glScalef(1.0, 0.1, 1.0);
        glutSolidSphere(1.35, 15, 15);
    }
    glPopMatrix();

}

GLvoid patte(GLfloat largeur, GLfloat longueur, GLfloat hauteur) {
    
    glPushMatrix();
    {
        glRotatef(180, 1, 0, 0);
        glRotatef(90, 1, 0, 0);
        GLUquadricObj* quadObj = gluNewQuadric();
        gluCylinder(quadObj, 0.7, 0.5, 0.5, 6, 6);
    }
    glPopMatrix();

    for (size_t i = 0; i < 5; i++)
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

    glTranslatef(0.0, -0.15, 0.0);
    
    
    for (size_t i = 0; i < 5; i++)
    {
        glRotatef(10, 0, 0, -1);
        glTranslatef(0.0, 0.45, 0.0);
        glPushMatrix();
        {
            glRotatef(90, 1, 0, 0);
            GLUquadricObj* quadObj = gluNewQuadric();
            gluCylinder(quadObj, 0.5, 0.4, 0.5, 6, 6);
        }
        glPopMatrix();
    }

    glTranslatef(0.0, -0.15, 0.0);
    
    
    for (size_t i = 0; i < 10; i++)
    {
        glRotatef(10, 0, 0, -1);
        glTranslatef(0.0, 0.45, 0.0);
        
        glPushMatrix();
        {
            glRotatef(90, 1, 0, 0);
            GLUquadricObj* quadObj = gluNewQuadric();
            gluCylinder(quadObj, 0.5, 0.4, 0.5, 6, 6);
        }
        glPopMatrix();
    }

    glTranslatef(0.0, -0.15, 0.0);

    for (size_t i = 0; i < 5; i++)
    {
        glRotatef(10, 0, 0, 1);
        glTranslatef(0.0, 0.45, 0.0);
        
        glPushMatrix();
        {
            glRotatef(90, 1, 0, 0);
            GLUquadricObj* quadObj = gluNewQuadric();
            gluCylinder(quadObj, 0.5, 0.4, 0.5, 6, 6);
        }
        glPopMatrix();
    }

}

GLvoid oeil() {

    glPushMatrix();
    {
        glColor3f(0, 255, 0);
        glTranslatef(0.0, 4.7, 1.4);
        glutSolidTorus(0.21, 0.22, 10, 10);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(0.1, 0.1, 0.1);
        glTranslatef(0.0, 4.7, 1.4);
        glutSolidSphere(0.3, 10, 10);
    }
    glPopMatrix();

}


GLvoid oreilles() {
    glColor3f(0, 255, 0);

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
