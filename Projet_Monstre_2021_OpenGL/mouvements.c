#include "mouvements.h"
#include <stdio.h>
#include "actions.h"
#include "touches.h"

extern int sommet_ava;
extern int sommet_lat;
extern int sommet_arr;

extern int avancer_ava;
extern int avancer_lat;
extern int avancer_arr;

extern GLfloat angle_pattes_AD;
extern GLfloat angle_pattes_AD_y;
extern GLfloat angle_pattes_AG;
extern GLfloat angle_pattes_AG_y;
extern GLfloat angle_pattes_CD;
extern GLfloat angle_pattes_CD_y;
extern GLfloat angle_pattes_CG;
extern GLfloat angle_pattes_CG_y;
extern GLfloat angle_pattes_ARD;
extern GLfloat angle_pattes_ARD_y;
extern GLfloat angle_pattes_ARG;
extern GLfloat angle_pattes_ARG_y;

extern GLfloat rayon_univers;
extern GLfloat mouvement_monstre_x;
extern GLfloat mouvement_monstre_y;
extern GLfloat mouvement_monstre_z;
extern GLfloat rotation_monstre_y;

extern GLfloat angle_bras_1;
extern GLfloat angle_bras_2;
extern GLfloat angle_bras_3;
extern GLfloat angle_bras_4;
extern GLfloat angle_bras_5;

extern int bras_leve_1;
extern int bras_leve_2;
extern int bras_leve_3;
extern int bras_leve_4;
extern int bras_leve_5;

extern int rotation;
extern int right_end;
extern GLfloat angle_tete;


extern int tourner;
extern int automatique;

GLfloat rot = 90.0f;
int brasC = 0;

GLvoid rotation_pattes_avant() // sommet = 0 que lorsqu'il aura avancé
{   
    if (sommet_ava == 0) {
        if (angle_pattes_AD <= 10.0f) {
            angle_pattes_AG += 0.1f;
            angle_pattes_AD += 0.1f;
        } else sommet_ava = 1;
    } else {
        if (angle_pattes_AD_y <= 5.0f) {
            angle_pattes_AG_y += 0.2f;
            angle_pattes_AD_y += 0.2f;
        } else {
            if (angle_pattes_AD > 0) {
                angle_pattes_AG -= 0.1f;
                angle_pattes_AD -= 0.1f;
            } else avancer_ava = 1;
        }
    }
}

GLvoid rotation_pattes_lat() 
{
    if (sommet_lat == 0) {
        if (angle_pattes_CD <= 10.0f) {
            angle_pattes_CG += 0.1f;
            angle_pattes_CD += 0.1f;
        } else sommet_lat = 1;
    } else {
        if (angle_pattes_CD_y <= 5.0f) {
            angle_pattes_CG_y += 0.2f;
            angle_pattes_CD_y += 0.2f;
        } else {
            if (angle_pattes_CD > 0) {
                angle_pattes_CG -= 0.1f;
                angle_pattes_CD -= 0.1f;
            } else avancer_lat = 1;
        }
    }
}

GLvoid rotation_pattes_arriere()
{
    if (sommet_arr == 0) {
        if (angle_pattes_ARD <= 10.0f) {
            angle_pattes_ARG += 0.1f;
            angle_pattes_ARD += 0.1f;
        } else sommet_arr = 1;
    } else {
        if (angle_pattes_ARD_y <= 5.0f) {
            angle_pattes_ARG_y += 0.2f;
            angle_pattes_ARD_y += 0.2f;
        } else {
            if (angle_pattes_ARD > 0) {
                angle_pattes_ARG -= 0.1f;
                angle_pattes_ARD -= 0.1f;
            } else avancer_arr = 1;
        }
    }
}


int getRotation() {
    if (rotation_monstre_y == 90 || rotation_monstre_y == -270) return 2;
    else if (rotation_monstre_y == -90 || rotation_monstre_y == 270) return 4;
    else if (rotation_monstre_y == 0) return 1;
    else if (rotation_monstre_y == 180 || rotation_monstre_y == -180) return 3;
    return 0;
}


GLvoid avancer_monstre() {
    if (avancer_ava && avancer_lat && avancer_arr) {
        if (angle_pattes_AD_y > 0) {
            angle_pattes_AD_y -= 0.2f;
            angle_pattes_AG_y -= 0.2f;
            angle_pattes_ARD_y -= 0.2f;
            angle_pattes_ARG_y -= 0.2f;
            angle_pattes_CD_y -= 0.2f;
            angle_pattes_CG_y -= 0.2f;

            int br = rand()%51;
            if (brasC == 0 && automatique) {
                if (br == 1) {
                    tourner = rand() % 2;
                    rotation = getRotation();
                } else if (br == 6) brasC = 1;
                else if (br == 12) brasC = 2;
                else if (br == 21) brasC = 3;
                else if (br == 35) brasC = 4;
                else if (br == 46) brasC = 5;
            }

            if (rotation_monstre_y == 90 || rotation_monstre_y == -270) {
                if (mouvement_monstre_x < (rayon_univers/2 - 2.0f)) mouvement_monstre_x += 0.075;
                else {
                    int t = rand()%2;
                    if (t == 1) tourner = 1;
                    else tourner = 0;
                    rotation = 2;
                }
            } else if (rotation_monstre_y == -90 || rotation_monstre_y == 270) {
                if (mouvement_monstre_x > (-rayon_univers/2 + 2.0f)) mouvement_monstre_x -= 0.075; 
                else {
                    int t = rand()%2;
                    if (t == 1) tourner = 1;
                    else tourner = 0;
                    rotation = 4;
                }        
            } else if (rotation_monstre_y == 180 || rotation_monstre_y == -180) {
                if (mouvement_monstre_z > (-rayon_univers/2 + 2.0f)) mouvement_monstre_z -= 0.075;
                else {
                    int t = rand()%2;
                    if (t == 1) tourner = 1;
                    else tourner = 0;
                    rotation = 3;
                }
            } else if (rotation_monstre_y == 0) {
                if (mouvement_monstre_z < (rayon_univers/2 - 2.0f)) mouvement_monstre_z += 0.075;   
                else {
                    int t = rand()%2;
                    if (t == 1) tourner = 1;
                    else tourner = 0;
                    rotation = 1;
                }
            }
        } else {
            avancer_ava = 0;
            avancer_lat = 0;
            avancer_arr = 0;
            sommet_ava = 0;
            sommet_lat = 0;
            sommet_arr = 0;
        }
    }
}


