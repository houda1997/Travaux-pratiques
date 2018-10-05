
/*
 *
 * Implementation : module noeud
 * ESI / 1cpi / 22-05-2010
 *
 */

#include "noeud.h"

#include <stdlib.h>	// pour malloc, exit ...


// Allouer un noeud avec comme info la valeur v
TNoeud *CreerNoeud( int v )
{
   TNoeud *p = malloc( sizeof(TNoeud) );
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   p->Info = v;
   p->FG = NULL;
   p->FD = NULL;
   p->Hauteur=0;

   return p;
}


// Destruction du noeud p
void LibererNoeud( TNoeud *p )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   free( p );
}


// Affecte v dans le noeud p
void Aff_info( TNoeud *p, TVal v )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   p->Info = v;
}


// Affecte q dans le fils-gauche de p
void Aff_FG( TNoeud *p, TNoeud *q )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   p->FG = q;
}


// Affecte q dans le fils-droit de p
void Aff_FD( TNoeud *p, TNoeud *q )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   p->FD = q;
}


// Retourne l'information de p
TVal Info( TNoeud *p )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   return p->Info;
}


// Retourne le fils-gauche de p
TNoeud *FG( TNoeud *p )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   return p->FG;
}


// Retourne le fils-droit de p
TNoeud *FD( TNoeud *p )
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   return p->FD;
}

int Hauteur (TNoeud *p)
{
    if ( p == NULL )
	   exit( EXIT_FAILURE );

   return p->Hauteur;
}

void Aff_Hauteur(TNoeud *p, int h)
{
   if ( p == NULL )
	   exit( EXIT_FAILURE );

   p->Hauteur = h;
}
