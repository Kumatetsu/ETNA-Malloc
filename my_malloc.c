/*
** my_malloc.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 05:54:25 2018 CASTELLARNAU Aurelien
** Last update Wed Jan 10 05:55:54 2018 CASTELLARNAU Aurelien
*/

#include "blockchain.h"
#include "chunk.h"
#include "my_malloc.h"
#include <unistd.h>
#include <stdio.h>

/*
** my_simple_malloc is the central call to allocation logic
*/
void            *my_simple_malloc(unsigned int size)
{
  t_bc		*bc;
  t_block       *space;
  
  bc = get_bc();
  add_block_with_chunks(&bc, size);
  space = bc->last;
  printf("allocated size: %d\n", size);
  printf("block adress: %p\n", space);
  printf("size of b: %lu\n", sizeof (*space));
  printf("size of t_block: %lu\n", sizeof (t_block));
  printf("returned address: %p\n", space + 1);
  return (space + 1);
}

/*
** my_simple_free is the central call for free logic
*/
void            my_simple_free(void *ptr)
{
  t_block       *b;

  b = (((t_block *)ptr) - 1);
  printf("block to free address: %p\n", b);
  printf("allocated size: %d\n", b->size);
  printf("space to free address: %p\n", b + 1);
}
