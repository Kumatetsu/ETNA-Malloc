/*
** my_calloc.c for Malloc in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Jan 13 15:10:06 2018 BILLAUD Jean
** Last update Sat Jan 13 17:01:39 2018 BILLAUD Jean
*/

#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"

void		*calloc(size_t num_elements, size_t size)
{
  void		*recipe;
  char		*address;
  size_t	i;

  if (0 == size)
    return NULL;

  recipe = malloc(num_elements * size);
  address = recipe;
  for (i = 0; i < num_elements * size ; i++)
    *address = 0;
  return (recipe);
}
