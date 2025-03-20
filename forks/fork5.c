#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void fork5()
{
printf("\n [%d] L0 \n", getpid());
if (fork() != 0)
    {printf("\n [%d] L1 \n", getpid());
    if (fork() != 0){
        printf("\n [%d] L2 \n", getpid());
        fork();}}

printf("\n [%d] Bye \n", getpid());
}
int main ()
{
fork5();
return 0;
}
/*the parent just keeps forking. all the children terminate*/
/*Bella> ./xfork5                   tree:    parent[3247]

 [3247] L0                     child 1 (3248) child 2(3249) child 3 (3250)                           

 [3247] L1 

 [3247] L2 

 [3248] Bye 

 [3247] Bye 

 [3249] Bye 

 [3250] Bye */