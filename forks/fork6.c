#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void fork6()
{printf("\n [%d] L0 \n", getpid());
if (fork() == 0){
    printf("\n [%d] L1 \n", getpid());
    if (fork() == 0){
        printf("\n [%d] L2 \n", getpid());
        fork();}}

printf("\n [%d] Bye \n", getpid());
}


int main ()
{
fork6();
return 0;
}

/*Bella> ./xfork6               tree:  parent (3364)
                                        child1 (3365)
 [3364] L0                              child2 (3366)
                                        child 3 (3367)
 [3364] Bye 
                                ret values are 0 so we pass to the next, 
 [3365] L1                      but then when it had a child it is no longer 0 so it says goobye.

 [3365] Bye 

 [3366] L2 

 [3366] Bye 

 [3367] Bye*/