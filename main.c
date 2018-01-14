/*
** main.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Mon Jan  8 14:13:37 2018 CASTELLARNAU Aurelien
** Last update Thu Jan 11 21:27:10 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "my_malloc.h"

int		main(int ac, char *av[]) {
  int		size;
  char		*test;
  int		i;
  int		limit;

  i = 0;
  limit = 5000;
  size = 1;
  if (ac >= 2 && !my_strcmp(av[1], "-alloc"))
    {
      size = my_getnbr(av[2]);
    }
  test = malloc(sizeof (char) * size + 1);
  while (i < limit)
    {
     test[i] = 'a';
     i++;
   }
  test[i] = '\0';
  my_simple_free(test);
  return (0);
}
