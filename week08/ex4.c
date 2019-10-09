#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#define MY_10M (1024 * 1024 * 10)

int main() {
    for (int i = 0; i < 10; ++i) {
        struct rusage u;
        int *ptr = malloc(MY_10M);
        memset(ptr, 0, MY_10M);
        getrusage(RUSAGE_SELF, &u);
        printf(" %ld \n", u.ru_maxrss);
        sleep(1);
    }
    return 0;
} 
