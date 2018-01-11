/*
** my_malloc.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 05:54:25 2018 CASTELLARNAU Aurelien
** Last update Thu Jan 11 22:12:07 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "chunk.h"
#include "my_malloc.h"
/*
** my_simple_malloc is the central call to allocation logic
*/
void            *malloc(size_t size)
{
  t_bc		*bc;
  t_block       *space;
  
  bc = get_bc();
  write(1, "ok", 3);
  add_block(&bc, size);
  space = bc->last;
  return (space + 1);
}

/*
** my_simple_free is the central call for free logic
*/
void            free(void *ptr)
{
  t_block       *b;

  b = (((t_block *)ptr) - 1);
  b->space = FREE;
}

/*test*/
