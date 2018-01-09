/*
** main.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Mon Jan  8 14:13:37 2018 CASTELLARNAU Aurelien
** Last update Mon Jan  8 14:14:24 2018 CASTELLARNAU Aurelien
*/

#include "libmy.h"
#include "blockchain.h"
#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char *av[]) {
  int		size;
  char		*test;
  int		i;
  int		limit;

  i = 0;
  limit = 5000;
  size = 1;
  printf("arguments: %s, %s, %s\n", av[0], av[1], av[2]);
  if (ac >= 2 && !my_strcmp(av[1], "-alloc"))
    {
      size = my_getnbr(av[2]);
    }
  test = my_simple_malloc(sizeof (char) * size + 1);
  printf("test address: %p\n", test);
  printf("asked size: %d\n", size); 
  while (i < limit)
    {
      test[i] = 'a';
      i++;
    }
  test[i] = '\0';
  printf("size of test: %d", i);
  printf("Test:\n%s\n", test);
  my_simple_free(test);
  return (0);
}
