/*
** args_utils.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 15:48:49 2016 Guillaume MARDON
** Last update Sun Dec 18 12:13:29 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int	need_encode_args_type(int code)
{
  return ((code != 1 && code != 9 && code != 12 && code != 15) ? 1 : 0);
}

char	get_encoded_args_type(char types[MAX_ARGS_NUMBER])
{
  char encoded_args;
  int args_index;

  encoded_args = 0;
  args_index = 0;
  while (args_index < 3)
    {
      encoded_args |= types[args_index++];
      encoded_args <<= 2;
    }
  return (encoded_args);
}
