#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void fork7()
{
int ret;
ret = fork();
if (ret == 0){
    printf("\n [%d] Running Child \n", getpid());
    sleep(2);
    printf("\n [%d] Ending Child \n", getpid());
    }
else{
    printf("\n [%d] Waiting Parent \n", getpid());
    wait(NULL);
    printf("\n [%d] Ending Parent \n", getpid());}
}

int main ()
{
fork7();
return 0;}


/*Bella> ./xfork7 &                             tree parent(3435)
[1] 3435                                                child (3436)
Bella> 
 [3435] Waiting Parent                          sync up.

 [3436] Running Child 
                                    these pairs displayed at same time, but there was a lag on the second set. 
 [3436] Ending Child 

 [3435] Ending Parent 
ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.14 -bash
[1]+  Done                    ./xfork7
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.14 -bash*/