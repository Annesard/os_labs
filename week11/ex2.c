#include <stdio.h>
#include <unistd.h>

int main(){

    char str[] = "Hello";

    for(int i = 0; i < 5; i++){
        printf("%c", str[i]);
        sleep(1);
    }
   
} 
