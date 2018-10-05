#include <stdio.h>
#include <stdlib.h>
#include "Modele_TP2.h"



/*void entrer ()
{
    system("mode con LINES=300 COLS=152");
    system("COLOR 0F");
    gotoxy(40,15);
    printf(" A");Sleep(100);
    printf("B");Sleep(100);
    printf("O");Sleep(100);
    printf("U");Sleep(100);
    printf("C");Sleep(100);
    printf("H");Sleep(100);
    printf("A");Sleep(100);
    printf("M");Sleep(100);
    printf("A");Sleep(100);
    printf("L");Sleep(100);
    printf("A");Sleep(100);
    printf(" H");Sleep(100);
    printf("O");Sleep(100);
    printf("U");Sleep(100);
    printf("D");Sleep(100);
    printf("A");Sleep(100);
    printf(" & ");Sleep(100);
    printf("D");Sleep(100);
    printf("J");Sleep(100);
    printf("E");Sleep(100);
    printf("D");Sleep(100);
    printf("D");Sleep(100);
    printf("A");Sleep(100);
    printf("L");Sleep(100);
    printf(" H");Sleep(100);
    printf("A");Sleep(100);
    printf("N");Sleep(100);
    printf("A");Sleep(100);
    printf("N");Sleep(100);
    printf("E");Sleep(100);
    printf(" V");Sleep(100);
    printf("O");Sleep(100);
    printf("U");Sleep(100);
    printf("S");Sleep(100);
    printf(" P");Sleep(100);
    printf("R");Sleep(100);
    printf("E");Sleep(100);
    printf("S");Sleep(100);
    printf("E");Sleep(100);
    printf("N");Sleep(100);
    printf("T");Sleep(100);
    printf("E");Sleep(100);
    printf("N");Sleep(100);
    printf("T ");Sleep(100);
    printf(".");Sleep(100);printf(".");Sleep(100);printf(".");Sleep(100);
    printf("\n");
   system("cls");
   textcolor (4) ;textbackground (0);
  printf("                     o o\n");
  printf("                      *\n");Sleep(200);
  system("cls");textcolor (12) ;
  printf("\n\n");
  printf("                     o o\n");
  printf("                      ^\n");Sleep(200);
  system("cls");textcolor (14) ;
  printf("\n\n\n");
  printf("                     o o\n");
  printf("                      o\n");Sleep(200);
  system("cls");textcolor (10) ;
  printf("\n\n\n\n");
  printf("                     o o\n");
  printf("                      *\n");Sleep(200);
  system("cls"); textcolor (13) ;
  printf("\n\n\n\n\n\n");
  printf("                     o o\n");
  printf("                      -\n");Sleep(200);
  system("cls"); textcolor (11) ;
  printf("\n\n\n\n\n\n\n\n");
  printf("                     o o\n");
  printf("                      ~\n");Sleep(200);
  system("cls");textcolor (3) ;
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("                     o o\n");
  printf("                      v");Sleep(200);
  system("cls");textcolor (5) ;
  printf("\n\n");
printf(" ------------------------------------------------------------------------------\n");textcolor (4);
//printf(" 같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같\n");

printf("|                                 ('-.    .-')                                 |\n");textcolor (4);
printf("|                                _(  OO)  ( OO ).                              |\n");textcolor (4);
printf("|                               (,------.(_)---(_)  ,-.-')                     |\n");textcolor (12);
printf("|                                |  .---'/    _ |   |  |OO)                    |\n");textcolor (12);
printf("|                                |  |    (  :` `.   |  |  |                    |\n");textcolor (14);
printf("|                               (|  '--.  '..`''.)  |  |(_/                    |\n");textcolor (14);
printf("|                                |  .--' .-._)   | ,|  |_.'                    |\n");textcolor (10);
printf("|                                |  `---.(       |                             |\n");textcolor (10);
printf("|                                `------' `-----'   `--'                       |\n");textcolor (2);
printf("|                _   _     _                                                   |\n");textcolor (11);
printf("|               /  /     /                                                     |\n");textcolor (11);
printf("|              ( T ( P ) ( 1 )                                                 |\n");textcolor (3);
printf("|                                                                              |\n");textcolor (3);
printf("|                                                                              |\n");textcolor (1);
printf("|                                                                              |\n");textcolor (5);
printf("|              ( W ( e ( l ( c ( o ( m ( e )                G:1 Sec:A          |\n");textcolor (5);
printf("|                _/  _/  _/  _/  _/  _/  _/                 Annee 2015/2016    |\n");textcolor (13);
printf(" ------------------------------------------------------------------------------");textcolor (13);
    gotoxy(10,25);
    AccessMenu();
    system("cls");
    system("COLOR 0F");
    textbackground(0);
    textcolor (15) ;
}
void entete ()
{
    int i ;
    gotoxy(50,1);
    printf("REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE ");
    gotoxy(55,3);
    printf("ECOLE SUPERIEURE D'INFORMATIQUE (ESI)\n");
    for (i=1 ; i <= 152 ; i++) printf("_");
    printf("\n") ;
}

void pied_de_page ()
{
    int i ;
    gotoxy(1,35);
    for (i=1 ; i <= 152 ; i++) printf("_");
    gotoxy(70,37);
    printf("REALISE PAR:");
    gotoxy(56,39);
    printf("ABOUCHAMALA HOUDA   |   DJEDDAL HANANE");
    gotoxy(63,41);
    printf("SECTION A   |   GROUPE 1");
    gotoxy(70,43);
    printf("ENCADRE PAR:");
    gotoxy(64,45);
    printf("Dr.BOULAKRADECHE Mohamed");
    gotoxy(61,47);
    printf("ANNEE UNIVERSITAIRE : 2015/2016\n");
    for (i=1 ; i <= 152 ; i++) printf("_");

}


*/
int main()
{

    int  m=0,n=0,i,nbrR=0,nbrNoeud=0,NbrAE=0,NbrANE=0;
    int *Tab=NULL;
    int y,w;
    FILE*fichier;
    TNoeud *R1=NULL,*R2=NULL ,*R3=NULL;
    printf(" Donner le nombre des donnees : ");
    scanf("%d",&m);
    Tab=malloc((m)*sizeof (int));
    printf(" Donner N : ");
    scanf("%d",&n);
    fichier=fopen("text.txt","w");
    for (i=0 ;i<n ;i++)
    {
        RandTab(Tab,m);
        Cvrt_TabABR(&R1,Tab,m); // construction de ABR a partir du Tab
        affiche_arbre(R1,60,2,20);

        //R3=CreationDrVine(R3,&y,&w);
        //affiche_arbre(R3,60,2,20);
        //printf("\n\n\n\n\n\n");

        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        //Inordre(R1);
        retourMenu();

        system("cls");
        DSW(&R1,&nbrR,&nbrNoeud);
        UpdateHauteur(R1);
        if (bienEqu(R1)) {NbrAE ++;}
        else {NbrANE ++;}
        if (fichier != NULL)
       {   fseek(fichier, 0, SEEK_END);
              fprintf(fichier, "  %d  ",nbrR);
              fprintf(fichier, "  %d  ",nbrNoeud);
              fprintf(fichier, "  %d  ",NbrAE);
              fprintf(fichier, " %d  \n",NbrANE);
          //  fprintf(fichier, " %d \n", B);
        }
       //  fclose(fichier);
        //affiche_arbre(R1,70,2,50);
        printf("\n\n\n\n\n herreeeee %d \n\n\n\n\n %d \n\n\n\n\n",nbrR,nbrNoeud);
        printf("\n\n\n\n %d \n\n\n ", bienEqu(R1));
        //Cvrt_TabABR(R2,Tab,m);
        //retourMenu();
        //system("cls");
        //Inordre(R1);
        LibereARB(&R1);
        retourMenu();
        system("cls");
        R1=NULL;
    }
    return 0;
}
