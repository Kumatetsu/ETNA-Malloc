/*
** blockchain.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Tue Jan  9 22:58:12 2018 CASTELLARNAU Aurelien
** Last update Tue Jan  9 23:02:38 2018 CASTELLARNAU Aurelien
*/

#ifndef  _BLOCKCHAIN_H_
# define _BLOCKCHAIN_H_

typedef struct		s_block
{
  struct s_block	*next;
  struct s_block	*prev;
  unsigned int		magic;
  unsigned int		size;
}			t_block;

typedef struct	s_bc
{
  t_block	*first;
  t_block	*last;
}		t_bc;

void	my_simple_free(void *ptr);
void	*my_simple_malloc(unsigned int size);

#endif	/* !_BLOCKCHAIN_H_ */
