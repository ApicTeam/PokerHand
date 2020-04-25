#include "minilib.h"

char *mx_strtrim(const char *str){
  int start = 0;
  int spaces_count = 0;
  int len = 0;

  char *temp_str = mx_strnew(mx_strlen(str));
  char *trimed_str;

  while (mx_isspace(*str))
    start++, str++;

  for (int i = 0; 1; i++){

    if (str[i] == '\0')
      break;

    if (!(mx_isspace(str[i])))
      spaces_count = 0;

    temp_str[i] = str[i];
    spaces_count++;

  }

  len = mx_strlen(temp_str) - spaces_count + 1;
  trimed_str = mx_strnew(len);

  for (int i = 0; i < len ; i++)
    trimed_str[i] = temp_str[i];

  mx_strdel(&temp_str);
  return trimed_str;
}
