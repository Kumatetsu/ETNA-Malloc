/*
** my_calloc.c for Malloc in /home/kumatetsu/ETNA-Malloc
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Jan 13 15:10:06 2018 BILLAUD Jean
** Last update Sat Jan 13 15:46:15 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"

void		*calloc(size_t num_elements, size_t size)
{
  void		*toto;
  void		**address;
  size_t	i;
  
  toto = malloc(size);
  address = &toto;
  for (i = 0; i < num_elements; i++)
    address[i] = 0;
  
  return (*address);
}
