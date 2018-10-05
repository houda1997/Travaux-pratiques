#include "Modele_Pile.h"

/*************************** Creer La pile ****************************/
void Creer_Pile (Pile *P)
{
    P->sommet=-1;
}

/****************** Vérifier si Une Pile est pleine ******************/
int Pile_pleine (Pile P)
{
    if (P.sommet == (M-1) ) {return (1);}
    else {return (0);}
}


/****************** Vérifier si Une Pile est vide ********************/
int Pile_vide (Pile P)
{
    if (P.sommet == -1 ) {return (1);}
    else {return (0);}
}

/************************* Empiler Une valeur ************************/
void Empiler (TNoeud*V,Pile *P)
{
    if (!Pile_pleine(*P))
    {
        P->sommet=(P->sommet)+1;
        P->Tab[P->sommet]=V;
    }
}


/************************* Depilet Une valeur ************************/
void Depiler(TNoeud**V, Pile *P)
{
    if (!Pile_vide(*P))
    {
        *V=P->Tab[P->sommet];
        P->sommet=(P->sommet) -1;
    }
}
