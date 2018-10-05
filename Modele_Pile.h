#include <stdlib.h>
#include "noeud.h"
#define M 100

 typedef struct Pile {
         TNoeud* Tab[M];
         int sommet;
       }Pile;

/*************************** Creer La pile ****************************/
void Creer_Pile (Pile *P);

/****************** Vérifier si Une Pile est pleine ******************/
int Pile_pleine (Pile P);

/****************** Vérifier si Une Pile est vide ********************/
int Pile_vide (Pile P);

/************************* Empiler Une valeur ************************/
void Empiler (TNoeud*V,Pile *P);

/************************* Depilet Une valeur ************************/
void Depiler(TNoeud**V, Pile *P);
