/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 23:04:38 2018 CASTELLARNAU Aurelien
** Last update Sat Jan 13 15:23:59 2018 BILLAUD Jean
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
  //write(1, "init bc\n", 8);
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

  //write(1, "begin add block\n", 16);
  if ((*blockchain) == NULL)
    (*blockchain) = new_bc();
  if (get_space_from_bc(blockchain, size))
    {
      size = add_more_size(size);
      b = (t_block*)sbrk((intptr_t)(sizeof(t_block) + (unsigned int)size));
      b->size = size;
      finalize_add_block(blockchain, b);
      //write(1, "block add from scratch\n", 23);
    }
}

size_t		add_more_size(size_t size)
{
  size_t	new_size;

  new_size = 1;
  while (new_size <= size)
    {
      new_size *= 2;
    }
  
  return (new_size);
}
 
int		get_space_from_bc(t_bc **blockchain, size_t  size)
{
  t_block	*tmp;
  t_block	**block;
  
  tmp = (*blockchain)->first;
  //write(1, "try to allocate from bc\n", 24);
  while(tmp)
    {
      if ((unsigned int)tmp->size >= (unsigned int)size && tmp->space == FREE)
	{
	  //write(1, "ready for allocation\n", 21);
	  block = &tmp;
	  if ((*blockchain)->first != (*blockchain)->last)
	    {
	      if ((*blockchain)->first == (*block))
		{
		  (*blockchain)->first = (*blockchain)->first->next;
		  (*blockchain)->first->prev = NULL;
		  
		  (*block)->next = NULL;
		  (*block)->prev = (*blockchain)->last;
		  (*blockchain)->last->next = (*block);
		  (*blockchain)->last = (*block);
		}
	      else if ((*blockchain)->last != (*block))
		{
		  (*block)->next->prev = (*block)->prev;
		  (*block)->prev->next = (*block)->next;

		  (*block)->next = NULL;
		  (*block)->prev = (*blockchain)->last;
		  (*blockchain)->last->next = (*block);
		  (*blockchain)->last = (*block);
		}
	    }
	  (*block)->space = ALLOC;
	  //write(1, "alloc should be fine\n", 22);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}
