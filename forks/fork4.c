#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork4()
{
printf("\n [%d] L0 \n", getpid());
fork();
printf("\n [%d] L1 \n", getpid());
fork();
printf("\n [%d] Bye \n", getpid());
}

int main ()
{
fork4();
return 0;
}


/*Bella> ./xfork4
                                tree:   parent L0 (3024)
 [3024] L0                  L1 child1(3025)   child 2(3026)      
                            L2 child 3(3027)
 [3024] L1 

 [3024] Bye                 so in this we are printing the statements at the inbetween levels.
                            so the parent exists at L0, forks down, is now at L1 forks again, and says bye
 [3025] L1                  the corresponding children do the same thing. 

 [3026] Bye 

 [3025] Bye 

 [3027] Bye */