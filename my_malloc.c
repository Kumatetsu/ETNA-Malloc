/*
** my_malloc.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 05:54:25 2018 CASTELLARNAU Aurelien
** Last update Sun Jan 14 14:38:22 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"

/*
** malloc is the central call to allocation logic
*/
void            *malloc(size_t size)
{
  t_bc		*bc;
  t_block       *space;

  if (0 == size)
    return NULL;
  
  bc = get_bc();
  add_block(&bc, size);
  space = bc->last;
  return (space + 1);
}

/*
** free is the central call for free logic
*/
void            free(void *ptr)
{
  t_block       *b;
  
  if (ptr != NULL)
    {
      b = (((t_block *)ptr) - 1);
      b->space = FREE;
    }
}
