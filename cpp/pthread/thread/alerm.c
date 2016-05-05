#include  <unistd.h>
#include  <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int alarm_fired=0;

void ding(int sig)
{
  alarm_fired = 1;
}

int main()
{
  int pid;

  printf("alarm alread start\n");
  if((pid=fork())==0)
  {
    sleep(5);
    kill(getppid(),SIGALRM);
    exit(0);
  }

   printf("5s later alerm start\n");
   (void) signal(SIGALRM, ding);
   pause();
   if (alarm_fired)
     printf("Ding!\n");

   printf("done\n");
   exit(0);
}
