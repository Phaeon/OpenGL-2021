#include "mouvements.h"

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
extern GLfloat mouvement_monstre_z;

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

extern int right_end;
extern GLfloat angle_tete;

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


GLvoid avancer_monstre() {
    if (avancer_ava && avancer_lat && avancer_arr) {
        if (angle_pattes_AD_y > 0) {
            angle_pattes_AD_y -= 0.2f;
            angle_pattes_AG_y -= 0.2f;
            angle_pattes_ARD_y -= 0.2f;
            angle_pattes_ARG_y -= 0.2f;
            angle_pattes_CD_y -= 0.2f;
            angle_pattes_CG_y -= 0.2f;
            mouvement_monstre_z += 0.025;
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


GLvoid rotation_tete()
{
    if (right_end) {
        if (angle_tete > -15.0f) angle_tete -= 0.5f;
        else right_end = 0;
    } else {
        if (angle_tete <= 15.0f) angle_tete += 0.5f;
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
        else bras_leve_1 = 0;
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
        else bras_leve_2 = 0;
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
        else bras_leve_3 = 0;
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
        else bras_leve_4 = 0;
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
        else bras_leve_5 = 0;
    } 
}