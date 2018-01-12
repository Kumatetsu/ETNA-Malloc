/*
** main.c for malloc in /home/nada/Documents/ETNA/TIC-DVC4/malloc/charti_r
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Jan 11 21:05:28 2018 MESRATI Nada
** Last update Thu Jan 11 21:31:30 2018 MESRATI Nada
*/
#include <stdio.h>
#include "malloc.h"

int	main()
{
  void	*ptr[3];
  
  printf("[Debug] -- Alloc ptr[0]");
  if ((ptr[0] = malloc(sizeof(**ptr))) == 0)
    return (1);
  printf("%p\n", ptr[0]);
  printf("[Debug] -- Alloc ptr[1]");
  if ((ptr[1] = malloc(sizeof(**ptr))) == 0)
    return (1);
  printf("%p\n", ptr[1]);
  printf("[Debug] -- Alloc ptr[2]");
  if ((ptr[2] = malloc(sizeof(**ptr))) == 0)
    return (1);
  printf("%p\n", ptr[2]);
  printf("[Debug] -- Free ptr[0] %p\n", ptr[0]);
  free(ptr[0]);
  printf("[Debug] -- Free ptr[1] %p\n", ptr[1]);
  free(ptr[1]);
  printf("[Debug] -- Alloc ptr[0]");
  if ((ptr[0] = malloc(sizeof(**ptr))) == 0)
    return (1);
  printf("%p\n", ptr[0]);
    printf("[Debug] -- Free ptr[0] %p\n", ptr[0]);
  free(ptr[0]);
  printf("[Debug] -- Free ptr[2] %p\n", ptr[2]);
  free(ptr[2]);

  return (0);
}
