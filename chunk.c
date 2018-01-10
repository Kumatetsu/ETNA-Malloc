/*
** chunk.c for Malloc in 
** 
** Made by CASTELLARNAU Aurelien
** Login   <castel_a@etna-alternance.net>
** 
** Started on  Wed Jan 10 03:53:29 2018 CASTELLARNAU Aurelien
** Last update Wed Jan 10 05:54:56 2018 CASTELLARNAU Aurelien
*/

#include "chunk.h"
#include "blockchain.h"
#include <unistd.h>
#include <stdio.h>

/*
** Memory allocation rules
** 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
** 1920, 500, 250, 125, 60, 30, 15, 5, 2, 2, 1
** total to init: 10 000
*/
static char *chunks[10];

static void *one[5000];
/*
static void *two[500];
static void *four[250];
static void *eight[125];
static void *sixteen[60];
static void *t_two[30];
static void *s_four[15];
static void *ht_eight[5];
static void *thf_six[2];
static void *tt_four[1];
*/
// convert any size in correspondant chunks index
// a zero size will lead to an allocation of 1 octet
int	define_index(unsigned int size)
{
  if (size == 0)
    return (0);
  else if (size == 1)
    return (0);
  else if (size == 2)
    return (1);
  else if (size > 2 && size <= 4)
    return (2);
  else if (size > 4 && size <= 8)
    return (3);
  else if (size > 8 && size <= 16)
    return (4);
  else if (size > 16 && size <= 32)
    return (5);
  else if (size > 32 && size <= 64)
    return (6);
  else if (size > 64 && size <= 128)
    return (7);
  else if (size > 128 && size <= 512)
    return (8);
  else if (size > 512 && size <= 1024)
    return (9);
  else
    return -1;
}

void	init_chunks()
{
  void	*internal_heap;
  int	ref;

  ref = -1;
  internal_heap = sbrk(10);
  ref = 0;
  while (ref <= 10)
    {
      one[ref] = internal_heap;
      printf("internal_heap state: %p, index: %d", internal_heap, ref);
      ++ref;
      internal_heap = internal_heap + 1;
    }
  chunks[0] = (char*)one;
}

char **get_chunks()
{
  return (chunks);
}
