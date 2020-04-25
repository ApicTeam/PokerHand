#include "minilib.h"

char *mx_del_extra_whitespaces(const char *str)
{
  char *string = NULL, *temp = NULL;
  int i = 0;
  int j = 0;

  if (!str)
    return NULL;

  else
  {
    string = mx_strnew(mx_strlen(str));
    while (str[i])
    {
      if (!(mx_isspace(str[i])))

      {
        string[j] = str[i];
        j++;
      }

      if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1]))

      {
        string[j] = ' ';
        j++;
      }

      i++;
    }

    temp = mx_strtrim(string);

    mx_strdel(&string);
    return temp;
  }
}