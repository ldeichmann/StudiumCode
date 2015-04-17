#include <stdio.h>
#include <string.h>
#include "caesar.h"
#include "anacae.h"


char most_frequent_letter(char s[])
{
  char c;
  int i;
  int biggest;

  int letters[256] = {0};

  for (i=0; i < strlen(s); i++)
  {
      int hashvalue = (int)(s[i]);
      letters[hashvalue] += 1;
  }

  biggest = letters[0];
  int value, biggest_found;
  for (i=0; i < 256; i++)
  {
      if (letters[i] > biggest)
      {
          biggest = letters[i];
          biggest_found = i;
      }
  }


  c = (char) biggest_found;
  return (c) ;
}

void anacae(char text[]) {

    printf("%c\n", most_frequent_letter(text));
    unsigned int offNr = (most_frequent_letter(text) - 69);
//      caesar(text, offNr);
}
