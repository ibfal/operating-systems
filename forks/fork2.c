#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main (){
int id, ret;
ret = fork();
ret = fork();
id = getpid();
printf("\n My identifier is ID = [%d] \n", id);
while(1);
return 0;
}

/*Bella> gcc -o xfork2 fork2.c                                          tree diagram
Bella> ./xfork2 &                                                           parent (1346)
[1] 1346                                                            child 1 (1347)        child 2 (1348)
Bella>                                                         child 3 (1349)     
 My identifier is ID = [1346]       this is parent                
                                                            the tree shows us that the system forked the parent process
 My identifier is ID = [1348]       this is C2              all the way through before forking child 1 for the second fork call.
                                                            this is evident by the printed output (im like 90%) confident about that.
 My identifier is ID = [1347]       this is c1                        

 My identifier is ID = [1349]       this is c3
ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.06 -bash
  504  1346  1178   0  7:59PM ttys000    0:40.20 ./xfork2
  504  1347  1346   0  7:59PM ttys000    0:40.19 ./xfork2
  504  1348  1346   0  7:59PM ttys000    0:40.18 ./xfork2
  504  1349  1347   0  7:59PM ttys000    0:40.19 ./xfork2
Bella> kill -9 1346                                         I killed processes in order this time. you can see the children still alive after the parent is killed
[1]+  Killed: 9               ./xfork2
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.07 -bash
  504  1347     1   0  7:59PM ttys000    1:03.13 ./xfork2
  504  1348     1   0  7:59PM ttys000    1:03.12 ./xfork2
  504  1349  1347   0  7:59PM ttys000    1:03.13 ./xfork2
Bella> kill -9 1348
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.07 -bash
  504  1347     1   0  7:59PM ttys000    1:41.61 ./xfork2
  504  1349  1347   0  7:59PM ttys000    1:41.61 ./xfork2
Bella> kill -9 1347
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.08 -bash
  504  1349     1   0  7:59PM ttys000    2:01.26 ./xfork2
Bella> kill -9 1349
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.08 -bash      all processes are dead except the terminal 
*/