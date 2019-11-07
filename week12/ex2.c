#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char filename[100] = "ex2.txt";

    if (argc == 3 && !strcmp(argv[1], "-a"))
        strcpy(filename, argv[2]);

    int fd = open(filename, O_WRONLY | O_CREAT); 
    char buffer[1], c;
    while (read(STDIN_FILENO, &buffer, 1)) {
        int status = write(fd, buffer, 1);
    }

} 
