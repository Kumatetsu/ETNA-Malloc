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
#include <unistd.h>
#include <stdlib.h>

void *my_dummy_malloc(unsigned int size) {
  return (sbrk((intptr_t) size));
}

typedef struct		s_block
{
  struct s_block	*next;
  unsigned int		size;
}			t_block;

// static t_block *available_list = NULL;
// static t_block *free_list = NULL;

void		my_simple_free(void *ptr)
{
  t_block	*b;

  b = (((t_block*)ptr) - 1);
  printf("block to free address: %p\n", b);
  printf("allocated size: %d\n", b->size);
  printf("space to free address: %p\n", b + 1);
}

void		*my_simple_malloc(unsigned int size) {
  t_block	*b;
  
  b = sbrk((intptr_t)(sizeof(*b) + size));
  b->size = size;
  printf("allocated size: %d\n", b->size);
  printf("block adress: %p\n", b);
  printf("size of b: %lu\n", sizeof (*b));
  printf("size of t_block: %lu\n", sizeof (t_block));
  printf("returned address: %p\n", b + 1);
  return (b + 1);
}

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
