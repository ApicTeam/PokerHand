#include "minilib.h"

int mx_strlen(const char *s)
{
    int len = 0;

    while (*s++)
        len += 1;

    return len;
}

char *mx_strcpy(char*dst, const char*src)
{

  char *p = dst;

  while (*src != '\0')
    *p++ = *src++;


  *p = '\0';
  return dst;
}

bool mx_isspace(char c)
{
  return (c == 32 || (c >= 9 && c <= 13) ? true: false);
}

char *mx_strnew(const int size)
{
  int i = 0;

  if (size < 0)
    return NULL;

  char *array = (char *)malloc((size + 1) * sizeof(char));

  for (i = 0; i < size; i++)
    array[i] = '\0';

  return array;
}

void mx_strdel(char **str)
{
  free(*str);
  *str = NULL;
}