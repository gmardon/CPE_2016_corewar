/*
** recon.h for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Tue Nov  8 17:33:45 2016 Aurelien Olibe
** Last update Mon Nov 14 12:59:50 2016 Aurelien Olibe
*/
#include "basic.h"

ssize_t		numeric(const char *format, int *i)
{
  ssize_t	no;

  no = 0;
  if (format[*i] >= '1' && format[*i] <= '9')
    {
      no = no + (format[*i] - '0');
      *i = *i + 1;
      while (format[*i] >= '0' && format[*i] <= '9')
	{
	  no = no * 10;
	  no = no + (format[*i] - '0');
	  *i = *i + 1;
	}
      *i = *i - 1;
    }
  return (no);
}

int	format1(const char form)
{
  if (form == 'd' || form == 'i')
    return (1);
  else if (form == 'o')
    return (3);
  else if (form == 'u')
    return (4);
  else if (form == 'x')
    return (5);
  else if (form == 'X')
    return (6);
  else if (form == 'e')
    return (7);
  else if (form == 'E')
    return (8);
  else if (form == 'f')
    return (9);
  else if (form == 'F')
    return (10);
  else if (form == 'g')
    return (11);
  else if (form == 'G')
    return (12);
  else
    return (format2(form));
}

int	format2(const char form)
{
  if (form == 'a')
    return (13);
  else if (form == 'A')
    return (14);
  else if (form == 'c')
    return (15);
  else if (form == 's')
    return (16);
  else if (form == 'C')
    return (17);
  else if (form == 'S')
    return (18);
  else if (form == 'p')
    return (19);
  else if (form == 'n')
    return (20);
  else if (form == 'm')
    return (21);
  else if (form == 'b')
    return (22);
  else if (form == '%')
    return (23);
  else
    return (0);
}

int	modifiers(const char modif, const char modif2)
{
  if (modif == modif2)
    {
      if (modif == 'h')
	return (1);
      else if (modif == 'l')
	return (1);
      else
	return (1);
    }
  else if (modif == 'h')
    return (1);
  else if (modif == 'l')
    return (1);
  else if (modif == 'L')
    return (1);
  else if (modif == 'J')
    return (1);
  else if (modif == 'z')
    return (1);
  else if (modif == 't')
    return (1);
  else
    return (0);
}

int	flags(const char flag)
{
  if (flag == '#')
    return (1);
  else if (flag == '0')
    return (2);
  else if (flag == '-')
    return (3);
  else if (flag == '+')
    return (4);
  else if (flag == ' ')
    return (5);
  else if (flag == '\'')
    return (6);
  else if (flag == 'I')
    return (7);
  else if (flag == '.')
    return (8);
  else
    return (0);
}
