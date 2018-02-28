/*
** main.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Mon Jan  8 14:13:37 2018 CASTELLARNAU Aurelien
** Last update Mon Jan 15 16:50:06 2018 BILLAUD Jean
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_malloc.h"

int		main() {
  int		size;
  char		*test;
  int		i;
  int		limit;

  i = 0;
  limit = 3000;
  size = 3000;
  test = malloc(sizeof (char) * size + 1);
  while (i < limit)
    {
     test[i] = 'a';
     i++;
   }
  test[i] = '\0';
  free(test);
  return (0);
}
