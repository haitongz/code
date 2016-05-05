#include <stdio.h>

int main ()
{
  char buffer [10];
  int cx;

  //cx = snprintf ( buffer, 5, "Thexhalfof");
  cx = snprintf ( buffer, 5, "Thexaaxxx");

  printf ("buffer:%s\n", buffer);
  printf ("cx:%d\n", cx);

  return 0;
}
