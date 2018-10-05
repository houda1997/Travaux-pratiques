#include <stdio.h>
#include <stdlib.h>
#include "Modele_TP2.h"


/*



TNoeud * rotateRight (TNoeud*grandParent, TNoeud*parent, TNoeud* leftChild)
 {
    TNoeud*root;
  if (grandParent != NULL) {
    Aff_FD(grandParent,leftChild);
    //FD(grandParent) = leftChild;
  } else {
    root = leftChild;
  }
  //parent.left = leftChild.right;
  Aff_FG(parent,FD(leftChild));
  Aff_FD(leftChild,parent);
  //FD(leftChild)= parent;
  return grandParent;
}

 void createBackbone(TNoeud **root) {
  TNoeud* grandParent = NULL;
  TNoeud* parent = *root;
  TNoeud* leftChild;

  while (parent!=NULL) {
    leftChild = FG(parent);
    if (leftChild!=NULL) {
      grandParent = rotateRight(grandParent, parent, leftChild);
      parent = leftChild;
    } else {
      grandParent = parent;
      parent = FD(parent);
    }
  }
}

/************************************************************************
 *   Before      After
 *    Gr          Gr
 *     \           \
 *     Par         Ch
 *    /  \        /  \
 *   Ch   Z      X   Par
 *  /  \            /  \
 * X    Y          Y    Z
 ***********************************************************************/
/*TNoeud * rotateRight (TNoeud*grandParent, TNoeud*parent, TNoeud* leftChild)
 {
    TNoeud*root;
  if (*grandParent != NULL) {
    FD(grandParent) = leftChild;
  } else {
    root = leftChild;
  }
  //parent.left = leftChild.right;
  Aff_FG(parent,FD(leftChild));
  FD(leftChild)= parent;
  return grandParent;
}

/**
 * Time complexity: O(n)
 */
 /*
void createPerfectBST(TNoeud**root) {
  int n = 0;
  TNoeud*tmp=*root;
  for ( tmp = *root;tmp!=NULL; tmp = FD(tmp)) {
    n++;
  }

  //m = 2^floor[lg(n+1)]-1, ie the greatest power of 2 less than n: minus 1
  int m = greatestPowerOf2LessThanN(n + 1) - 1;
  makeRotations(n - m);

  while (m > 1) {
    makeRotations(m /= 2);
  }
}

/**
 * Time complexity: log(n)
 */
 /*
int greatestPowerOf2LessThanN(int n) {
  int x = MSB(n);//MSB
  return (1 << x);//2^x
}

/**
 * Time complexity: log(n)
 * return the index of most significant set bit: index of
 * least significant bit is 0
 */
/*
int MSB(int n) {
  int ndx = 0;
  while (1 < n) {
    n = (n >> 1);
    ndx++;
  }
  return ndx;
}

void makeRotations(int bound) {
  TNoeud*root ;
  TNoeud *grandParent = NULL;
  TNoeud* parent = root;
  TNoeud* child = FD(root);
  for (bound > 0; bound--;) {
    //try {
      if (child!=NULL) {
        rotateLeft(grandParent, parent, child);
        grandParent = child;
        parent = FD(grandParent);
        child = FD(parent);
      } //else {
       // break;
     // }
    //} catch (NullPointerException convenient) {
    //  break;
    //}
  }
}

void rotateLeft(TNoeud* grandParent, TNoeud* parent, TNoeud* rightChild) {
    TNoeud*root;
  if (grandParent !=NULL) {
   // FD(grandParent) = rightChild;
    Aff_FD(grandParent,rightChild);
  } else {
    root = rightChild;
  }
  //parent.right = rightChild.left;
  Aff_FD(parent,FG(rightChild));
  Aff_FG(rightChild,parent);
  //FG(rightChild) = parent;
}


 void DSW2(TNoeud **root) {
  if (null != *root) {
    createBackbone(root);// effectively: createBackbone( root)
    createPerfectBST(root);//effectively: createPerfectBST( root)
  }
}

*/



