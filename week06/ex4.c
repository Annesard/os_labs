#include <stdio.h>
#include <signal.h> 


void handler(int signal_int) {
    if (signal_int == SIGUSR1) {
        printf("SIGUSR1\n");
    } else if (signal_int == SIGSTOP) {
        printf("SIGSTOP\n");
    } else if (signal_int == SIGKILL) {
        printf("SIGKILL\n");
    }
}

void check(int result, int code) {
    if (result)
        printf("Not succeed to catch signal with code %d\n", code);
    else
        printf("Succeed to catch signal with code %d\n", code);
}

int main() {
    int result;
    result = signal(SIGUSR1, handler);
    check(result, SIGUSR1);

    result = signal(SIGKILL, handler);
    check(result, SIGKILL);

    result = signal(SIGSTOP, handler);
    check(result, SIGSTOP);

    while (1) {
        sleep(1);
        printf(".\n");
    }
    return 0;
}
