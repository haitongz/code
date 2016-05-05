#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
  pid_t pid;
  char *message;
  int n;
  int exit_code;

   printf("fork program starting\n");
   pid=fork();
   switch(pid)
   {
     case -1:
     perror("fork failed");
     exit(1);
     case 0:
     message = "This is the child";
     n = 5;
     // child process exit code
     exit_code=37;
     break;
     default:
     message = "This is the prrent";
     n = 3;
     // prarent process exit code
     exit_code = 0;
     break;
   }

    if(pid)
    {
      int stat_val;
      pid_t child_pid;

      // parent exit until child process exit
      child_pid = wait(&stat_val);
      printf("Child process has finished: PID=%d\n", child_pid);
      if(WIFEXITED(stat_val))
      {
        printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
      }
      else
      {
        printf("Child terminated abnormally\n");
      }
    }
   for(;n>0;n--)
   {
     puts(message);
     sleep(1);
   }
   exit(exit_code);
}
