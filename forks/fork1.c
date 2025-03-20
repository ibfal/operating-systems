#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main (){
int id, ret; /*initializes variables*/
ret = fork(); /*we fork processes*/
id = getpid(); /*we get the process ID*/
printf("\n My identifier is ID = [%d] \n", id); /*print the process ID*/
while(1); /**/
return 0;
}


/*Bella> ./xfork1 &                                             we are running the code
[1] 1239                                                        this is the process ID of the parent fucntion 
Bella> 
 My identifier is ID = [1239]                                   parent process ID

 My identifier is ID = [1240]                                   child process ID
./xfork ps -f                                                   this prints out the process ID of current/active processes running
  UID   PID  PPID   C STIME   TTY           TIME CMD        
  504  1178  1177   0  7:44PM ttys000    0:00.05 -bash
  504  1239  1178   0  7:48PM ttys000    0:13.84 ./xfork1
  504  1240  1239   0  7:48PM ttys000    0:13.84 ./xfork1
Bella> kill -9 1240                                             I know i did this backwards because the first time i ran it when i killed the 1st one 
                                                                it didnt do anyhting after killing the second so i wanted to see the effect
Bella> ps -f
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.05 -bash
  504  1239  1178   0  7:48PM ttys000    0:49.91 ./xfork1
  504  1240  1239   0  7:48PM ttys000    0:00.00 <defunct>       Here we can see that process (1240, the child) is no longer running
Bella> kill -9 1239                                             now we killed the parent 
[1]+  Killed: 9               ./xfork1                          shows that the parent is killed
Bella> ps -f                                                    check current processes active
  UID   PID  PPID   C STIME   TTY           TIME CMD
  504  1178  1177   0  7:44PM ttys000    0:00.05 -bash          we can see only the terminal is running with no other active processes 
*/