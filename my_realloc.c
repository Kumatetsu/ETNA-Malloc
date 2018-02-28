/*
** my_realloc.c for Malloc in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Jan 14 14:25:04 2018 BILLAUD Jean
** Last update Sun Jan 14 15:57:01 2018 BILLAUD Jean
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"

/*
** check if the block is large enough for the requested memory
** if not malloc a new block and copy the first one in this new.
*/
void		*realloc(void *ptr, size_t size)
{
  void		*new;
  t_block	*current;
  
  if (NULL == ptr)
    return malloc(size);

  if (0 == size)
    {
      free(ptr);
      return NULL;
    }

  current = (((t_block *)ptr) - 1);
  if (current->size >= size)
    return (ptr);
  
  new = malloc(size);
  memcpy(new, ptr, size);
  free(ptr);
  
  return (new);
}
