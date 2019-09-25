#include <stdio.h>
#include <signal.h>

int main() {
    int process_id = fork();

    if (process_id > 0) {
        sleep(10);
        kill(process_id, SIGKILL);
        printf("The process is killed\n");
    } else if (!process_id) {
        while(1){
            printf("I’m alive\n");
            sleep(1);
        }
    }
    return 0;

}
