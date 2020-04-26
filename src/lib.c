#include "minilib.h"
#include "methods.h"

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

  array[i] = '\0';
  return array;
}

void mx_strdel(char **str)
{
  free(*str);
  *str = NULL;
}

t_pokerHand *mx_create_node(char *rank, char *suit)
{
    t_pokerHand *node = malloc(sizeof(t_pokerHand));

    if (!node) return NULL;

    node -> rank = rank;
    node -> suit = suit;
    node -> next = NULL;

    return node;
}

int mx_strcmp(const char *s1, const char *s2)
{
  while (*s1 && *s1 == *s2) {
    s1++;
    s2++;
  }
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void mx_push_back(t_pokerHand **list, char *rank, char *suit)
{
  t_pokerHand *back_list = mx_create_node(rank, suit);
  t_pokerHand *temp_list = NULL;

  temp_list = *list;

  while (temp_list -> next)
    temp_list = temp_list -> next;

  temp_list -> next = back_list;
}

bool is_rank(char *rank)
{
    if (mx_strcmp(rank, "2") == 0) return true;

    else if (mx_strcmp(rank, "2") == 0) return true;

    else if (mx_strcmp(rank, "3") == 0) return true;

    else if (mx_strcmp(rank, "4") == 0) return true;

    else if (mx_strcmp(rank, "5") == 0) return true;

    else if (mx_strcmp(rank, "6") == 0) return true;

    else if (mx_strcmp(rank, "7") == 0) return true;

    else if (mx_strcmp(rank, "8") == 0) return true;

    else if (mx_strcmp(rank, "9") == 0) return true;

    else if (mx_strcmp(rank, "10") == 0) return true;

    else if (mx_strcmp(rank, "J") == 0) return true;

    else if (mx_strcmp(rank, "Q") == 0) return true;

    else if (mx_strcmp(rank, "K") == 0) return true;

    else if (mx_strcmp(rank, "A") == 0) return true;

    else return false;

}

bool is_suit(char *suit)
{

  if (mx_strcmp(suit, "H") == 0) return true;

  else if (mx_strcmp(suit, "C") == 0) return true;

  else if (mx_strcmp(suit, "S") == 0) return true;

  else if (mx_strcmp(suit, "D") == 0) return true;

  else return false;

}

bool mx_isalpha(int c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? true : false;
}

bool mx_isdigit(int c)
{
  return (c >= 0 && c <= 9 ? true: false);
}

bool mx_is_suit(char suit)
{
  if (suit == 'H' || suit == 'D' || suit == 'C' || suit == 'S')
    return true;

  return false;
}

int mx_count_words(const char *str, char c)
{
  int state = 1;
  int wordcount = 0;
  int i = 0;

  if (str == NULL)
    return -1;

  else {

    while (str[i]) {

      if (str[i] == c)
        state = 1;

      else if (state == 1) {

        state = 0;
        ++wordcount;
      }

      ++i;
    }
    return wordcount;
  }
}

char *mx_strcat(char *s1, const char *s2)
{

  char *ptr = s1 + mx_strlen(s1);

  while (*s2 != '\0')
    *ptr++ = *s2++;

  *ptr = '\0';

  return s1;
}