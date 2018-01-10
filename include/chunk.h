/*
** chunk.h for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 05:11:52 2018 CASTELLARNAU Aurelien
** Last update Wed Jan 10 05:12:41 2018 CASTELLARNAU Aurelien
*/

#ifndef  _CHUNK_H_
# define _CHUNK_H_

int	define_index(unsigned int size);
void	init_chunks();
t_bc	**get_chunks();
t_block	*get_space_from_chunks(unsigned int size);

#endif  /* !_CHUNK_H_ */
