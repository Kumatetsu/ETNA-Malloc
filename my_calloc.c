/*
** my_calloc.c for Malloc in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Jan 13 15:10:06 2018 BILLAUD Jean
** Last update Sun Jan 14 15:44:40 2018 BILLAUD Jean
*/

#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"


/*
** Calloc allocate memory
** and init it with the value 0 
 */
void		*calloc(size_t num_elements, size_t size)
{
  void		*recipe;
  char		*address;
  size_t	i;

  if (0 == size)
    return NULL;

  recipe = malloc(num_elements * size);
  if (NULL == recipe)
    return NULL;
  address = recipe;
  for (i = 0; i < num_elements * size ; i++)
    *address = 0;
  return (recipe);
}
