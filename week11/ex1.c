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
    int fd = open("ex1.txt", O_RDWR);
    struct stat stat = {};
    fstat(fd, &stat);
    void *map = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    char string [] = "This is a nice day";
    strcpy(map, string);

    unsigned int size = strlen(string) * sizeof(char);

    ftruncate(fd, size);

    msync(map, size, MS_SYNC);
    
    return 0;

}
