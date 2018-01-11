/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 23:04:38 2018 CASTELLARNAU Aurelien
** Last update Thu Jan 11 22:03:11 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "chunk.h"

static t_bc *bc = NULL;

/*
** create_bc singleton to instanciate the central
** chain list of memory block
*/
void	create_bc()
{
  bc = new_bc();
}

/*
** get_bc is the accessor to retrieve the blockchain singleton
*/
t_bc	*get_bc()
{
  if (bc == NULL)
    create_bc();
  return bc;
}

/*
** new_bc instanciate a new chainlist t_bc
** and return it putting all properties at NULL or 0
*/
t_bc	*new_bc()
{
  t_bc	*blockchain;
  
  blockchain = sbrk((intptr_t)(sizeof(*blockchain)));
  blockchain->first =NULL;
  blockchain->last = NULL;
  blockchain->size = 0;
  return (blockchain);
}

/*
** finalize_add_block factorise the end of the add_block logic
*/
void	finalize_add_block(t_bc **blockchain, t_block *b)
{
  if ((*blockchain)->first == NULL)
    {
      (*blockchain)->first = b;
      (*blockchain)->last = b;
    }
  else
    {
      (*blockchain)->last->next = b;
      b->next = NULL;
      b->prev = (*blockchain)->last;
      (*blockchain)->last = b;
    }
  (*blockchain)->size++;
}

/*
** Classic block creation without call to get_space_from_chunks
** this function is used in chunk initialisation process
*/
void		add_block(t_bc **blockchain, size_t size)
{
  t_block	*b;

  if ((*blockchain) == NULL)
    (*blockchain) = new_bc();
  if (get_space_from_bc(blockchain, size))
    {
      b = (t_block*)sbrk((intptr_t)(sizeof(t_block) + (unsigned int)size));
      b->size = size;
      finalize_add_block(blockchain, b);
    }
}
 
int		get_space_from_bc(t_bc **blockchain, size_t  size)
{
  t_block	*tmp;
  t_block	*block;
  
  tmp = (*blockchain)->first;
  while(tmp)
    {
      if ((unsigned int)tmp->size >= (unsigned int)size && tmp->space == FREE)
	{
	  block = tmp;
	  block->prev->next = (*blockchain)->last;
	  block->next->prev = (*blockchain)->last;
	  (*blockchain)->last->prev = block->prev;
	  (*blockchain)->last->next = block->next;
	  (*blockchain)->last = block;
	  block->space = ALLOC;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}
