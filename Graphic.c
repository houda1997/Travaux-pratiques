#include "Graphic.h"

/**========================= Retourner au Menu ========================**/
void retourMenu() // Affiche un message pour retourner au menu
{
    printf("APPUYEZ SUR N'IMPORTE QUELLE TOUCHE POUR RETOURNER AU MENU!\n");
    getch();
}

//********************** feuille ****************************//
int feuille (TNoeud *R)
{
    if (FG(R) == NULL && FD(R) == NULL) {return 1;}
    else {return 0;}
}

//********************** Interface ****************************//
void cadre (int x , int y , TNoeud* N)
{
    gotoxy(x,y);
    printf("%c",193);
    gotoxy(x-1,y);
    printf("%c",196);
    gotoxy(x+1,y);
    printf("%c",196);
    gotoxy(x-2,y);
    printf("%c",196);
    gotoxy(x+2,y);
    printf("%c",196);
    gotoxy(x-3,y);
    printf("%c",196);
    gotoxy(x+3,y);
    printf("%c",196);
    gotoxy(x-4,y);
    printf("%c",218);
    gotoxy(x+4,y);
    printf("%c",191);
    gotoxy(x-4,y+1);
    printf("|");
    gotoxy(x+4,y+1);
    printf("|");
    gotoxy(x-4,y+2);
    printf("%c",192);
    gotoxy(x+4,y+2);
    printf("%c",217);
    gotoxy(x-1,y+2);
    printf("%c",196);
    gotoxy(x+1,y+2);
    printf("%c",196);
    gotoxy(x-2,y+2);
    printf("%c",196);
    gotoxy(x+2,y+2);
    printf("%c",196);
    gotoxy(x-3,y+2);
    printf("%c",196);
    gotoxy(x+3,y+2);
    printf("%c",196);
    gotoxy(x,y+2);
    if (feuille(N))printf("%c",196);
    else printf("%c",194);
    gotoxy(x-3,y+1);
    printf("%4d",Info(N));
}
/*-------------------------------------------------*/
void aff_branche1(int l , int x , int y )
{
    int i ;
    gotoxy(x,y);
    printf("|");
    gotoxy(x,y+1);
    printf("%c",193);

    for(i=1 ; i < l ;i++)
    {   gotoxy(x+i,y+1);
        printf("%c",196);
        gotoxy(x-i,y+1);
        printf("%c",196);
    }
    gotoxy(x+l,y+1);
    printf("%c",191);
    gotoxy(x-l,y+1);
    printf("%c",218);

    gotoxy(x+l,y+2);
    printf("|");
    gotoxy(x-l,y+2);
    printf("|");
}


/*===============================================================================================*/
void aff_branche_gauche(int l , int x , int y )
{
    int i ;
    gotoxy(x,y);
    printf("|");
    gotoxy(x,y+1);
    printf("%c",217);

    for(i=1 ; i < l ;i++)
    {
        gotoxy(x-i,y+1);
        printf("%c",196);
    }
    gotoxy(x-l,y+1);
    printf("%c",218);

    gotoxy(x-l,y+2);
    printf("|");

}

/*===============================================================================================*/
void aff_branche_droite(int l , int x , int y )
{
    int i ;
    gotoxy(x,y);
    printf("|");
    gotoxy(x,y+1);
    printf("%c",192);

    for(i=1 ; i < l ;i++)
    {   gotoxy(x+i,y+1);
        printf("%c",196);
    }
    gotoxy(x+l,y+1);
    printf("%c",191);

    gotoxy(x+l,y+2);
    printf("|");

}

/*=======================================================================================*/
void affiche_arbre(TNoeud *R,int x , int y , int l)
{
  if ( R != NULL)
  {
      cadre(x,y,R);
      if (FG(R) != NULL && FD (R) != NULL) aff_branche1(l,x,y+3);
      else if (FG(R) == NULL && FD (R) != NULL) aff_branche_droite(l,x,y+3);
      else if (FG(R) != NULL && FD (R) == NULL) aff_branche_gauche(l,x,y+3);

      affiche_arbre(FG(R),x-l,y+5,l/2);
      affiche_arbre(FD(R),x+l,y+5,l/2);
  }

}