/**=========================== Recherche ==============================**/
/**    Rechercher une valeur dans une Arbre de Recherche Binaire
/**=====================================================================**/
void Recherche(int V, TNoeud *Racine, TNoeud **Pere, TNoeud **P)
{
    int trouve=0;
    *P=Racine;
    *Pere=NULL;
     while ( *P!=NULL && !trouve)
     {
         if (Info(*P) == V) {trouve = 1;}
            else
            {
                *Pere=*P;
                if (Info(*P) < V) {*P=FD(*P);}
                else {*P=FG(*P);}
            }
     }
}

/**=========================== UpdateHauteur =================================**/
/**    metre à jour le champs Hauteur dans un arbre R
/**===========================================================================**/
void UpdateHauteur(TNoeud *R)
{
    int a,b;
    if (R != NULL)
    {
        UpdateHauteur(FG(R));
        UpdateHauteur(FD(R));
        if (FG(R) == NULL) {a=-1;}
        else {a=Hauteur(FG(R));}
        if (FD(R) == NULL ){b=-1;}
        else {b= Hauteur(FD(R));}
        a=Max (a,b);
        Aff_Hauteur(R,a+1);
    }
}

/**=========================== Inserer =================================**/
/**    Inserer une valeur dans une Arbre de Recherche Binaire
/**=====================================================================**/
void Inserer(int V, TNoeud **Racine)
{
    TNoeud * Pere=NULL,*P=NULL;
    Recherche(V,*Racine,&Pere,&P);
    if (P == NULL)
    {
        P=CreerNoeud(V);
        if (*Racine == NULL) {*Racine=P;}
        else
        {
            if (V> Info(Pere)){Aff_FD(Pere,P);}
            else {Aff_FG(Pere,P);}
        }
        UpdateHauteur(*Racine); // Metre à jour JUSTE le champs Hauteur (SANS EQUILIBRAGE)
    }
}

/**=============================== Cvrt_TabABR =================================**/
/**    Construire un arbre binaire de recherche de racine "R" avec les elements
/**                     du tableau "Tab" du taille "m"
/**=============================================================================**/
void Cvrt_TabABR (TNoeud ** R,int *Tab,int m)
{
    int i;
    for (i=0; i<m; i++)
    {
        Inserer(Tab[i], &*R);
    }
}


/**=============================== RandTab =========================================**/
/**   Remplir un tableau "Tab" du taille "m" avc des valeur aleéatoire entre 0 et 100
/**=================================================================================**/
void RandTab (int *Tab,int m)
{
    int i,Sup=100,Inf=0,A;
    for (i=0; i<m; i++)
    {
        A=(rand() % (Sup-Inf+1))+Inf;
        Tab[i]=A;
    }
}

/*************** Le Max entre a et B ***************/
int Max (int a, int b)
{
    if (a<b) {return (b);}
    else {return (a);}
}

/*************** La valeur absolue ***************/
int abs(int x)
{
    if (x>= 0){return x;}
    else {return (-x);}
}

/**=============================== BienEqu ===============================**/
/**   Retourne un 1 si l'arbre "R" est bien équilibré et "0" sinon
/**=======================================================================**/
int bienEqu(TNoeud *R)
{
    int a,b;
    if (R == NULL ) {return 1;}
    else
    {
        if (FG(R) == NULL) {a=-1;}
        else {a=Hauteur(FG(R));}
        if (FD(R) == NULL ){b=-1;}
        else {b= Hauteur(FD(R));}
        if (abs(a-b) > 1) {return 0;}
        else
        {
            a=bienEqu(FD(R));
            b=bienEqu(FG(R));
            if (a == 1 && b == 1) {return 1;}
            else {return 0;}
        }
    }
}

/**=============================== LibereARB ===============================**/
/**                Liberer l'espace mémoire occupé par un arbre
/**=======================================================================**/
void LibereARB(TNoeud**R)
{
    TNoeud *p,*q;
    if (*R != NULL)
    {
        if (feuille (*R)) {LibererNoeud(*R);}
        else
        {
            p=FD(*R);
            q=FG(*R);
            LibereARB(&p);
            LibereARB(&q);
            LibererNoeud(*R);
        }
    }
}

/**======================================== DSW ALGORITHME  =============================================**/


