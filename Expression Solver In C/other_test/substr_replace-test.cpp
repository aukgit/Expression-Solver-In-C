#include <stdio.h>
#include <string.h>

#define N 1000

char *replace_str(char *str, char *FindChar, char *rep)
{
  static char buffer[N];
  char *p;

  if(!(p = strstr(str, FindChar)))  // Is 'FindChar' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'FindChar' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(FindChar));

  return buffer;
}

int main(void)
{
  puts(replace_str("Hello, world!", "world", "Miami"));

  return 0;
}
