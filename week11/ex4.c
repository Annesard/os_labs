#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int one = open("ex1.txt", O_RDWR);
    int two = open("ex1.memcpy.txt", O_RDWR);

    struct stat stat1 = {};
    fstat(one, &stat1);

    struct stat two_stat = {};
    fstat(two, &two_stat);

    void *one_ad = mmap(NULL, stat1.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, one, 0);
    void *two_ad = mmap(NULL, two_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, two, 0);

    unsigned int new_size = strlen(one_ad) * sizeof(char);

    ftruncate(two, new_size);
    memcpy(two_ad, one_ad, new_size);

    msync(two, new_size, MS_SYNC);
    return 0;

}
