#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
    for (int i = 0; i < 10; ++i) {
        int *ptr = malloc(1024 * 1024 * 10);
        memset(ptr, 0, 1024 * 1024 * 10);
        sleep(1);
    }
    return 0;

} 
