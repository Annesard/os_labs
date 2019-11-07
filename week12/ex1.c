#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define NUMBER_OF_SYMBOLS 20

int main() {
    int random_data = open("/dev/random", O_RDONLY);
    char data[NUMBER_OF_SYMBOLS + 1];
    read(random_data, data, NUMBER_OF_SYMBOLS);

    for (int i = 0; i < NUMBER_OF_SYMBOLS; i++)
        data[i] = (char) 'a' + (data[i] % ('z' - 'a') + 1);

    data[NUMBER_OF_SYMBOLS] = '\0';
    printf("%s\n", data);
    return 0;
} 
