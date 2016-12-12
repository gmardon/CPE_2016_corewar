/*
** labelref_utils.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 17:48:59 2016 Guillaume MARDON
** Last update Mon Dec 12 19:04:05 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	add_ref(labelref_t *stack, labelref_t *labelref)
{
  int index;

  index = 0;
  while (stack[index].name)
    index++;
  stack[index] = *labelref;
}

void	add_label_ref(int index, char *name, labelref_t *stack)
{
  labelref_t *label;

  label = my_malloc(sizeof(labelref_t));
  label->is_label = 1;
  label->is_direct = 0;
  label->name = name;
  label->size = 0;
  label->index = index;

  add_ref(stack, label);
}

labelref_t	*create_refs_stack()
{
  int index;
  labelref_t *stack;

  index = 0;
  stack = my_malloc(sizeof(labelref_t) * 512);
  while (index < 512)
    {
      stack[index++].name = 0;
    }
  return (stack);
}

void	show_alls_label(labelref_t *refs)
{
  int index;

  index = 0;
  while (refs[index].name)
    {
      my_printf("ref name: %s, is label ref: %d, with index: %d, with size: %d\n", refs[index].name, refs[index].is_label, refs[index].index, refs[index].size);
      index++;
    }
}
