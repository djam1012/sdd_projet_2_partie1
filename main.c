#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu() {
   printf("\e[1;96m");
   printf("---Menu---\n\n");
   printf("(0): sortie du programme\n");
   printf("(1): Affichage d'une bibliothèque\n");
   printf("(2): Recherche d'un ouvrage par son numéro\n");
   printf("(3): Recherche d'un ouvrage par son titre\n");
   printf("(4): Recherche de tous les livres d'un même auteur\n");
   printf("(5): Suppression d'un ouvrage\n");
   printf("(6): Fusion de deux bibliothèques en ajoutant la deuxième bibliothèque à la première et en supprimant la deuxième\n");
   printf("(7): Recherche de tous les ouvrages avec plusieurs exemplaires\n\n\n");
   printf("\n Votre choix ? \n\n");
   printf("\e[0;37m");
}

int main(int argc, char *argv[]){
  if (argc!=3){
    printf("Il faut un seul fichier d'entrée et un seul entier > 0.\n");
    return 1;
  }
  if (atoi(argv[2])==0){
    printf("Il faut charger au moins une entrée.\n");
    return 1;
  }
  Biblio* b1 = charger_n_entrees(argv[1], atoi(argv[2]));
  enregistrer_biblio(b1, "Biblio_rangee.txt");


///////////////////////////////////////////////////////////

  Biblio* bib = creer_biblio();
  inserer_en_tete(bib, 102222, "livre1", "auteur1");
  inserer_en_tete(bib, 102223, "livre2", "auteur2");
  inserer_en_tete(bib, 102224, "livre3", "auteur1");
  inserer_en_tete(bib, 102225, "livre4", "auteur2");
  inserer_en_tete(bib, 102226, "livre5", "auteur1");
  inserer_en_tete(bib, 102227, "livre6", "auteur1");
  inserer_en_tete(bib, 102228, "livre7", "auteur1");
  inserer_en_tete(bib, 102229, "1984", "Orwell");
  inserer_en_tete(bib, 102230, "1984", "Orwell");
  inserer_en_tete(bib, 102231, "1984", "Orwell");
  inserer_en_tete(bib, 102232, "1984", "Orwell");
  inserer_en_tete(bib, 102233, "1984", "Orwell");

  Livre* livre=creer_livre(102234, "un_titre", "un_auteur");

  printf("bibliothèque b1: \n\n");
  afficher_biblio(b1);
  printf("bibliothèque bib: \n\n");
  afficher_biblio(bib);

  int choix_int;
  do{
    char choix[20];
    Menu();
    fgets(choix, 20, stdin);
    choix_int = atoi(choix);
    switch(choix_int){
       case 1:
          printf("Affichage d'une bibliothèque : \n");
          printf("\e[1;92m");
          afficher_biblio(b1);
          printf("\x1b[0m");
          break;
       case 2:
          printf("Recherche d'un ouvrage par son numéro \n");
          printf("Veuillez taper le numéro de l'ouvrage \n");
          char num[256];
          fgets(num,256,stdin);
          printf("\e[1;92m");
          recherche_ouvrage_num(b1,atoi(num));
          printf("\x1b[0m");
          break;
       case 3:
          printf("Recherche d'un ouvrage par son titre \n");
          printf("Veuillez taper le titre de l'ouvrage \n");
          char titre[256];
          char lire_stdin[256];
          fgets(lire_stdin,256,stdin);
          if (sscanf(lire_stdin,"%s",titre)==1){
            printf("\e[1;92m");
            recherche_ouvrage_titre(b1,titre);
            printf("\x1b[0m");
          } else printf("Voter entrée est invalide\n");
          break;
       case 4:
          printf("Recherche de tous les livres d'un même auteur \n");
          printf("Merci d'entrer le nom de l'auteur \n");
          char nom[256];
          char lire_stdin_2[256];
          fgets(lire_stdin_2,256,stdin);
          if (sscanf(lire_stdin_2,"%s",nom)==1){
            printf("\e[1;92m");
            recherche_ouvrage_auteur(b1,nom);
            printf("\x1b[0m");
          } else printf("Votre entrée est invalide\n");
          break;
       case 5:
          printf("Suppression d'un ouvrage \n");
          printf("Merci d'entrer le numéro,l'auteur et le titre de l'ouvrage à supprimer.\n");
          char numero[256];
          char title[256];
          char auteur[256];
          char lire_stdin_3[256];
          fgets(lire_stdin_3,256,stdin);
          if (sscanf(lire_stdin_3,"%s %s %s",numero, title, auteur)==3){
            supprimer_ouvrage(b1,atoi(numero),title,auteur);
            printf("L'ouvrage a bien été supprimé.\n");
          } else printf("Votre entrée est invalide\n");
          break;
       case 6:
          printf("Fusion de deux bibliothèques \n");
          fusion_biblio(b1,bib);
          break;
       case 7:
          printf("Recherche de tous les ouvrages avec plusieurs exemplaires \n");
          printf("\e[1;92m");
          Biblio* exemplaires=afficher_exemplaires(b1);
          afficher_biblio(exemplaires);
          liberer_biblio(exemplaires);
          free(exemplaires);
          printf("\x1b[0m");
          break;

       default:
          printf("\e[1;33m");
          printf("Merci d'avoir utilisé nos services, à bientôt !\n");
          printf("\x1b[0m");
          break;
      }
    } while(choix_int);

  liberer_livre(livre);
  liberer_biblio(b1);
  free(b1);  // on libère le pointeur sur bibliothèque
  liberer_biblio(bib);
  free(bib);
  return 0;
}
