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
  b = sbrk(sizeof (*b) + size);
  finalize_add_block(blockchain, b);
}
