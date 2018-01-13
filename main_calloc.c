/*
** main_calloc.c for Malloc in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Jan 13 15:46:42 2018 BILLAUD Jean
** Last update Sat Jan 13 16:04:12 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_calloc.h"

int	main()
{
  int	size;
  char *maChaine;

  maChaine = calloc(15, sizeof(char));

  if (maChaine == NULL) {
    exit(1);
  }
  write(1, "in callooooc\n", 13);
  for (size = 0; size < 15; size ++)
    printf("%d", maChaine[size]);
  return 1;
}
