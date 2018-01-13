/*
** my_malloc.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 05:54:25 2018 CASTELLARNAU Aurelien
** Last update Sat Jan 13 15:24:15 2018 BILLAUD Jean
*/

#include <unistd.h>
#include <stdio.h>
#include "blockchain.h"
#include "my_malloc.h"
/*
** my_simple_malloc is the central call to allocation logic
*/
void            *malloc(size_t size)
{
  t_bc		*bc;
  t_block       *space;
  
  bc = get_bc();
  //write(1, "get the bc!\n", 12);
  add_block(&bc, size);
  //write(1, "block added\n", 12);
  space = bc->last;
  //write(1, "space set\n", 10);
  return (space + 1);
}

/*
** my_simple_free is the central call for free logic
*/
void            free(void *ptr)
{
  t_block       *b;
  
  if (ptr != NULL)
    {
      //write(1, "in free\n", 8);
      b = (((t_block *)ptr) - 1);
      b->space = FREE;
      //write(1, "block freed\n", 12);
    }
}

/*test*/
