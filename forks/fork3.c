#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork3(){
int ret;
ret = fork();
if (ret == 0) /* ret = 0 is for the child*/
printf("\n [%d] Hello from child \n", getpid());
else /*ret != 0 is for the parent process*/
printf("\n [%d] Hello from parent \n", getpid());
}

int main ()
{
fork3();
return 0;
}

/*Bella> ./xfork3
                                    tree:    parent [2883]
 [2883] Hello from parent                       |
                                            child [2884]
 [2884] Hello from child 
*/