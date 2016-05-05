#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="";
  char * pch;
  char clickurl[1024];
  pch = strstr (str,"simple");
  snprintf(clickurl, sizeof(clickurl), "%s", pch+6);
  puts ("clickurl:");
  puts (clickurl);
  return 0;
}
