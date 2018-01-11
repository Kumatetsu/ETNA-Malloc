/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 22:58:12 2018 CASTELLARNAU Aurelien
** Last update Thu Jan 11 21:01:35 2018 BILLAUD Jean
*/

#ifndef  _BLOCKCHAIN_H_
# define _BLOCKCHAIN_H_

enum Alloc {ALLOC, FREE};

typedef struct		s_block
{
  struct s_block	*next;
  struct s_block	*prev;
  enum 	 Alloc	 	space;
  size_t		size;
}			t_block;

typedef struct	s_bc
{
  int		size;
  t_block	*first;
  t_block	*last;
}		t_bc;

void	create_bc();
t_bc	*get_bc();
t_bc	*new_bc();
int	get_space_from_bc(t_bc **blockchain, size_t size);
void	add_block(t_bc **blockchain, size_t size);
void	add_block_with_chunks(t_bc **blockchain, unsigned int size);

#endif	/* !_BLOCKCHAIN_H_ */
