#include <stdio.h>
#include <stdlib.h>
#include "Modele_TP2.h"
#include "conio.h"


/**========================= Retourner au Menu ========================**/
void retourMenu();

//********************** feuille ****************************//
int feuille (TNoeud *R);

//********************** Interface ****************************//
void cadre (int x , int y , TNoeud* N);

/*-------------------------------------------------*/
void aff_branche1(int l , int x , int y );

/*===============================================================================================*/
void aff_branche_gauche(int l , int x , int y );

/*===============================================================================================*/
void aff_branche_droite(int l , int x , int y );

/*=======================================================================================*/
void affiche_arbre(TNoeud *R,int x , int y , int l);

