/*
 *
 * Entete : module noeud
 * ESI / 1cpi / 22-05-2010
 *
 */


// Information du noeud
typedef int TVal;

// Noeud de l'arbre
typedef struct noeud {
		TVal Info;
		int Hauteur;
		struct noeud *FG;
		struct noeud *FD;
	} TNoeud;

// Allouer un noeud avec comme info la valeur v
TNoeud *CreerNoeud( int v );

// Destruction du noeud p
void LibererNoeud( TNoeud *p );

// Affecte v dans le noeud p
void Aff_info( TNoeud *p, TVal v );

// Affecte q dans le fils-gauche de p
void Aff_FG( TNoeud *p, TNoeud *q );

// Affecte q dans le fils-droit de p
void Aff_FD( TNoeud *p, TNoeud *q );

// Retourne l'information de p
TVal Info( TNoeud *p );

// Retourne le fils-gauche de p
TNoeud *FG( TNoeud *p );

// Retourne le fils-droit de p
TNoeud *FD( TNoeud *p );

// Retourne l'Hauteur de p
int Hauteur (TNoeud *p);

// Affecte h dans l'hauteur de p
void Aff_Hauteur(TNoeud *p, int h);
