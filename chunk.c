/*
** chunk.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 03:53:29 2018 CASTELLARNAU Aurelien
** Last update Wed Jan 10 05:54:56 2018 CASTELLARNAU Aurelien
*/

#include "blockchain.h"
#include "chunk.h"
#include <unistd.h>
#include <stdio.h>

static t_bc *chunks[11];

/*
** Convert any size in correspondant chunks index
** a zero size will lead to an allocation of 1 octet
*/
int	define_index(unsigned int size)
{
  if (size == 0)
    return (0);
  else if (size == 1)
    return (0);
  else if (size == 2)
    return (1);
  else if (size > 2 && size <= 4)
    return (2);
  else if (size > 4 && size <= 8)
    return (3);
  else if (size > 8 && size <= 16)
    return (4);
  else if (size > 16 && size <= 32)
    return (5);
  else if (size > 32 && size <= 64)
    return (6);
  else if (size > 64 && size <= 128)
    return (7);
  else if (size > 128 && size <= 512)
    return (8);
  else if (size > 512 && size <= 1024)
    return (9);
  else
    return -1;
}

/*
** Initialise and fullfill a chainlist where each block
** contain another chainlist containing memory spaces.
** Memory spaces are organised as follow:
** 1, 2, 4, 8, 16, 32, 64, 128, 512, 1024 octets
** if > 1024, we call sbrk direct (see get_space_from_chunks)
*/
void	init_chunks()
{
  int	ref;

  ref = -1;
  while (++ref < 11)
    chunks[ref] = new_bc();
  ref = 0;
  while (ref < 192)
    {
      add_block(&chunks[0], 1);
      ++ref;
    }
  ref = 0;
  while (ref < 50)
    {
      add_block(&chunks[1], 2);
      ++ref;
    }
  ref = 0;
  while (ref < 25)
    {
      add_block(&chunks[2], 4);
      ++ref;
    }
  ref = 0;
  while (ref < 12)
    {
      add_block(&chunks[3], 8);
      ++ref;
    }
  ref = 0;
  while (ref < 6)
    {
      add_block(&chunks[4], 16);
      ++ref;
    }
  ref = 0;
  while (ref < 3)
    {
      add_block(&chunks[5], 32);
      ++ref;
    }
  ref = 0;
  while (ref < 1)
    {
      add_block(&chunks[6], 64);
      ++ref;
    }
  ref = 0;
  while (ref < 1)
    {
      add_block(&chunks[7], 128);
      ++ref;
    }
  ref = 0;
  while (ref < 1)
    {
      add_block(&chunks[8], 256);
      ++ref;
    }
  ref = 0;
  while (ref < 1)
    {
      add_block(&chunks[9], 512);
      ++ref;
    }
  ref = 0;
  while (ref < 1)
    {
      add_block(&chunks[10], 1024);
      ++ref;
    }
  printf("check on chunks[index]: %p\n", chunks[4]);
}

/*
** get_chunks singleton on chunks chainlist
*/
t_bc **get_chunks()
{
  if (chunks[0] == NULL)
    init_chunks();
  return (chunks);
}

/*
** get_space_from_chunks call define index to retrieve the good
** size value, define if chunks can provide or 
** if we need to make a new allocation
*/
t_block		*get_space_from_chunks(unsigned int size)
{
  int		index;
  t_bc		**chunks;
  t_block	*block;
  
  index = define_index(size);
  chunks = get_chunks();
  printf("get space from chunks with index: %d\n", index);
  if (index == -1 || chunks[index] == NULL || !chunks[index]->size)
    {
      block = (t_block*)sbrk((intptr_t)(sizeof(t_block) + size));
      block->size = size;
      printf("allocate from scratch\n");
    }
  else
    {
      printf("allocate from chunks, on index: %d", index);
      block = chunks[index]->last;
      if (chunks[index]->last->prev != NULL)
	chunks[index]->last = chunks[index]->last->prev;
      chunks[index]->last->next = NULL;
      chunks[index]->size--;
    }
  return block;
}
 
