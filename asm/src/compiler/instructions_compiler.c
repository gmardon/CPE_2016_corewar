/*
** instructions_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 20:21:45 2016 Guillaume MARDON
** Last update Mon Dec  5 20:39:28 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char	*create_instructions(instruction_t *first_instruction, int *size)
{
  char *buffer;
  instruction_t *instruction;
  int index;

  buffer = malloc(sizeof(char) * BUFF_SIZE);
  index = 0;
  instruction = first_instruction;
  while (instruction)
    {
      buffer[index++] = instruction->op->code;
      if (need_encode_args_type(instruction->op->code))
				buffer[index++] = get_encoded_args_type(instruction->args->type);
      my_printf("[%s]\n", instruction->op->mnemonique);
      instruction = instruction->next;
    }
  *size = index;
  return (buffer);
}
