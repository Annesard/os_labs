#include <stdio.h>
#include <sys/types.h>


int main(){
    char input[20];
    for(;;){
        scanf("%s", input);
        system(input);
        if(strcmp(input, "exit") == 0){
            return 0;
        }
    }
    return 0;   
}
