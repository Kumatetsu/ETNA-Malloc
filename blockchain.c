/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 23:04:38 2018 CASTELLARNAU Aurelien
** Last update Thu Jan 11 18:35:19 2018 BILLAUD Jean
*/

#include "blockchain.h"
#include "chunk.h"
#include <unistd.h>
#include <stdio.h>

static t_bc *bc = NULL;

/*
** create_bc singleton to instanciate the central
** chain list of memory block
*/
void	create_bc()
{
  if (bc == NULL)
    bc = new_bc();
}

/*
** get_bc is the accessor to retrieve the blockchain singleton
*/
t_bc	*get_bc()
{
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
** add_block_with_chunks must be call after init_chunks
** this function will add block checking if some are available in chunks
*/ 
void		add_block_with_chunks(t_bc **blockchain, unsigned int size)
{
  t_block	*b;

  if ((*blockchain) == NULL)
    (*blockchain) = new_bc();
  b = get_space_from_chunks(size);
  finalize_add_block(blockchain, b);
}

/*
** Classic block creation without call to get_space_from_chunks
** this function is used in chunk initialisation process
*/
void		add_block(t_bc **blockchain, unsigned int size)
{
  t_block	*b;

  if ((*blockchain) == NULL)
    (*blockchain) = new_bc();
  if (get_space_from_bc(blockchain, size))
    {
      printf("try to allocate from scratch \n");
      b = (t_block*)sbrk((intptr_t)(sizeof(t_block) + size));
      b->size = size;
      finalize_add_block(blockchain, b);
      printf("size needed is %d and allocated is %d\n", size, (*blockchain)->last->size);
    }
}
 
int		get_space_from_bc(t_bc **blockchain, unsigned int size)
{
  t_block	*tmp;
  t_block	*block;
  
  tmp = (*blockchain)->first;
  printf("get space from bc \n");
  printf("size needed %d\n", size);
  while(tmp)
    {
      printf("block size is %d\n", size);
      if (tmp->size >= size && tmp->space == FREE)
	{
	  block = tmp;
	  block->prev->next = (*blockchain)->last;
	  block->next->prev = (*blockchain)->last;
	  (*blockchain)->last->prev = block->prev;
	  (*blockchain)->last->next = block->next;
	  (*blockchain)->last = block;
	  block->space = ALLOC;
	  printf("memory allocated from my memory bitches \n");
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}
