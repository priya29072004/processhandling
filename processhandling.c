#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
  pid_t pid;
  printf("Parent id:%d\n",getpid());
  pid =fork();
  if(pid <0)
  {
    perror("Fork falied");
    
  }
  else if(pid==0)
  {
    printf("child process id:%d\n",getpid());
    printf("parent process id:%d\n",getppid());
    execl("/bin/date","date",NULL);
    perror("exec failed");
   // exit(1);
  }
  else
  {
      printf("Parent: I created child with PID %d\n", pid);
        printf("Parent: Waiting for child to finish...\n");

        wait(NULL); // Wait for child

        printf("Parent: Child finished. I'm done.\n");
  }
}
