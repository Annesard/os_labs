#include <stdio.h>
#include <sys/types.h>
#include <string.h>


int main(){
    
    for(;;){
    char str[100];
    
    gets(str);
    int  init_size = strlen(str);
    char delim[] = " ";
    char *arr[128];
    int i =0;

    char *ptr = strtok(str, delim);
    while(ptr != NULL)
    {
        arr[i] = ptr;
        ptr = strtok(NULL, delim);
        ++i;
    }

    arr[i] = 0;

    if (fork() == 0) {
        execve(arr[0], arr, 0);
        }
    }
    return 0;   
} 
