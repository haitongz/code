#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
  printf("OUCH! - I got signal %d\n", sig);
  (void) signal(SIGINT,SIG_DFL);
}

int main()
{
  (void) signal(SIGINT, ouch);
    printf("Hello world!%d \n", SIGINT);
  while (1)
  {
    printf("Hello world!\n");
    sleep(1);
  }
}

