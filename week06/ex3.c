#include <stdio.h>
#include<signal.h>


void handler(int signal_int) {
    if (signal_int == SIGINT) {
        printf("\nctrl c is pressed\n");
    }
}

int main() {
    signal(SIGINT, handler);

    while (1) {
        sleep(1);
        printf("press ctrl c \n");
    }
    return 0;
}
