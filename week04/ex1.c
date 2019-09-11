#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t n = getpid();
    if(n = fork()){
         printf("Hello from parent [PID - %d]\n", getpid());

    }
    else{
         printf("Hello from child [PID - %d]\n", getpid());
    }
    return 0;
} 
