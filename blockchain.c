/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 23:04:38 2018 CASTELLARNAU Aurelien
** Last update Wed Jan 10 00:12:03 2018 CASTELLARNAU Aurelien
*/

#include "blockchain.h"
#include <unistd.h>
#include <stdio.h>

static t_bc *bc = NULL;

void	create_bc()
{
  bc = sbrk((intptr_t)(sizeof(*bc)));
  bc->first =NULL;
  bc->last = NULL;
}

void		add_block(unsigned int size)
{
  t_block	*b;

  b = sbrk((intptr_t)sizeof(*b));
  b->size = size;
  if (bc == NULL)
    {
      create_bc();
      bc->first = b;
      bc->last = b;
    }
  else
    {
      bc->last->next = b;
      b->next = NULL;
      b->prev = bc->last;
      bc->last = b;
    }
}

void		*my_simple_malloc(unsigned int size)
{
  t_block	*space;

  add_block(size);
  space = sbrk((intptr_t)sizeof (*(bc->last)) + size);
  space = bc->last;
  printf("allocated size: %d\n", space->size);
  printf("block adress: %p\n", space);
  printf("size of b: %lu\n", sizeof (*space));
  printf("size of t_block: %lu\n", sizeof (t_block));
  printf("returned address: %p\n", space + 1);
  return (space + 1);
}
  
void		my_simple_free(void *ptr)
{
  t_block	*b;

  b = (((t_block *)ptr) - 1);
  printf("block to free address: %p\n", b);
  printf("allocated size: %d\n", b->size);
  printf("space to free address: %p\n", b + 1);
}
