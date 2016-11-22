/*
** compiler.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 11:27:08 2016 Guillaume MARDON
** Last update Tue Nov 22 15:15:22 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int compile(char* buffer, instruction_t *first_instruction)
{
  instruction_t *instruction;

  buffer = malloc(sizeof(char*) * 1024);
  instruction = first_instruction;
  while (instruction)
    {
      printf("[%s]\n", instruction->op->mnemonique);
      instruction = instruction->next;
    }

  return (0);
}
