#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="we are simplesample!";
  char * pch;
  char clickurl[1024];
  pch = strstr (str,"simple");
  snprintf(clickurl, sizeof(clickurl), "%s", pch+6);
  puts (str);
  puts (clickurl);
  if((pch=strstr(clickurl, "am"))) *pch = 0;
  //if((pch=strstr(log->clickurl, "\1"))) *pch = 0;
//strncpy (pch,"sample",6);
  puts ("str:");
  puts (str);
  puts ("pch:");
  puts (pch);
  puts ("clickurl:");
  puts (clickurl);
  return 0;
}
