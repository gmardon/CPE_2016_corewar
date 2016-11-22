/*
** compiler.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 11:27:08 2016 Guillaume MARDON
** Last update Tue Nov 22 17:33:25 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char*  compile(int* size, instruction_t *first_instruction)
{
  char *buffer;
  instruction_t *instruction;
  int index;

  buffer = malloc(sizeof(char*) * 1024);
  instruction = first_instruction;
  index = 0;
  while (instruction)
    {
      buffer[index++] = instruction->op->code;
      printf("[%s]\n", instruction->op->mnemonique);
      instruction = instruction->next;

    }
  *size = index;
  return (buffer);
}
