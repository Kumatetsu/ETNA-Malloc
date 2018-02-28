/*
** main_realloc.c for billau_j in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Mon Jan 15 16:58:10 2018 BILLAUD Jean
** Last update Mon Jan 15 17:11:20 2018 BILLAUD Jean
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_realloc.h"
#include "my_calloc.h"
#include "my_malloc.h"

void pb_memoire(void)
{
  write(1, "ERREUR : probleme de memoire !\n", 34);
  exit(1);
}

int main()
{
  char *test;
  char *copie_test;
  /* 15 ou plus probablement la valeur d'une variable. */
  int i;

  test = malloc(15 * sizeof(char));
  copie_test = NULL;
  if (test == NULL)
    pb_memoire();
  for (i=0; i<15; ++i)
    test[i] = 0; // On met tout à zéro, ce que fait calloc().
  //quelques instructions

  copie_test = malloc(15 * sizeof(char));
  if (copie_test == NULL)
    pb_memoire();

  for (i = 0; i < 15; i++)
    copie_test[i] = test[i]; // On enregistre les données pour ne pas les perdre.

  free(test); // On libére la zone mémoire avant d'en acquérir une nouvelle.
  test = malloc(20 * sizeof(char)); // On demande plus de place en mémoire.

  if (test == NULL)
    pb_memoire();

  for (i = 0; i < 15; i++)
    test[i] = copie_test[i]; // On récupère les valeurs qu'on a sauvegardées.
  free(copie_test); // On peut maintenant supprimer les données sauvegardées.

  //quelques instructions
  free(test); // On n'oublie pas de libérer la mémoire à la fin du programme ou de la fonction.
  write(1, "tout est bien kifinibien\n", 27);
  return 0;
}
