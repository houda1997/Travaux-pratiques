#include <stdio.h>
#include <stdlib.h>
#include "Modele_Pile.h"

/**=========================== Recherche ==============================**/
/**    Rechercher une valeur dans une Arbre de Recherche Binaire
/**=====================================================================**/
void Recherche(int V, TNoeud *Racine, TNoeud **Pere, TNoeud **P);

/**=========================== UpdateHauteur =================================**/
/**    metre à jour le champs Hauteur dans un arbre R
/**===========================================================================**/
void UpdateHauteur(TNoeud *R);

/**=========================== Inserer =================================**/
/**    Inserer une valeur dans une Arbre de Recherche Binaire
/**=====================================================================**/
void Inserer(int V, TNoeud **Racine);

/**=============================== Cvrt_TabABR =================================**/
/**    Construire un arbre binaire de recherche de racine "R" avec les elements
/**                     du tableau "Tab" du taille "m"
/**=============================================================================**/
void Cvrt_TabABR (TNoeud ** R,int *Tab,int m);

/**=============================== RandTab =========================================**/
/**   Remplir un tableau "Tab" du taille "m" avc des valeur aleéatoire entre 0 et 100
/**=================================================================================**/
void RandTab (int *Tab,int m);

/*************** Le Max entre a et B ***************/
int Max (int a, int b);

/*************** La valeur absolue ***************/
int abs(int x);

/**=============================== BienEqu ===============================**/
/**   Retourne un 1 si l'arbre "R" est bien équilibré et "0" sinon
/**=======================================================================**/
int bienEqu(TNoeud *R);

/**=============================== LibereARB ===============================**/
/**                Liberer l'espace mémoire occupé par un arbre
/**=======================================================================**/
void LibereARB(TNoeud**R);

/**=============================== Rotation Droite  ===============================**/
/**  Faire une rotation Droite sur le Noeud n et retourne le nouveau noeud
/**                        qui va prendre sa place
/**==============================================================================**/
TNoeud *RotationDroite (TNoeud *n);

/**========================= Creation une Branche droite ========================**/
/**        Transformer un arbre "R" en une seule branche droite
/**==============================================================================**/
TNoeud * CreationDrVine (TNoeud*root,int *cmpt,int *VisitN2);

/**========================= Compter les Noeud  ========================================**/
/**      retourne le nombre des neoud dans un arbre "R" construit d'une seule branche droite
/**=====================================================================================**/
int ComptNoeud(TNoeud * root);

/**========================= Balancer une Branche  ========================**/
/**      equilibrer un arbre construit d'une seule branche droite
/**     en retournant des compteurs de rotations et noeuds visitées
/**====================================================================**/
TNoeud * BalanceVine (TNoeud *root , int Comp,int *cmpt2,int *VisitN);

/**========================= DSW ========================**/
/**      Equilibrer un arbre "R" par la méthode DSW
/**           en retournant des compteurs
/**======================================================**/
void DSW (TNoeud **R,int *cmpt,int *NoeudVisit);