GLvoid tourner_a_gauche()
{
    if (automatique && rotation > 0) {
        if (rot <= 180) {
            rot += 0.2f;
            rotation_monstre_y += 0.2f;
        } else {
            if (rotation == 1) rotation_monstre_y = 90; // si angle entre 0 et 90
            else if (rotation == 2) rotation_monstre_y = 180; // si angle entre 90 et 180
            else if (rotation == 3) rotation_monstre_y = 270; // entre 180 et 270
            else if (rotation == 4) rotation_monstre_y = 0; // + 270
            rotation = 0;
            rot = 90.f;
        }
    } else {
        if (rotation_monstre_y >= 360) rotation_monstre_y = 0;
        rotation_monstre_y += 0.2;
    }
}


GLvoid tourner_a_droite()
{
    if (automatique && rotation > 0) {
        if (rot >= 0) {
            rot -= 0.2f;
            rotation_monstre_y -= 0.2f;
        } else {
            if (rotation == 1) rotation_monstre_y = -90;
            else if (rotation == 4) rotation_monstre_y = -180;
            else if (rotation == 3) rotation_monstre_y = -270;
            else if (rotation == 2) rotation_monstre_y = 0;
            rotation = 0;
            rot = 90.f;
        }
    } else {
        if (rotation_monstre_y <= -360) rotation_monstre_y = 0;
        rotation_monstre_y -= 0.2;
    }
}


GLvoid rotation_tete()
{
    if (right_end) {
        if (angle_tete > -15.0f) angle_tete -= 0.15f;
        else right_end = 0;
    } else {
        if (angle_tete <= 15.0f) angle_tete += 0.15f;
        else right_end = 1;
    }
}


GLvoid lever_bras1()
{
    if (bras_leve_1 == 0) {
        if (angle_bras_1 <= 20) angle_bras_1 += 0.3f;
        else {
            bras_leve_1 = 1;
        }
    }
}

GLvoid baisser_bras1() 
{
    if (bras_leve_1) {
        if (angle_bras_1 > 7) angle_bras_1 -= 0.2f;
        else {
            brasC = 0;
            bras_leve_1 = 0;
        }
    } 
}

GLvoid lever_bras2()
{
    if (bras_leve_2 == 0) {
        if (angle_bras_2 <= 20) angle_bras_2 += 0.3f;
        else {
            bras_leve_2 = 1;
        }
    }
}

GLvoid baisser_bras2() 
{
    if (bras_leve_2) {
        if (angle_bras_2 > 7) angle_bras_2 -= 0.2f;
        else {
            brasC = 0;
            bras_leve_2 = 0;
        }
    } 
}


GLvoid lever_bras3()
{
    if (bras_leve_3 == 0) {
        if (angle_bras_3 <= 20) angle_bras_3 += 0.3f;
        else {
            bras_leve_3 = 1;
        }
    }
}

GLvoid baisser_bras3() 
{
    if (bras_leve_3) {
        if (angle_bras_3 > 7) angle_bras_3 -= 0.2f;
        else {
            brasC = 0;
            bras_leve_3 = 0;
        }
    } 
}


GLvoid lever_bras4()
{
    if (bras_leve_4 == 0) {
        if (angle_bras_4 <= 20) angle_bras_4 += 0.3f;
        else {
            bras_leve_4 = 1;
        }
    }
}

GLvoid baisser_bras4() 
{
    if (bras_leve_4) {
        if (angle_bras_4 > 7) angle_bras_4 -= 0.2f;
        else {
            brasC = 0;
            bras_leve_4 = 0;
        }
    } 
}


GLvoid lever_bras5()
{
    if (bras_leve_5 == 0) {
        if (angle_bras_5 <= 20) angle_bras_5 += 0.3f;
        else {
            bras_leve_5 = 1;
        }
    }
}

GLvoid baisser_bras5() 
{
    if (bras_leve_5) {
        if (angle_bras_5 > 7) angle_bras_5 -= 0.2f;
        else {
            brasC = 0;
            bras_leve_5 = 0;
        }
    } 
}


// MOUVEMENTS ALEATOIRES
GLvoid avancer_auto()
{
    int r = rand() % 101;

    if (avancer_ava == 0) rotation_pattes_avant();
    if (avancer_lat == 0 && avancer_ava) rotation_pattes_lat();
    if (avancer_arr == 0 && avancer_lat && avancer_ava) rotation_pattes_arriere();

    if (rotation == 0) avancer_monstre();
    else {
        if (tourner) tourner_a_gauche();
        else tourner_a_droite();
    }

    if (r < 15) rotation_tete();
    if (brasC == 1) {
        lever_bras1();
        baisser_bras1();
    } else if (brasC == 2) {
        lever_bras2();
        baisser_bras2();
    } else if (brasC == 3) {
        lever_bras3();
        baisser_bras3();
    } else if (brasC == 4) {
        lever_bras4();
        baisser_bras4();
    } else if (brasC == 5) {
        lever_bras5();
        baisser_bras5();
    }
}