/**=============================== Rotation Gauche  ===============================**/
/**  Faire une rotation Gauche sur le Noeud n et retourne le nouveau noeud
/**                        qui va prendre sa place
/**==============================================================================**/
TNoeud *RotationGauche (TNoeud *n)
{
    TNoeud*fild;
    int temp =Info(n);
    if (FD(n)!=NULL) {
            fild=FD(n);
            Aff_FD(n,FD(fild));
            Aff_FD(fild,FG(fild));
            Aff_FG(fild,FG(n));
            Aff_FG(n,fild);
            Aff_info(n,Info(fild));
            Aff_info(fild,temp);

    }
    return n;
}

/**=============================== Rotation Droite  ===============================**/
/**  Faire une rotation Droite sur le Noeud n et retourne le nouveau noeud
/**                        qui va prendre sa place
/**==============================================================================**/
TNoeud *RotationDroite (TNoeud *n)
{
    TNoeud*filg;   int temp =Info(n);
    if (FG(n)!=NULL) {

            filg=FG(n);
            Aff_FG(n,FG(filg));
            Aff_FG(filg,FD(filg));
             Aff_FD(filg,FD(n));
             Aff_FD(n,filg);
            Aff_info(n,Info(filg));
            Aff_info(filg,temp);
    }
    return n;
}

/**========================= Creation une Branche droite ========================**/
/**        Transformer un arbre "R" en une seule branche droite
/**==============================================================================**/
TNoeud * CreationDrVine (TNoeud*root,int *cmpt,int *VisitN2)
{
    while (FG(root) != NULL)
    {
        root=RotationDroite(root);
        *cmpt=*cmpt+1;
         *VisitN2=*VisitN2+1;
    }
 if (FD(root)!= NULL) { Aff_FD(root,CreationDrVine(FD(root),cmpt,VisitN2)) ;   }

    return root;

}

/**========================= Compter les Noeud  ========================================**/
/**      retourne le nombre des neoud dans un arbre "R" construit d'une seule branche droite
/**=====================================================================================**/
int ComptNoeud(TNoeud * root)
{
    if (root==NULL)
    {
        return 0 ;
    }
    int i=1;
    while (FD(root) !=NULL ) {root=FD(root); i++; }
    return i;

}

/**========================= Balancer une Branche  ========================**/
/**      equilibrer un arbre construit d'une seule branche droite
/**     en retournant des compteurs de rotations et noeuds visitées
/**====================================================================**/
TNoeud * BalanceVine (TNoeud *root , int Comp,int *cmpt2,int *VisitN)
{   int i;
    *cmpt2=0;
    *VisitN=0;
    double times; int timesI;
    times = log(Comp)/log(2);
    timesI =(int)times;
    TNoeud*newroot=root;
    int j;

    for (i=0;i<timesI;i++)
    {
     newroot = RotationGauche(newroot);
     *VisitN=*VisitN+2;
     *cmpt2=*cmpt2+1;
     root=FD(newroot);

     for (j=0;j<Comp/2 - 1;j++)
     {
         root = RotationGauche(root);
         *cmpt2 =*cmpt2+1;
         root =FD(root);
         *VisitN=*VisitN+2;
     } Comp >>=1;

    } return newroot;
}

/**========================= DSW ========================**/
/**      Equilibrer un arbre "R" par la méthode DSW
/**           en retournant des compteurs
/**======================================================**/
void DSW (TNoeud **R,int *cmpt,int *NoeudVisit)
{
    int N,B,Comp;
    *R=CreationDrVine(*R,cmpt,NoeudVisit); // D'abord on transforme l'arbre à une seule branche
    Comp=ComptNoeud(*R);
    N= *cmpt; // on sauvgarde le nombe des rotations effectuées dans cette étape
     B= *NoeudVisit + Comp; // le nombre des noeuds visitées aussi
    *R=BalanceVine(*R,Comp,cmpt,NoeudVisit); // on équilibre la branche
    * NoeudVisit = *NoeudVisit + B ; // on rajoute le nombre des rotations et noeuds visitées dans cette étape
    *cmpt=*cmpt+N;

}
